import turtle

def data_mean(my_list):
    """
    computes the mean value of elements of a list
    Args:
        my_list: list of floats (MUST BE NON-EMPTY)
    Returns:
        float, mean value of elements in my_list
    """
    return sum(my_list) / len(my_list)

def data_median(my_list):
    """
    computes the median value of the elements of a list
    Args:
        my_list: list of floats (MUST BE NON-EMPTY)
    Returns:
        float, median value of elements in my_list
    """
    copy = sorted(my_list)
    if len(copy)%2 == 0:
        rndx = len(copy) // 2
        lndx = rndx - 1
        median = (copy[rndx] + copy[lndx]) / 2.0
    else:
        median = copy[len(copy)//2]
    return median

def data_mode(my_list):
    """
    computes the mode value[s] of the elements of a list
    Args:
        my_list: list of floats (MUST BE NON-EMPTY)
    Returns:
        list of mode value[s] of elements in my_list
    """
    dict_of_counts = {}

    for item in my_list:
        if item in dict_of_counts:
            dict_of_counts[item] += 1
        else:
            dict_of_counts[item] = 1

    count_list = dict_of_counts.values()
    max_count = max(count_list)

    mode = []
    for item in dict_of_counts:
        if dict_of_counts[item] == max_count:
            mode.append(item)

    return mode

def data_freq_table(my_list):
    """
    prints frequency table of elements in my_list
    Args:
        my_list: list of floats (MUST BE NON-EMPTY)
    Outputs:
        frequency table printed on the standard output
    """
    count = {}

    for item in my_list:
        if item in count:
            count[item] += 1
        else:
            count[item] = 1

    item_list = sorted(list(count.keys()))

    print("ITEM    FREQUENCY")

    for item in item_list:
        print('{:5}  {:5}'.format(item, count[item]))

def data_freq_chart(my_list):
    """
    plots frequency bar chart of elements in my_list using turtle graphics
    Args:
        my_list: list of floats (MUST BE NON-EMPTY)
    Outputs:
        frequence bar chart of elements plotted using turtle graphics
        waits for user to click on window to exit
    """
    count = {}

    for item in my_list:
        if item in count:
            count[item] += 1
        else:
            count[item] = 1

    item_list = list(count.keys())
    min_item = 0
    max_item = len(item_list) - 1

    count_list = count.values()
    max_count = max(count_list)

    wn = turtle.Screen()
    chart_turtle = turtle.Turtle()
    wn.setworldcoordinates(-1, -1, max_item+1, max_count+1)
    chart_turtle.hideturtle()

    chart_turtle.up()
    chart_turtle.goto(0,0)
    chart_turtle.down()
    chart_turtle.goto(max_item,0)
    chart_turtle.up()

    chart_turtle.goto(-1,0)
    chart_turtle.write("0", font=("Helvetica",16,"bold"))
    chart_turtle.goto(-1, max_count)
    chart_turtle.write(str(max_count), font=("Helvetica", 16, "bold"))

    for index in range(len(item_list)):
        chart_turtle.goto(index, -1)
        chart_turtle.write(str(item_list[index]), font=("Helvetica",16,"bold"))
        chart_turtle.goto(index, 0)
        chart_turtle.down()
        chart_turtle.goto(index, count[item_list[index]])
        chart_turtle.up()

    wn.exitonclick()

def data_m1(my_list):
    """
    computes the 1st moment of elements of a list (identical to mean)
    note that this implementation exhibits numerical stability
    Args:
        my_list: list of floats (MUST BE NON-EMPTY)
    Returns:
        float, 1st moment (mean) of elements in my_list
    """
    n = 0
    m1 = 0.0

    for item in my_list:
        n += 1
        delta = item - m1
        m1 += delta / n

    return m1

def data_m2(my_list):
    """
    computes the 2nd moment of elements of a list
    note that this implementation exhibits numerical stability
    Args:
        my_list: list of floats (MUST BE NON-EMPTY)
    Returns:
        float, 2nd moment of elements in my_list
    """
    n = 0
    m2 = 0.0

    for item in my_list:
        n += 1
        delta = item * item - m2
        m2 += delta / n

    return m2

def data_mean_variance(my_list):
    """
    computes the mean and variance of the elements of my_list
    note that this implementation exhibits numerical stability
    Args:
        my_list: list of floats (MUST BE NON-EMPTY)
    Returns:
        tuple, 1st element is the mean, 2nd element is the variance
    """
    n = 0
    m1 = 0.0
    m2 = 0.0

    for item in my_list:
        n += 1
        d1 = item - m1
        d2 = item * item - m2
        m1 += d1 / n
        m2 += d2 / n

    if n < 2:
        var = float('nan')  # not defined
    else:
        var = n / (n-1) * (m2 - m1 * m1)
    return (m1, var)

def data_range(my_list):
    """
    computes the range of elements of a list (max - min)
    Args:
        my_list: list of floats (MUST BE NON-EMPTY)
    Returns:
        float, range of elements in my_list
    """
    if len(my_list) == 0:
        return 0
    max_so_far = my_list[0]
    min_so_far = my_list[0]
    for item in my_list[1:]:
        if item > max_so_far:
            max_so_far = item
        if item < min_so_far:
            min_so_far = item
    return max_so_far - min_so_far

