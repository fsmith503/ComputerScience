"""
Sudoku solver.
Author: Michal Young, 10-15 November 2012 for CIS 210
Author: Joe Sventek, 11-13 November 2015, minor modifications

terminal call
$ python3 sudoku.py board1.txt


Overall application control (including instantiation of 
graphical and/or textual views of progress).
"""
#Notes from class, building a sudoku solver, no mathematics, just pattern matching
# implementing two of those tactics, out of 30 or more, there will be puzzles that we cant complete all the way
# check for invalid entry, with illegal numbers
# main challenges, Data structure: tiles ar eshared by mulitple lists,
# algorithm: logic bbased on sets
# event listeners: functions as objects
# if you have the number you can check if its in a row, column, or 3 by 3 square
# function you have to write is board that checks input
# sets of symbols found in a row, start with empty set add symbols as theyre found, or start with a set and remove them as theyre used
# 81 tiles that make up the board
# factor out the code, 9 slists that correspond to the 9 rows
# 9 lists to correspond to the 9 columns

import sdkboard    # The Sudoku board  (model component)
import sdkdisplay  # Display of Sudoku board (view component)
import sdktactics  # Tactics for checking and solving sudoku
import sdktextview # Alternative display: spew text
import argparse    # Interpret command line


###
# Command line processing - the Pythonic way
###

parser = argparse.ArgumentParser(description="""
   Check a Sudoku board (complete or incomplete) to
   report whether it is correct or whether, on the
   contrary, there are duplicate digits in a row,
   a column, or a subsquare.  If there are no 
   errors, proceed to fill in as many open tiles
   as possible using the naked single and hidden 
   single tactics. """)

parser.add_argument('board', metavar="filename",
                    type=argparse.FileType('r'), 
                    help="file containing board description")
                    
parser.add_argument('--display', action="store_true", 
                    help="Display Sudoku board graphically")
                    
args = parser.parse_args()

###
# Main program logic
###

f = args.board
board = sdkboard.Board.from_file(f)

if args.display: 
    sdkdisplay.display(board)
else:
    sdktextview.display(board)
  
sdktactics.prepare(board)
if sdktactics.good_board():
    sdktactics.solve()
    print(board)
else:
    print("Sudoku FAIL")

if args.display: 
    input("Press enter to close down")



    
