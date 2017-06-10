"""
eqanalysis.py: analyze and plot earthquake data
Authors: Franklin Smith
Credits: Hannah Minns, Brian Gravelle, Roscoe Cacita
CIS 210 assignment 7, Fall 2016

As we discussed in lecture, there is a rapid increase in the amount of 
published data in the world; some say the growth is exponential. Data analytics
is the science of examining raw data with the purpose of drawing conclusions about
(inferring information from) the raw data. Data analysis is the process of inspecting,
cleaning, transforming, and modeling data with the goal of discovering useful information.
We discussed several central tendency measures of data, a couple of dispersion measures, 
and frequency tables for showing some aspects of data. The purpose of this project is for 
you to apply these measures, and to use turtle graphics for plotting the raw data, to 
assist an analyst in understanding earthquake data here in the Pacific Northwest.

The program will be executed as follows from the command or terminal window:
$ python3 eqanalysis.py file.csv plot clusters
$ python3 eqanalysis.py file.csv plot magnitudes
$ python3 eqanalysis.py file.csv plot depths
$ python3 eqanalysis.py file.csv analyze clusters
$ python3 eqanalysis.py file.csv analyze magnitudes
$ python3 eqanalysis.py file.csv analyze depths

The first three will generate dot plots on a turtle graphics window, 
while the last three will display mean, median, standard deviation, and
frequency table information on the standard output; for cluster analysis, 
the mean, median, and standard deviation information is shown for each cluster.

Examples using EqData01.csv
$ python3 eqanalysis.py EqData01.csv plot magnitudes
$ python3 eqanalysis.py EqData01.csv plot depths
$ python3 eqanalysis.py EqData01.csv plot clusters
$ python3 eqanalysis.py EqData01.csv analyze magnitudes
$ python3 eqanalysis.py EqData01.csv analyze depths
$ python3 eqanalysis.py EqData01.csv analyze clusters
"""

# a set of modules that we need to use in the code below
import math
import random
import argparse
from data import *
import turtle
import sys


# constants for the k-means clustering algorithm
# if you change these in your experimentation, you will need to look at 
# all parts of the code that refer to them, as there is some dependence
# on them (such as number of colors used in plotting clusters)
#
# IF YOU DO CHANGE THEM, YOU MUST PUT THEM BACK TO THE ORIGINAL VALUES
# BEFORE SUBMITTING YOUR WORK!!!!!
NO_OF_CLUSTERS = 6
NO_OF_ITERATIONS = 7

def euclid_distance(point1, point2):
    """
    computes the euclidean distance between two points
    Args:
        point1: list of floats, index 0 is longitude, index 1 is latitude
        point2: list of floats, index 0 is longitude, index 1 is latitude
    Returns:
        float, sqrt((x1-x2)**2 + (y1-y2)**2)
    """

    total = 0
    for index in range(2):
        diff = point1[index] - point2[index]
        total += diff * diff

    return math.sqrt(total)

def create_centroids(k, datadict):
    """
    randomly selects 'k' points from 'datadict' as the starting
        centroids for the k-means clustering algorithm
    Args:
        k: int, number of clusters desired
        datadict: list of lists, each contained list represents an EQ event
    Returns:
        list of lists, each contained list is an event to act as the centroid
    """
    centroids = []
    count = 0
    centroid_keys = []

    while count < k:
        rkey = random.randint(1, len(datadict))
        if rkey not in centroid_keys:
            centroids.append(datadict[rkey])
            centroid_keys.append(rkey)
            count += 1

    return centroids

def create_clusters(k, centroids, datadict, iterations):
    """
    k-means clustering algorithm - implementation taken from page 249 of
        ranum and miller text, with some modifications
    Args:
        k: integer, number of clusters
        centroids: list of events, each event is the centroid of its cluster
        datadict: dictionary of all EQ events
        iterations: int, number of clustering iterations to perform
    Returns:
        list of lists: each contained list is the set of indices into 'datadict'
           for events that belong to that cluster
    """
    for iteration in range(iterations):
        #print("****Iteration", iteration, "****")
        clusters = []
        for i in range(k):
            clusters.append([])

        for key in datadict:
            distances = []
            for cl_index in range(k):
                dist = euclid_distance(datadict[key], centroids[cl_index])
                distances.append(dist)
            min_dist = min(distances)
            index = distances.index(min_dist)
            clusters[index].append(key)

        dimensions = 2
        for cl_index in range(k):
            sums = [0]*dimensions
            for key in clusters[cl_index]:
                data_points = datadict[key]
                for ind in range(2):
                    sums[ind] = sums[ind] + data_points[ind]
            for ind in range(len(sums)):
                cl_len = len(clusters[cl_index])
                if cl_len != 0:
                    sums[ind] /= cl_len
            centroids[cl_index] = sums

        #for c in clusters:
            #print("CLUSTER")
            #for key in c:
                #print(datadict[key], end=" ")
            #print()

    return clusters

