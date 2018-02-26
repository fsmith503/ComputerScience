"""
Franklin Smith CIS 313 Problem2.py
"""
import sys
import copy
sys.setrecursionlimit(100000000)
lib = set([ ('(',')'), ('[',']'), ('{','}'), ('<','>') ])

def driver():
    with open(sys.argv[1]) as f:
        n = int(f.readline().strip())
        for k in range(n):
            in_data = f.readline().strip()
            checker(in_data)

def checker(input_array):
    result = "YES"
    s = Stack()
    if len(input_array)%2 != 0:
        result = "NO"
    starters= '{[(<'
    result = "YES"
    for element in input_array:
        if element in starters:
            s.push(element)
        else:
            if 0 == s.size():
                result = "NO"
            temp = s.pop()
            if (temp , element) not in lib:
                result = "NO"
    print(result)       

class Underflow(Exception):
    pass  

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

    def length(self):
        temp=self.head
        count=0
        while(temp):
            count+=1
            temp=temp.next
        return count

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

class Stack:
    def __init__(self):
        self.mysingleLL = singleLL()
        self.myllNode = llNode()

    def push(self, x):
        self.mysingleLL.insert(x)

    def size(self):
         return self.mysingleLL.length()

    def pop(self):
        a = self.mysingleLL.delete_head()
        return a.data

    def is_empty(self):
        if self.mysingleLL.head == None:
            return True
        else:
            return False

def print_stack(s):
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
       
if __name__ == "__main__":
    driver()