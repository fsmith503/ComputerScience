"""
Sudoku board. 

Author: Michal Young, November 2012 for CIS 210

"""

# Global constants
DIGITS = frozenset('123456789') 
OPEN = '.'
SYMBOLS = frozenset('.123456789')

class Tile:

    """One tile on a Sudoku board.
    Public data atributes: 
        row: integer 0..8  (position on board, read only after creating)
        col: integer 0..8  (position on board, read only after creating)
        symbol: String '1','2', .. '9' or '.'  (read-write in solver)
             A digit '1' .. '9' is a choice that has been made;
             The OPEN symbol is a choice that has not yet been made. 
        possible: set of possible symbols that could be here (read-write in solver)

    It is permitted to directly access tile.row, tile.col, tile.symbol, and tile.possible
    (that is what calling them "public" means).  However, they should not be changed
    directly.  Change their values only by calling methods in this class. 

    Invariant:
        The "possible" set always includes the potential correct symbol in
        this tile, provided the board is solvable. Thus, if there is only
        one symbol in "possible", that must be the correct symbol for the tile.

    Events:
        listeners are functions called to announce certain events in a user
        interface (whether graphical or textual).  Currently supported event
        types are "duplicate" (this tile is a duplicate of another in a row,
        column, or block);  "determined"  (this tile was OPEN, but we just
        figured out what digit it must be); and "constrained"  (we just trimmed
        down the "possible" set of symbols, making progress toward a solution). 

     """
        
    def __init__(self, row, col, sym):
        self.symbol = sym
        self.row = row
        self.col = col
        self.listeners = [ ] 
        if sym == OPEN : 
            self.possible = set(DIGITS)
        else: 
            self.possible = { self.symbol }
            
    def __str__(self):
        return self.symbol
        
    def determine(self, symbol):
        """Set this previously open tile to a fixed value.
        Arguments:
            symbol: The symbol that we will set this tile to.
        """
        assert(self.symbol == OPEN)
        assert(symbol in self.possible)
        self.symbol = symbol
        self.possible = { self.symbol }
        self.announce("determined")

    def remove_choices(self, choices):
        """Remove any elements of choices from the possible
        set of this tile. 
        Args:
          Choices:  A set of symbols that can't appear here.
        Returns:
          True if this constraint reduces the number of
          possibilities for this tile (indicating progress in
          solving the Sudoku puzzle).
        """
        old_size = len(self.possible)
        limited = self.possible - choices
        new_size = len(limited)
        assert(new_size > 0)
        # Three possibilities:
        #    We have cut the number of possibilities to 1
        #    We have cut the possibilities, but it's still more than one
        #    We haven't cut the number at all
        if new_size == 1:
            self.symbol = limited.pop()
            self.possible = { self.symbol }
            self.announce("determined")
            return True
        elif new_size != old_size:
            self.possible = limited
            self.announce("constrained")
            return True
        else:
            return False        
              
    def announce(self, event):
        """Announce an event (string) to each registered listener.
        Arguments: 
            event:  A string describing this event. Currently known
            events are "duplicate", "determined", and "constrained".
        """
        for func in self.listeners:
            func(self, event)
            
    def register(self, listener): 
        """Register a listener callback function. 
        Arguments: 
            listener(tile,event): Function that reacts to a 
                an event (identified by a string) on this tile.
        """
        self.listeners.append(listener)

    
    
class Board:

    """9 x 9 grid of Sudoku tiles.  The same tiles are organized 
    in three collections. 
    
    Public attributes: 
        tiles:  a list of lists of Tile objects, organized by row.
                board.tiles[r][c] is the tle in row r, column c.
    """
    
    def __init__( self, symbols ):
        """Constructor from a sequence of 9 sequences of 9 symbols."""
        rowcount = 0
        self.tiles = [ ] 
        for row in symbols: 
            colcount = 0
            cols = [ ]
            for col in row:
                if not (col in SYMBOLS):
                    raise ValueError("Invalid sudoku symbol: " + col )
                cols.append(Tile(rowcount, colcount, col))
                colcount += 1
            if colcount != 9 : 
                raise ValueError("Length of row is wrong: '" + row + "'")
            self.tiles.append(cols)
            rowcount += 1
        if rowcount != 9:
            raise ValueError("Wrong number of rows")
            
                        
    @classmethod
    def from_file(cls, f):
        """Factory method: Read a Sudoku board from a file.
        Arguments: 
            f: file to read the Sudoku board from
        Returns: a Board object with tiles from the file
        """
        lines = [ ] 
        for line in f: 
            line = line.strip()
            if len(line) == 0:
                pass
            elif line[0] == "#":
                ## Comment in sdk format files
                pass
            else:
                lines.append( line )
        #DEBUG print("Read board from file: ", lines)
        return Board(lines)
        

    def __str__(self): 
        rep=""
        for row in self.tiles:
            for col in row:
                rep += str(col)
            rep += "\n"
        return rep.rstrip()


    
        
if __name__ == "__main__":
    brd_txt = ["435269781", "682571493", "197834562",
               "826195347", "374682915", "951743628",
               "519326874", "248957136", "763418295"]
    
    brd = Board(brd_txt)
    
    print(brd)
    
    

        
                
                

        
        
                    