def read_file(filename):
    """
    read the EQ events from the csv file, 'filename'; any lines starting with
        # are skipped; the longitude, latitude, magnitude, and depth (in miles)
        is extracted from each event record, and stored as a list against its
        record number in a dictionary
    Args:
        filename: string, name of a CSV file containing the EQ data
    Returns:
        dictionary, indexed by integers, each value is a list of floats
            representing an EQ event
    """
    dict = {}
    key = 0

    fd = open(filename, "r")
    for line in fd:
        if line[0] == '#':
            continue		# causes the loop to grab another line
        key += 1
        values = line.rstrip('\n').split(',')
        lat = float(values[7])
        lon = float(values[8])
        mag = float(values[1])
        dep = float(values[10])
        dict[key] = [lon, lat, mag, dep]
    fd.close()
    return dict

# global data for map - if we had ;earmed about classes yet, this would have
# been hidden in a class instance, and the plot_*() functions would be methods
# on that class instance.  for now, these are global variables, and the
# plot functions access them

eq_turtle = None
eq_win = None
# these are the longitudes and latitudes for the Pacific NorthWest map that
# I have provided to you; do not change them!
left_lon = -128.608689
right_lon = -114.084764
top_lat = 51.248522
bot_lat = 38.584004
lon_diff = 0
lat_diff = 0
size_x = 0
size_y = 0
left_x = 0
bot_y = 0

def prepare_turtle():
    """
    Prepares the turtle and the window to plot magnitudes, depths, or clusters
    Args:
        None
    Outputs:
        creates turtle, sets window size, defines remainder of global
        data needed for plot_routines
    """
    global eq_turtle, eq_win
    global left_lon, right_lon, top_lat, bot_lat
    global lon_diff, lat_diff
    global size_x, size_y, left_x, bot_y

    eq_turtle = turtle.Turtle()
    eq_turtle.speed(10)
    eq_win = turtle.Screen()
    eq_win.screensize(655,808)	# number of pixels in the map I have provided
    lon_diff = right_lon - left_lon
    lat_diff = top_lat - bot_lat
    size_x = eq_win.screensize()[0]
    left_x = -size_x/2
    size_y = eq_win.screensize()[1]
    bot_y = -size_y/2
    eq_win.bgpic("PacificNW.gif")	# the map I have provided
    eq_turtle.hideturtle()
    eq_turtle.up()

def xy_calculate(lon, lat):
    """
    compute (x, y) given lon[gitude] and lat[itude]
    Args:
        lon: float, longitude value for point on map
        lat: float, latitude value for point on map
    Returns:
        tuple, corresponding pixel x and y values for use in turtle methods
    """
    global left_lon, right_lon, top_lat, bot_lat
    global lon_diff, lat_diff
    global size_x, size_y, left_x, bot_y

    x = left_x + (lon - left_lon) / lon_diff * size_x
    y = bot_y + (lat - bot_lat) / lat_diff * size_y
    return (x, y)

def plot_clusters(eq_clusters, eq_dict):
    """
    plot the clusters - use turtle.dot() at the appropriate location on the
        map for each event; use a different color for the events in each
        cluster - e.g. for cluster 0, use 'red', for 1, use 'violet' ...
    Args:
        eq_clusters: list of lists, each contained list has the indices for
                     events in that cluster in eq_dict
        eq_dict: list of lists, each contained list represents an EQ event
    Outputs:
        plots all events in a particular cluster as dots on the map
    """

    global eq_turtle
    turtle.colormode(255) 
    for lst in eq_clusters:
        r = random.randint(0, 255)
        g = random.randint(0, 255)
        b = random.randint(0, 255)
        turtle.color(r, g, b)
        for i in lst:
            x_cord = eq_dict[i][0]
            y_cord = eq_dict[i][1]
            cords = xy_calculate(x_cord,y_cord)
            turtle.up()
            turtle.goto(cords)
            turtle.down()
            turtle.begin_fill()
            turtle.speed(1000)
            turtle.dot()
            turtle.end_fill()
            


    

