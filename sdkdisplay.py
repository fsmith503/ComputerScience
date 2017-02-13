"""
Sudoku board display. 
Author: M Young, Nov 10 2012 for CIS 210

Designed for a simple model/view/controller architecture, 
in which the board display knows about the sudoku board, 
and not vice versa.  Communication from the sudoku board
to the board display is by event notifications through 
registered listeners. 
"""

import grid
import sdkboard

def handle_events(tile, event): 
    """Handle an event announced by a tile.
    Arguments: 
        tile: The sdkboard.Tile object announcing the event
        event: String describing the event.  The only currently known 
             event type is "duplicate", for when a tile has been 
             discovered to be a duplicate of another tile in the same
             row, column, or square.
    """
    if event == "duplicate":
        grid.fill_cell(tile.row, tile.col, color=grid.red)
        grid.label_cell(tile.row, tile.col, tile.symbol, color=grid.white)
    elif event == "determined":
        grid.fill_cell(tile.row, tile.col, color=grid.green)
        grid.label_cell(tile.row, tile.col, tile.symbol, color=grid.white)
    elif event == "constrained":
        grid.fill_cell(tile.row,tile.col, color=grid.green)
        grid.fill_cell(tile.row,tile.col, color=grid.white)
        candidates = [[ '1', '2', '3'], ['4', '5', '6'], ['7', '8', '9']]
        for subrow in range(3):
            for subcol in range(3):
                candidate = candidates[subrow][subcol]
                if candidate in tile.possible:
                    grid.sub_label_cell(tile.row, tile.col,
                                subrow, subcol, candidate)
                               
    

def display(board):
    """Create a display of a Sudoku board.
    Arguments: 
        board: an sdkboard.Board object
        
    Note an event handler (handle_events) will be attached 
    as a listener to each tile in the board. 
    """
    grid.make(9,9,500,500)
    grid.sub_grid_dim(3,3)
    for row in range(9):
        for col in range(9):
            # Direct access to tile of sdkboard is more Pythonic
            # than an access method. 
            # In Java and some other languages we'd need a getter. 
            tile = board.tiles[row][col]
            tile.register(handle_events)
            grid.fill_cell(row, col, grid.white)
            if (tile.symbol != sdkboard.OPEN):
                grid.label_cell(row, col, tile.symbol)
    
