"""
Franklin Smith CIS 313 Problem4.py
"""

import sys
import copy
sys.setrecursionlimit(100000000)
class Underflow(Exception):
    pass  

class List(object):
    def __init__(self):
        self.list = [None]

    def list_insert(self,x):
        """
        Takes a single integer argument X and insets the key X into the heap
        """
        self.list.append(x)
        self.upheap(self.list.index(x))

    def list_remove(self):
        """
        removes the key with highest priority and returns it
        """
        if len(self.list) == 1:
            return
        else:
            a = self.list[len(self.list)-1]
            print(self.list[1])
            self.list.remove(a)
            if len(self.list) == 1:
                print("HeapError")
            else:
                self.list[1] = a
                self.upheap(1)

    def list_look(self):
        return self.list[1]

    def swap(self,x,y):
        temp1 = self.list[x]
        temp2 = self.list[y]
        self.list[x] = temp2
        self.list[y] = temp1

    def upheap(self,i):
        """
        min-heap property
        """
        if len(self.list) == 1:
            None
        elif self.list[i] < self.list[i//2]:
            self.swap(i,i//2)
            self.upheap(i//2)

    def downheap(i):
        """
        max-heap property
        """
        if self.list[i] > self.list[i//2]:
            swap(self.list,i,i//2)
            downheap(i)

    def list_size(self):
        print(len(self.list)-1)

    def list_best(self):
        if len(self.list) == 1:
            print("HeapError")
        else:
            print(self.list[1]) 

    def print_list(self):
        if len(self.list) == 1:
            print("Empty")
        else:
            res = map(str, self.list[1:])
            print(' '.join(res))

class Heap:
    def __init__(self):
        self.heap = List()

    def insert(self,x):
        """
        takes single argument and inserts
        the key x onto the heap
        """
        self.heap.list_insert(x)

    def remove(self):
        """
        removes the key with the highest priority and returns it
        """ 
        self.heap.list_remove()   

    def printh(self):
        self.heap.print_list()

    def look(self):
        """
        returns the key with the highest priority and returns it
        return List[0] ?
        """
        return self.heap.list_look()
    
    def size(self):
        """
        returns an integer, the number of keys in the heap
        size of list? What about empty nodes?
        """
        self.heap.list_size()
    
    def best(self):
        """
        outputs key with higher priority
        """
        self.heap.list_best()

    def remove(self):
        """
        removes the key with the highest priority
        output the removed element, if the heap is empty,
        output heap error
        """
        self.heap.list_remove()

    def is_empty(self):
        """
        returns a boolean indicating whether the heap is empty
        """
        if self.heap.size() == 0:
            return True
        else:
            return False

    def to_string(list):
        """
        returns a string, a space separated list of the keys in the heap in order
        of the underlying array
        """
        for i in list:
            print(i)

def driver():
    H = Heap()
    with open(sys.argv[1]) as f:
        n = int(f.readline().strip())
        for _ in range(n):
            in_data = f.readline().strip().split()
            action, value_option = in_data[0], in_data[1:]
            if action == "print":
                H.printh()
            if action == "best":
                H.best()
            if action == "insert":
                value = int(value_option[0])
                H.insert(value)
            if action == "size":
                H.size()
            if action == "remove":
                H.remove()

# this starter code should work with either python or python3
if __name__ == "__main__":
    driver()