def bin_value(value, bounds):
    """
    'bounds' defines a set of bins; this function returns the index of the
        first bin that contains 'value'
    Args:
        value: float, value to place in bin
        bounds: list of floats, bounds[i] is the top value of the bin
                code assumes that bounds is an increasing set of values
    Returns:
        integer, index of smallest value of bounds[] that is >= value
            if value > bounds[-1], returns len(bounds)
    """
    for i in range(len(bounds)):
        if value <= bounds[i]:
            return i
    return len(bounds)

def plot_magnitudes(eq_dict):
    """
    plot the magnitudes - use turtle.dot() at the appropriate location on the
        map for each event; use a different color and size for magnitude
        equivalence classes - e.g. if magnitude of event is <=1, use small dot
        that is 'violet', if between 1 and 2, use slightly larger dot that is
        'blue', ..., if between 9-10, use very large dot that is 'red'
    Args:
        eq_dict: list of lists, each contained list represents an EQ event
    Outputs:
        plots magnitude of all events as dots on the map
    """

    global eq_turtle
    turtle.colormode(255)

    dot_size = [5,10,15,20,25,30,35,40,45,50]
    color_mags = [(238,130,238),(0,0,255),(127,255,0),(34,139,34),(50,205,50),(255,255,0),(255,255,102),(255,165,0),(255,140,0),(255,0,0)]
    bounds1 = [1.0,2.0,3.0,4.0,5.0,6.0,7.0,8.0,9.0] 


    for val in eq_dict:
        x_cord = eq_dict[val][0]
        y_cord = eq_dict[val][1]
        cords = xy_calculate(x_cord,y_cord)
        bin_mag_index = bin_value(eq_dict[val][2],bounds1)
        turtle.speed(1000)
        turtle.up()
        turtle.goto(cords)
        turtle.color(color_mags[bin_mag_index])
        turtle.begin_fill()
        turtle.speed(1000)
        turtle.dot(dot_size[bin_mag_index]) 
        turtle.end_fill()

        

   



    

def plot_depths(eq_dict):
    """
    plot the depths - use turtle.dot() at the appropriate location on the
        map for each event; use a different color and size for depth
        equivalence classes - e.g. if depth of event is <=1 mile, use a very
        large dot that is 'red', if between 1 and 5, use slightly smaller dot
        that is 'orange', ..., if between 50-100, use a small dot that is
        'violet'

    Args:
        eq_dict: list of lists, each contained list represents an EQ event
    Outputs:
        plots depth of all events as dots on the map
    """     
    dot_size = [15,13,11,9,8,7,6,5,4,3]
    color_depths = [(255,0,0),(255,140,0),(255,165,0),(255,255,0),(50,205,50),(34,139,34),(127,255,0),(0,0,255),(238,130,238)] 
    bounds2 = [1.0,5.0,10,15,20,25,30,35,50.0,100.0] 
    global eq_turtle
    turtle.colormode(255)
    for lst in eq_dict:
        x_cord = eq_dict[lst][0]
        y_cord = eq_dict[lst][1]
        cords = xy_calculate(x_cord,y_cord)
        bin_depth_index = bin_value(eq_dict[lst][3],bounds2)
        turtle.up()
        turtle.goto(cords)
        turtle.color(color_depths[bin_depth_index])
        turtle.begin_fill()
        turtle.speed(1000)
        turtle.dot(dot_size[bin_depth_index])
        turtle.end_fill()
    

def analyze_depths(eq_dict):
    """
    Perform statistical analysis on the depth information in the dictionary
    Args:
        eq_dict: list of lists, each contained list represents an EQ event
    Outputs:
        mean, median, and standard deviation of depth data
        frequency table for the depth data
    """
    depths_list = []
    for val in eq_dict:
        depths_list.append(eq_dict[val][3])
    q = (data_mean(depths_list))
    r = (data_median(depths_list))

    depth_deviation_sum = 0 
    for i in depths_list:
        temp_sum = 0
        a = i - data_mean(depths_list)
        b = a ** 2
        depth_deviation_sum += b
        c = depth_deviation_sum / (len(depths_list) - 1)
        d = math.sqrt(c)
    print("Analysis of Depth Data \n Mean depth = {:.2} miles \n Median depth = {:.2} miles \n Standard Deviation = {:.3} miles".format(q,r,d))
    depth_freq_list = []
    for val in eq_dict:
        depth_freq_list.append(eq_dict[val][3])
    data_freq_table(depth_freq_list)
    

