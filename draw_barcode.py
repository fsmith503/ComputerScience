"""
draw_barcode.py: Draw barcode representing a ZIP code using Turtle graphics
Authors: Franklin Smith
Credits: GTF Alex

CIS 210 assignment 3, part 2, Fall 2016.
"""
import argparse	# Used in main program to obtain 5-digit ZIP code from command
                # line
import time	# Used in main program to pause program before exit
import turtle	# Used in your function to print the bar code

## Constants used by this program
SLEEP_TIME = 30	# number of seconds to sleep after drawing the barcode
ENCODINGS = [[1, 1, 0, 0, 0],	# encoding for '0'
             [0, 0, 0, 1, 1],	# encoding for '1'
             [0, 0, 1, 0, 1],   # encoding for '2'
             [0, 0, 1, 1, 0],	# encoding for '3'
             [0, 1, 0, 0, 1],	# encoding for '4'
             [0, 1, 0, 1, 0],	# encoding for '5'
             [0, 1, 1, 0, 0],	# encoding for '6'
             [1, 0, 0, 0, 1],	# encoding for '7'
             [1, 0, 0, 1, 0],	# encoding for '8'
             [1, 0, 1, 0, 0]	# encoding for '9'
            ]
SINGLE_LENGTH = 25	# length of a short bar, long bar is twice as long

def compute_check_digit(digits):
    """
    Compute the check digit for use in ZIP barcodes
    args:
        digits: list of 5 integers that make up zip code
    returns:
        check digit as an integer
    """
    a = digits
    b = str(a)
    digits = []

    for digit in b:
        digits.append (int(digit))

    

    sum = 0
    for i in range(len(digits)):
        sum = sum + digits[i]
    check_digit = 10 - (sum % 10)
    if (check_digit == 10):
        check_digit = 0
    return check_digit

def draw_bar(my_turtle, digit):
    """
    Draws a barcode using the turtle function
    args:
        my_turtle: Initiates the turtle function
        Digit: Is either 0 or 1. If it is 0 then the bar
        is a single length. If it is 1 then it is twice
        the size of the single length
    """
    my_turtle.left(90)
    if digit == 0:
        length = SINGLE_LENGTH
    else:
        length = 2 * SINGLE_LENGTH
    my_turtle.forward(length)
    my_turtle.up()
    my_turtle.backward(length)
    my_turtle.right(90)
    my_turtle.forward(10)
    my_turtle.down()


def draw_zip(my_turtle, zip):
    """
    Takes each digit in the zip code and
    turns it into a string. Then iterates 
    though the digits in the string and calls the
    draw_bar function wich draws the corresponding
    bar with the turtle function.
    args: 
        My_turtle: Initiates the turtle funciton
        Zip: draw the barcode corresponding to the zip
    """
    p = compute_check_digit(zip)
    a = [int(k) for k in str(zip)] ## for each number for the zip code
    a.append(p)
    draw_bar(my_turtle, 1)

    
    for i in a:
        if i == 0:
            digit = "11000"
        if i == 1:
            digit = "00011"
        if i == 2:
            digit = "00101"
        if i == 3:
            digit = "00110"
        if i == 4:
            digit = "01001"
        if i == 5:
            digit = "01010"
        if i == 6:
            digit = "01100"
        if i == 7:
            digit = "10001"
        if i == 8:
            digit = "10010"
        if i == 9:
            digit = "10100"  

        for i in digit:
            if i == "0":
                draw_bar(my_turtle, 0)
            if i == "1":
                draw_bar(my_turtle, 1)

    draw_bar(my_turtle, 1)

    
def main():
    parser = argparse.ArgumentParser()
    parser.add_argument("ZIP", type=int)
    args = parser.parse_args()
    zip = args.ZIP
    if zip <= 0 or zip > 99999:
        print("zip must be > 0 and < 100000; you provided", zip)
    else:
        my_turtle = turtle.Turtle()
        draw_zip(my_turtle, zip)
        time.sleep(SLEEP_TIME)

if __name__ == "__main__":
    main()
