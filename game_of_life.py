#Franklin Smith Game of Life Project
"""
My project is a cellular automaton style biological simulation.
The sytem is described in Chapter 11 of the Miller and Ranum text. 
The project has three main parts:
A class named World that defines a 2D grid where cells are accessed according 
to their row and column coordinates
Classes for Bear and Fish, the organisms that can inhabit the world
Two top level functions, wbf and step_system; the first will make a world and 
populate it at random with bears and fish, and the second will run a simulation using that world.
"""
import numpy as np
import random

logging = False

def log(message):
    if logging:
        print(message)

class World:
    """
    World Class
    the constructor should is passed the grid size (number of rows and columns)
    all cells should contain None when the world is initialized; later 
    they contain references to Fish or Bear objects
    include a method named biota that returns a list of Fish and Bear objects currently in the grid
    For my world class I made a method called get item 
    that returns the item from the grid. I made a method 
    called set item that sets the item int he grid to the input. 
    I made a method called empty location that checks if the object 
    passed into it is empty or not, returns true of false. I made a method 
    called biota that returns a list of occupied cells.
    """
    def __init__(self,mx,my):
        self._maxX = mx
        self._maxY = my
        self._grid = [[None for a in range(my)]for b in range((mx))]
        
        
    def __getitem__(self, row, col):
        return self._grid[row][col]
    
    def __setitem__(self, x1, y1, thing):
        self._grid[x1][y1] = thing
    
    def emptyLocation(self,row,col):
        if self._grid[row][col] is None:
            return True
        else:
            return False
    
   
    def biota(self):
        temp_list = []
        for c in self._grid:
            for d in c:
                if d is not None:
                    temp_list.append(d)
        return temp_list
                    
	#print("\U0001F420") # tropical fish
	#print("\U0001F41F") # fish
	#print("\U0001F43B") # bear

	class Animal:
    """
    Animal Class
    For my animal class I made a method called live that checks 
    if 2 or more fish are in the neighboring cells, if that is 
    true then the object (the fish) dies and is removed from the 
    simulator. The state then goes to dead. In this method also 
    the fish breeds a new fish in a random cell. I made a method 
    called move that looks at the neighboring cells and chooses
    an empty one at random and moves the object to that cell if it is empty.
    """
    def __init__(self, world, location):
        self._location = location
        self._world = world
        x , y = location
        #self._world.set_item(x, y, self)
        self._alive = True
        
        self._world.__setitem__(self._location[0], self._location[1], self)
    
    def live(self):
        #if 2 or more fish in neighboring 
        #cells, fish dies removed from suimulator
        #state goes to dead
        self._counter += 1   
        offsetList = [(-1,1) ,(0,1) ,(1,1) ,
                      (-1,0)        ,(1,0) ,
                      (-1,-1),(0,-1),(1,-1)]
        adjfish = 0
        for offset in offsetList:
            newx = self._row + offset[0]
            newy = self._col + offset[1]
            if self._world.__getitem__(newx,newy) == "fish":
                adjfish += 1
        
        if adjfish >= 2:
            self._life = False
            (t1,t2) = (self._row, self._col)
            self._world.__setitem__(t1,t2, None)  
        
        else:
            #breeding
            if self._counter >= Fish.breed_interval:
                a = random.randint(-1,1)
                b = random.randint(-1,1)
                newerx = self._row + a
                newery = self._col + b
                if self._world.__getitem__(newerx,newery) is None:
                    self._world.__setitem__(a, b, self)
                
    def move(self):
        # look at random cell
        # if cell == none
        # move fish to that cell
        #while cell is not none keep doing random choice
        #move
        onsetList = [(-1,1) ,(0,1) ,(1,1) ,
                      (-1,0)        ,(1,0) ,
                      (-1,-1),(0,-1),(1,-1)]
        #WHILE "emptyLocation" is NOT True, find another random neighbor to move to.
        #emp = self._world.empty_Location(random.choice(onsetlist))
        a1 = random.choice(onsetList)
        #print(a1) #(val,val)
        newa1 = self._row + a1[0]
        newb2 = self._col + a1[1]
        while self._world.__getitem__(newa1,newb2) is not None:
            a2 = random.choice(onsetList)
            newa1 = self._row + a2[0]
            newb2 = self._col + a2[1]
        #print(newa1)
        #print(newb2)
        self._world.__setitem__(self._row , self._col, None)
        self._row = newa1
        self._col = newb2
        self._world.__setitem__(newa1, newb2, self) 


        class Fish(Animal):
    """
    Fish Class
    #the constructor for the fish class will be passed a reference to a world object and a location, in the form
    of a tuple with a row number and column number (the object needs to know its location so it can look for other 
    objects in neighboring cells)
    
    For my fish class I made a method called repr that returns 
    the emoji of the fish. I made a method called location that 
    returns the location of an object. I made a method called live
    that checks if 2 or more objects are in the neighboring cells,
    if that is true then the object (the fish) dies and is removed 
    from the simulator. The state then goes to dead. In this method 
    also the fish breeds a new fish in a random cell. I made a method 
    called move that looks at the neighboring cells and chooses an empty 
    one at random and moves the object to that cell if it is empty.
    
    (1) Fish are susceptible to overcrowding: if there are fish in 2 or more 
    neighboring cells the fish dies (it's removed from the simulation)
    (2) A fish can reproduce if it has been alive for a certain number of time steps: a random neighboring 
    cell is chosen, and if that cell is empty, a new fish is placed in that cell
    (3) A fish can move to another cell: it picks a random direction, and if 
    the neighboring cell in that 
    direction is unoccupied the fish moves there
    The constructor for the Fish class will be passed a reference to a World 
    object and a location, in 
    the form of a tuple with a row number and column number (the object needs to know its location so it can look for other objects in neighboring cells).
    The class should include the following methods:
    live implements rules 1 and 2 shown above
    move implements rule 3
    location returns the current grid location (row and column) of the object
    I Defineed a class variable named breed_interval to specify how many time steps 
    a fish must be alive before it reproduces; the initial value for this variable is 12.
    """
    breed_interval = 12
    def __init__(self, world, location):
        Animal.__init__(self, world , location)
        self._world = world
        (self._row , self._col) = location
        self._counter = 0
        self._world._grid[self._row][self._col] = self
        self._life = True
    
    def __repr__(self):
        return "\U0001F41F"
    
    def location(self):
        return (self._row,self._col)     
        
    def live(self):
        #if 2 or more fish in neighboring 
        #cells, fish dies removed from suimulator
        #state goes to dead
        self._counter += 1   
        offsetList = [(-1,1) ,(0,1) ,(1,1) ,
                      (-1,0)        ,(1,0) ,
                      (-1,-1),(0,-1),(1,-1)]
        adjfish = 0
        for offset in offsetList:
            newx = self._row + offset[0]
            newy = self._col + offset[1]
            if self._world.__getitem__(newx,newy) == "fish":
                adjfish += 1
        
        if adjfish >= 2:
            self._life = False
            self._world.__setitem__(self._row, self._col, None)  
        
        else:
            #breeding
            if self._counter >= Fish.breed_interval:
                a = random.randint(-1,1)
                b = random.randint(-1,1)
                newerx = self._row + a
                newery = self._col + b
                if self._world.__getitem__(newerx,newery) is None:
                    self._world.__setitem__(a, b, self)
                
    def move(self):
        # look at random cell
        # if cell == none
        # move fish to that cell
        #while cell is not none keep doing random choice
        #move
        onsetList = [(-1,1) ,(0,1) ,(1,1) ,
                      (-1,0)        ,(1,0) ,
                      (-1,-1),(0,-1),(1,-1)]
        #WHILE "emptyLocation" is NOT True, find another random neighbor to move to.
        #emp = self._world.empty_Location(random.choice(onsetlist))
        a1 = random.choice(onsetList)
        #print(a1) #(val,val)
        newa1 = self._row + a1[0]
        newb2 = self._col + a1[1]
        while self._world.__getitem__(newa1,newb2) is not None:
            a2 = random.choice(onsetList)
            newa1 = self._row + a2[0]
            newb2 = self._col + a2[1]
        #print(newa1)
        #print(newb2)
        self._world.__setitem__(self._row, self._col, None)
        self._row = newa1
        self._col = newb2
        self._world.__setitem__(newa1, newb2, self) 
    

    	class Bear(Animal):
    """
    Bear Class
    #the constructor for my bear class will be passed a reference to a world 
    object and a location, in the form of a tuple witha row number and column 
    number (the object needs to know its location so it can look for other 
    objects in neighboring cells)
    Bear Class
    During the simulation a Bear object behaves as follows:
    (1) A bear looks for fish in each adjacent cell; if it finds one or more 
    fish it eats one at random
    (2) If a bear has not eaten for certain number of time steps it dies 
    (it's removed from the simulation)
    (3) A bear can reproduce if it has been alive for a certain number of time 
    steps: a random neighboring cell is chosen, and if that cell is empty, a 
    new bear is placed in that cell
    (4) A bear can move to another cell: it picks a random direction, and if 
    the neighboring cell in that direction is unoccupied the bear moves there
    I Defined a class variable named breed_interval to specify how many time 
    steps a bear must be alive before it reproduces; the initial value for this 
    variable is 8. I Defined another class variable named survive_without_food 
    to be the number of time steps a bear can live before it dies from starvation; 
    the initial value for this variable is 10.
    The constructor for my bear class is passed a reference to a World object and a location, 
    in the form of a tuple with a row number and column number (the object needs 
    to know its location so it can look for other objects in neighboring cells).
    The class should include the following methods:
    live implements rules 1, 2, and 3 shown above
    move implements rule 4
    location returns the current grid location (row and column) of the object
    """
    breed_interval = 8
    survive_without_food = 8
    def __init__(self, world, location):
        Animal.__init__(self, world, location)
        self._world = world
        (self._row , self._col) = location
        self._counter = 0
        self._world._grid[self._row][self._col] = self
        self._life = True
        self.days_with_no_food = 0
        #self.survive_without_food = 8
    
    def __repr__(self):
        return "\U0001F43B"
        
    def live(self):
        #looks for fish in each adjacent cell,
        #if it finds one or more it eats one at random
        #if bear has not eaten for certain number
        #of time steps it dies 
        #(removed from simulation)
        #if bear breed_interval >= 8
        #then choose random neighboring cell
        # if cell is empty, new fish placed in that cell
        #if 2 or more bears in neighboring 
        
        self._counter += 1   
        offsetList = [(-1,1) ,(0,1) ,(1,1) ,
                      (-1,0)        ,(1,0) ,
                      (-1,-1),(0,-1),(1,-1)]
        adjfish = 0
        food_list = []
        for offset in offsetList:
            newx = self._row + offset[0]
            newy = self._col + offset[1]
            if self._world.__getitem__(newx,newy) == "fish":
                food_list.append((newx,newy))
                adjfish += 1
        if len(food_list) == 0:
            self.days_with_no_food += 1
        if adjfish >= 1:
            a = random.choice(food_list)
            self._world.__setitem__(a[0], a[1], None)
            self.days_with_no_food = 0
            #one or more fish in adjacent cell
            #eat one of the fish at random
            #self._life = False
            #self._world.__setitem__(self._row, self._col, None)  
        else:
            #breeding
            if self._counter == Bear.breed_interval:
                a = random.randint(-1,1)
                b = random.randint(-1,1)
                newerx = self._row + a
                newery = self._col + b
                if self._world.__getitem__(newerx,newery) is None:
                    self._world.__setitem__(a, b, self)
        
        if self.days_with_no_food == self.survive_without_food:
            self._world.__setitem__(self._row, self._col, None)
            self._life = False
                    
        #food logic
        #Define a class variable named breed_interval to specify 
        #how many time steps a bear must be alive before it reproduces; 
        #the initial value for this variable is 8. Define another class variable 
        #named survive_without_food to be the number of time steps a bear can live 
        #before it dies from starvation; the initial value for this variable is 10.
        
    def move(self):
        # look at random cell
        # if cell == none
        # move bear to that cell
        # look at random cell
        # if cell == none
        # move fish to that cell
        #while cell is not none keep doing random choice
        #move
        onsetList = [(-1,1) ,(0,1) ,(1,1) ,
                      (-1,0)        ,(1,0) ,
                      (-1,-1),(0,-1),(1,-1)]
        #WHILE "emptyLocation" is NOT True, find another random neighbor to move to.
        #emp = self._world.empty_Location(random.choice(onsetlist))
        a1 = random.choice(onsetList)
        #print(a1) #(val,val)
        newa1 = self._row + a1[0]
        newb2 = self._col + a1[1]
        while self._world.__getitem__(newa1,newb2) is not None:
            a2 = random.choice(onsetList)
            newa1 = self._row + a2[0]
            newb2 = self._col + a2[1]
        #print(newa1)
        #print(newb2)
        self._world.__setitem__(self._row, self._col, None)
        self._row = newa1
        self._col = newb2
        self._world.__setitem__(newa1, newb2, self) 
        
        
    def location(self):
        return (self._row, self._col) 



    def wbf(nrows, ncols, nbears, nfish):
    '''
    Return a new World object with the specified number of Bear and Fish objects.
    '''
    w = World(nrows,ncols)
    #bear_count = 0
    #fish_count = 0 
    bear_location_list = []
    fish_location_list = []
    for q in range(nbears):
        #make a list with locations in it
        #put animal at that location
        #Bear(w, (random.randint(0, nrows), random.randint(0, ncols))
        bear_location_list.append((random.randint(0,nrows),random.randint(0,ncols)))
    
    #for e in range(len(bear_location_list)):
        #check if any of the locations are the same as any in fish list
        #if it is change it to another random location
    
    for r in range(nfish):
        #Fish(w, (random.randint(0, nrows), random.randint(0, ncols))
        fish_location_list.append((random.randint(0,nrows),random.randint(0,ncols)))
    
    for t in range(len(bear_location_list)):
        for k in range(len(fish_location_list)):
            if bear_location_list[t] == fish_location_list[k]:
                bear_location_list[t][0] = random.randint(0,nrows)
                bear_location_list[t][1] = random.randint(0,ncols)
                
    
    for s in bear_location_list:
        #print(s[0])
        #print(s[1])
        Bear(w, (s[0], s[1]))
        
    
    for m in fish_location_list:
        Fish(w, (m[0], m[1]))
        
    return(w)

    #Tests
    """
    # Setting breed_interval to 1 should cause a fish to reproduce when live is called
	w2 = World(5,5)
	Fish.breed_interval = 1
	f2 = Fish(w2, (2,2))
	f2.live()
	assert len(w2.biota()) == 2

	# Reset the interval to original value for remaining tests
	Fish.breed_interval = 12
	"""

	"""
	# A new world has no objects
	w1 = World(5,5)
	assert len(w1.biota()) == 0

	# After adding a fish there should be one object
	f1 = Fish(w1, (2,2))
	assert len(w1.biota()) == 1

	# Test the location method
	assert f1.location() == (2,2)
	"""

	"""
	# When a fish moves it should be within one cell of its original location
	w4 = World(5,5)
	f4 = Fish(w4, (2,2))
	f4.move()
	r, c = f4.location()
	assert (r,c) != (2,2)
	assert abs(r-2) <= 1 and abs(c-2) <= 1
	"""

	"""
	# Make three fish, the one in the middle should die from overcrowding
	w3 = World(5,5)
	f3 = Fish(w3, (2,2))
	Fish(w3, (1,1))
	Fish(w3, (3,3))
	f3.live()
	assert len(w2.biota()) == 2
	"""

	"""
	# Test the Bear constructor and location method
	w1 = World(5,5)
	b1 = Bear(w1, (1,1))
	assert len(w1.biota()) == 1
	assert b1.location() == (1,1)
	"""

	"""
	# Repeat the reproduction test for Bears
	w2 = World(5,5)
	Bear.breed_interval = 1
	b2 = Bear(w2, (2,2))
	b2.live()
	assert len(w2.biota()) == 2
	Bear.breed_interval = 8
	"""

	"""
	# Make fish for the bear to eat, count the number of objects after eating
	w3 = World(5,5)
	b3 = Bear(w3, (2,2))
	Fish(w3, (1,1))
	Fish(w3, (3,3))
	b3.live()
	assert len(w2.biota()) == 2
	"""

	"""
	# Setting the survival limit to 1 should cause a Bear to starve 
	w4 = World(5,5)
	Bear.survive_without_food = 1
	b4 = Bear(w4, (2,2))
	b4.live()
	assert len(w4.biota()) == 0
	"""

	"""
	# Repeat the move test for bears
	w5 = World(5,5)
	b5 = Bear(w5, (2,2))
	b5.move()
	r, c = b5.location()
	assert (r,c) != (2,2)
	assert abs(r-2) <= 1 and abs(c-2) <= 1
	"""