def analyze_magnitudes(eq_dict):
    """
    Perform statistical analysis on the magnitude information in the dictionary
    Args:
        eq_dict: list of lists, each contained list represents an EQ event
    Outputs:
        mean, median, and standard deviation of magnitude data
        frequency table for the magnitude data
    """
    mags_list = []
    for val in eq_dict:
        mags_list.append(eq_dict[val][2])
        e = (data_mean(mags_list))
        f = (data_median(mags_list))

    mag_deviation_sum = 0
    for i in mags_list:
        mag1 = i - (data_mean(mags_list))
        mag2 = mag1 ** 2
        mag_deviation_sum += mag2
        mag3 = mag_deviation_sum / (len(mags_list) - 1)
        mag4 = math.sqrt(mag3)
    print("Analysis of Magnitude Data \n Mean Magnitude = {:.2} \n Median Magnitude {:.2} \n Standard Deviation = {:.2f} ".format(e,f,mag4))
    mag_freq_list = []
    for val in eq_dict:
        mag_freq_list.append(eq_dict[val][2])
    data_freq_table(mag_freq_list)



def analyze_clusters(eq_clusters, eq_dict):
    """
    Perform statistical analysis on the depth and magnitude information
        for each cluster
    Args:
        eq_clusters: list of lists, each contained list has the indices into
                     eq_dict for events in that cluster
        eq_dict: list of lists, each contained list represents an EQ event
    Outputs:
        for each cluster:
            mean, median, and standard deviation of magnitude data
            mean, median, and standard deviation of depth data
    """
    
    cluster_count = 0
    for lts in eq_clusters:
        print("Analysis of cluster {}".format(cluster_count))
        cluster_count += 1
        magnitude_cluster_list = []
        depth_cluster_list = []
        for i in lts:
            magnitude_cluster_list.append(eq_dict[i][2])
            depth_cluster_list.append(eq_dict[i][3])

        w = (data_mean(magnitude_cluster_list))
        x = (data_median(magnitude_cluster_list))
        y = (data_mean(depth_cluster_list))
        z = (data_median(depth_cluster_list))
        

        
            
        cluster_deviation_sum = 0
        clust1 = i - (data_mean(magnitude_cluster_list))
        clust2 = clust1 ** 2
        cluster_deviation_sum += clust2
        clust3 = cluster_deviation_sum / (len(magnitude_cluster_list) - 1)
        clust4 = math.sqrt(clust3)
        
        depth_deviation_sum = 0
        dep1 = i - (data_mean(depth_cluster_list))
        dep2 = dep1 ** 2
        depth_deviation_sum += dep2
        dep3 = depth_deviation_sum / (len(depth_cluster_list) - 1)
        dep4 = math.sqrt(dep3)
        
        
        print("Analysis of Magnitude Data \n Mean Magnitude = {:.2} \n Median Magnitude {:.2} \n Standard Deviation = {:.3} ".format(w,x,clust4))
        print("Analysis of Depth Data \n Mean Depth = {:.2} \n Median Depth {:.2} \n Standard Deviation = {:.3} miles".format(y,z,dep4))
        print()




    


    

def main():
    """
    Interaction if run from the command line.
    Usage:  python3 eqanalysis.py eq_data_file.csv command
    """
    parser = argparse.ArgumentParser(description="Earthquake event file stats")
    parser.add_argument('eq_file', type=str,
                 help='A csv file containing earthquake events, one per line.')
    parser.add_argument('command', type=str,
                 help='One of the following strings: plot analyze')
    parser.add_argument('what', type=str,
                 help='One of the following strings: clusters depths magnitudes')
    args = parser.parse_args()
    eq_file = args.eq_file
    cmd = args.command
    what = args.what
    if cmd != 'plot' and cmd != 'analyze':
        print('Illegal command: {}; must be "plot" or "analyze"'.format(cmd))
        sys.exit(1)
    if what != 'clusters' and what != 'magnitudes' and what != 'depths':
        print('Can only process clusters, magnitudes, or depths')
        sys.exit(1)
    eq_dict = read_file(eq_file)
    prepare_turtle()
    if what == 'clusters':
        eq_centroids = create_centroids(NO_OF_CLUSTERS, eq_dict)
        eq_clusters = create_clusters(NO_OF_CLUSTERS, eq_centroids, eq_dict, NO_OF_ITERATIONS)
    if cmd == 'plot':
        if what == 'clusters':
            plot_clusters(eq_clusters, eq_dict)
        elif what == 'magnitudes':
            plot_magnitudes(eq_dict)
        elif what == 'depths':
            plot_depths(eq_dict)
        print("ALL EVENTS HAVE BEEN PLOTTED")
        eq_win.exitonclick()
    else:
        if what == 'clusters':
            analyze_clusters(eq_clusters, eq_dict)
        elif what == 'magnitudes':
            analyze_magnitudes(eq_dict)
        elif what == 'depths':
            analyze_depths(eq_dict)

if __name__ == "__main__":
    main()
