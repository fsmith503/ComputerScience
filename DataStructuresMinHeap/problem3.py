"""
Franklin Smith CIS 313 Problem3.py
"""
import sys
import copy
sys.setrecursionlimit(100000000)

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
        if self.head == None:
            self.tail = None
            self.size = 0
        return result

    def len(self):
        return self.size

class Queue:
    def __init__(self):
        self.mysingleLL = singleLL()
        self.myllNode = llNode()

    def enqueue(self, x):
        self.mysingleLL.insert(x)

    def dequeue(self):
        a = self.mysingleLL.delete_head()
        return a.data

    def is_empty(self):
        if self.mysingleLL.head == None:
            return True
        else:
            return False

    def size(self):
        b = self.mysingleLL.len()
        return b
        
def print_queue(s):
    if s.is_empty():
        print("Empty")
    else:
        t = []
        while not s.is_empty():
            t.append(s.dequeue())
        tstr = map(str, t)
        print(" ".join(tstr))
        t.reverse()
        while t:
            s.enqueue(t.pop())

def driver():
    Q = Queue()
    with open(sys.argv[1]) as f:
        n = int(f.readline().strip())
        energy = 0
        counter = 0
        for k in range(n):
            in_data = f.readline().strip().split()
            a = [in_data[0],in_data[1]]
            energy += int(a[0])
            path = int(a[1])
            Q.enqueue(a)
            e = Q.dequeue()
            Q.enqueue(e)
            energy = energy - path
            counter += 1
            if energy < 0:
                print(counter)
                break
            if counter == n:
                print("0")
                break      

if __name__ == "__main__":
    driver()