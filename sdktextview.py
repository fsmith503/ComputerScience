"""
  Reporting progress on the command line - 
  Alternative to graphic display

  Author: Michal Young
"""


seen_duplicates = set()   # Global set to avoid re-reporting the same tile
def report_textually(tile, event):
    """Event listener: Respond to events
    by printing a message on the standard output.
    
    Arguments: 
        tile:  The sdkboard.Tile object reporting an event
        event: What happened to the tile.  "duplicate" is the 
               one we care about here. 
    """
    global seen_duplicates  # So I don't re-report the same tile
    if event == "duplicate":
        if tile in seen_duplicates:
             return
        seen_duplicates.add(tile)
        print("*** Tile at ", tile.row, tile.col, " is a duplicate of ", tile.symbol)
    #elif event == "determined":
    #    print("++ Determined value ", tile.symbol," at ", tile.row, tile.col)

def display(board): 
    """Register a listener to print reports of duplicate tiles.
    Arguments: 
        board:  An sdkboard.Board object that we wish to monitor. 
    """
    for row in board.tiles:
        for tile in row:
            tile.register(report_textually)
