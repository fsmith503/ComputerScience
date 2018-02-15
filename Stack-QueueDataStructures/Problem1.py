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

    def insert(self, x):
        node = llNode(x)
        node.next = self.head
        self.head = node
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
        return result

# TODO: implement the stack
class Stack:
    #push, pop, # built in copy for print

    # class constructor
    def __init__(self):
        self.mysingleLL = singleLL()
        self.myllNode = llNode()

    # push method
    def push(self, x):
        self.mysingleLL.insert(x)

    # pop method
    def pop(self):
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
def print_stack(s):
    # only use s.push, s.pop, and s.is_empty
    if s.is_empty():
        print("Empty")
    else:
        t = []
        while not s.is_empty():
            t.append(s.pop())
        tstr = map(str, t)
        print(" ".join(tstr))
        while t:
            s.push(t.pop())
       
    
    

# this function runs the program according to the problem specification
def driver():
    s = Stack()
    with open(sys.argv[1]) as f:
        n = int(f.readline().strip())
        for _ in range(n):
            in_data = f.readline().strip().split()
            action, value_option = in_data[0], in_data[1:]
            if action == "push":
                value = int(value_option[0])
                s.push(value)
                #print("need to implement push")  # change this!
            elif action == "pop":
                try:
                    print(s.pop())
                except Underflow:
                    print("StackError")
                #print("need to implement pop")  # change this!
            elif action == "print":
                print_stack(s)
                #print("need to implement print")  # change this!


# this starter code should work with either python or python3
if __name__ == "__main__":
    driver()
