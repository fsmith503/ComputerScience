"""
Graph search to find shortest path between two cities. 
Authors: Franklin Smith
Credits: GTF Roscoe

A road map is represented as a directed graph.
Edges represent road segments and are labeled with distances.
Nodes represent cities. 
We use depth first search to find the shortest distance
between two cities. During the depth-first search from
start to end, we compute a 'shortest known distance to here from start'
attribute for each node.  After completion of depth first search,
destination city should be labeled with the shortest distance from
the start city.  

The input and output in the command or terminal window will look like this:
> python3 routes.py a g sample-map.txt
Distance from a to g is 19.0

In case of a misspelled city, your program will report that it does not appear on the map:

> python3 routes.py a x sample-map.txt
Destination  x  is not on the map

It can also cope with cities that are present on the map, but with no route between:

> python3 routes.py a x sample-map-noreach.txt
You can't get from a to x

"""



import argparse 


def read_distances(map_file):
    """Read a distance table from a named file into a dict
       mapping sources to lists of (destination, distance) pairs. 
    Args:
       map_file: A readable text file in which each line either 
           begins with #  (indicating a comment line) or is of the form
           from location, to location, distance or time, for example
              Minis Tirith,Cair Andros,5
           indicating one can travel from Minis Tirith to Cair Andros in 5.0 hours.
    Returns:
        Dict in which each entry d[from] is a list [(to, cost), (to, cost), ... ]
        where from is a location name, to is a location name, and cost is time
        or distance
        as a floating point number.  If x,y,z appears in the input file, then 
        we should have both d[x] contains (y,z) and d[y] contains (x,z), i.e., 
        we assume that roads are bi-directional. 
    """
    connections = dict() 
    for line in map_file:
        line = line.strip()  
        if line.startswith("#") or line=="" :
            # print("Skipping comment: ", line)
            continue  ## Discard and go on to next
        # print("Processing line: ", line)
        fields = line.split(",")
        place_from = fields[0]
        place_to = fields[1]
        cost = float(fields[2])
        if not (place_from in connections): 
            connections[place_from] = [ ]
        connections[place_from].append( (place_to, cost) )
        if not (place_to in connections): 
            connections[place_to] = [ ]
        connections[place_to].append( (place_from, cost) ) 
    
    return connections


    
    
def show_roads(roads):
    """Print roads from dict (for debugging).
       Args: 
         roads:  A dict in which
                roads[Chicago] == [("Atlanta", 30.0), ("Austin", 25.0)]
              means that there is a 30.0 mile road from Chicago to Atlanta and a 
              25.0 mile road from Chicago to Austin.
       Returns: 
            nothing
       Effects: 
            Prints a textual representation of the road connections    
    """
    for from_place in roads:
        print(from_place + ":")
        for hop in roads[from_place]:
            to_place, dist = hop
            print("\t->" + to_place + " (" + str(dist) + ")")
            

def dfs(place, dist_so_far, roads, distances):
    """Depth-first search, which may continue from from_place if dist_so_far    
        is the shortest distance at which it has yet been reached.  
       Args: 
          place: Currently searching from here
          dist_so_far:  Distance at which from_place has been reached 
              this time (which may not be the shortest path to from_place)
          roads:  dict mapping places to lists of hops of the form (place, hop-distance)
          distances: dict mapping places to the shortest distance 
          at which they 
               have been reached so far (up to this time). 
        Effects:
            modifys the distances dictionary
        Raises:
            None    
    """
   
    
    if place not in distances.keys():
        distances[place] = dist_so_far
        for edge in roads[place]:
            (city,dist) = edge
            dfs(city,dist_so_far + dist,roads,distances)
    else:
        if dist_so_far < distances[place]:
            distances[place] = dist_so_far 
            for edge in roads[place]:
                (city,dist) = edge
                dfs(city,dist_so_far + dist, roads, distances)            
    
    

            

    
def main():
    """
    Main program gets city pair and map file name,
    reports distance or reports lack of connectivity.
    """
    parser = argparse.ArgumentParser(
        description="Find shortest route in road network")
    parser.add_argument('from_place', 
                help = "Starting place (quoted if it contains blanks)")
    parser.add_argument('to_place', 
                help = "Destination place (quoted if it contains blanks)")
    parser.add_argument('map_file', type=argparse.FileType('r'),
                help = "Name of file containing road connections and distances")
    args = parser.parse_args()
    start_place  = args.from_place
    destination = args.to_place
    roads = read_distances(args.map_file)

    if not start_place in roads: 
        print("Start place ", start_place, " is not on the map")
        exit(1)
    if not destination in roads: 
        print("Destination ", destination, " is not on the map")
        exit(1)

    distances = { }
    

    dfs(start_place, 0.0, roads, distances )

    if destination in distances :
        print("Distance from {} to {} is {}".format(
            start_place,destination, distances[destination]))
    else:
        print("You can't get from {} to {}".format(start_place, destination))

if __name__ == "__main__":
    main()
        
