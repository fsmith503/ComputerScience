
# this is just a rough outline for completing problem 1 from programming assignment 1
# you don't have to use this code if you don't want to, but at least read and understand it

#     here are suggested interfaces for the Stack and Queue classes
#
#     interface stack {
#         Boolean is_empty();           // returns True if empty, False if not
#         void push(Type X);            // pushes X onto the stack
#         Type pop() raises Underflow;  // pops top element of the stack,
#                                          raises Underflow if stack is empty
#     }
#
#     interface queue {
#         Boolean is_empty();               // returns True if empty, False if not
#         void enqueue(Type X);             // appends X to the queue
#         Type dequeue() raises Underflow;  // removes front element of the
#                                              queue, raises Underflow if queue is empty
#     };

import sys
import copy
sys.setrecursionlimit(100000000)
# TODO: any other imports you might need (e.g., your linked list class)

# custom Underflow exception
class Underflow(Exception):
    pass  # make it fancier if you want :)

class llNode(object):
    def __init__(self, data=None):
        self.data = data
        self.next = None

class singleLL(object):
    def __init__(self):
        self.size = 0
        self.head = None
        self.tail = None

    def insert(self, x):
        if self.size == 0:
            node = llNode(x)
            self.head = node
            self.tail = node
            self.size += 1
        elif self.size >= 1:
            node = llNode(x)
            self.tail.next = node
            self.tail = node 
            self.size += 1

    def delete(self, x):
        y = self.head
        while y != None and y.next != x:
            y = y.next
        if y != None:
            y.next = x.next
            self.size -= 1

    def delete_head(self):
        k = self.head
        if self.head == None:
            raise Underflow
        else:
            result = self.head
            self.head = result.next
        #
        if self.head == None:
            self.tail = None
            self.size = 0
        return result

# TODO: implement the stack
class Queue:
    #push, pop, # built in copy for print

    # class constructor
    def __init__(self):
        self.mysingleLL = singleLL()
        self.myllNode = llNode()

    # push method
    def enqueue(self, x):
        self.mysingleLL.insert(x)

    # pop method
    def dequeue(self):
        a = self.mysingleLL.delete_head()
        return a.data

    # is_empty method
    def is_empty(self):
        if self.mysingleLL.head == None:
            return True
        else:
            return False
        
# TODO: implement the print function
# args: s, Stack
def print_queue(s):
    # only use s.push, s.pop, and s.is_empty
    if s.is_empty():
        print("Empty")
    else:
        """
        t = []
        c = copy.deepcopy(s)
        while not c.is_empty():
            t.append(c.dequeue())
        t = map(str, t)
        print(" ".join(t))
        """
        t = []
        while not s.is_empty():
            t.append(s.dequeue())
        tstr = map(str, t)
        print(" ".join(tstr))
        t.reverse()
        while t:
            s.enqueue(t.pop())
        

       

# this function runs the program according to the problem specification
def driver():
    s = Queue()
    with open(sys.argv[1]) as f:
        n = int(f.readline().strip())
        for _ in range(n):
            in_data = f.readline().strip().split()
            action, value_option = in_data[0], in_data[1:]
            if action == "enqueue":
                value = int(value_option[0])
                s.enqueue(value)
                #print("need to implement push")  # change this!
            elif action == "dequeue":
                try:
                    print(s.dequeue())
                except Underflow:
                    print("QueueError")
                #print("need to implement pop")  # change this!
            elif action == "print":
                print_queue(s)
                #print("need to implement print")  # change this!


# this starter code should work with either python or python3
if __name__ == "__main__":
    driver()
