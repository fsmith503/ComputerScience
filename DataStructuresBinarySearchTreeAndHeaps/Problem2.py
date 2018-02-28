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
		self.upheap(len(self.list)-1)

	def upheap(self,x):
		"""
		"""
		i = x
		parent = i//2
		while i > 1 and self.list[parent] > self.list[i]:
			x = self.list[parent]	
			self.list[parent] = self.list[i]
			self.list[i] = x
			i = parent
			parent = i//2
			
	def list_remove(self):
		"""
		#removes the key with highest priority and returns it
		"""
		if len(self.list) <= 2:
			return self.list.pop()
		else:
			a = self.list[1]
			self.list[1] = self.list.pop()
			if len(self.list) == 1:
				print("HeapError")
			else:
				self.downheap(1)
			return a  		  

	def list_look(self):
		return self.list[1]

	def swap(self,x,y):
		temp1 = self.list[x]
		temp2 = self.list[y]
		self.list[x] = temp2
		self.list[y] = temp1
		
	def counter_checker(self,x,y):
		if self.list[x][1] < self.list[y][1]:
			#self.swap(i,i+1)
			None
		if self.list[x][1] > self.list[y][1]:
			self.swap(x,y)


	def downheap(self,i):
		"""
		max-heap property
		"""
		parent = i//2
		while i > 2 and self.list[parent] > self.list[i]:
			x = self.list[parent]
			self.list[parent] = self.list[i]
			self.list[i] = x
			i = parent
			parent = i//2

	def list_size(self):
		return len(self.list)-1

	def list_best(self):
		if len(self.list) == 1:
			print("HeapError")
			#print("list_best")
			#print(self.list[0])
		else:
			return(self.list[1]) 

	def print_list(self):
		if len(self.list) == 1:
			print("Empty")
		else:
			res = map(str, self.list[1:])
			print(' '.join(res))

class MaxHeap:
	def __init__(self):
		self.name = "MaxHeapLowNums"
		self.heap = Heap()
	
	def insert(self,x):
		self.heap.insert(-x)

	def remove(self):
		return -self.heap.remove()

	def best(self):
		"""
		outputs key with higher priority
		"""
		return -self.heap.best()

	def printh(self):
		return self.heap.printh()

	def size(self):
		return self.heap.size()		

class Heap:
	def __init__(self):
		self.name = "MinHeapHighNums"
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
		return self.heap.list_remove()   

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
		return self.heap.list_size()
	
	def best(self):
		"""
		outputs key with higher priority
		"""
		return self.heap.list_best()

	def remove(self):
		"""
		removes the key with the highest priority
		output the removed element, if the heap is empty,
		output heap error
		"""
		return self.heap.list_remove()

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
	"""
	why is my max heap acting as a min
	"""
	MaxHeap1 = MaxHeap()
	MinHeap1 = Heap()
	#MinHeap1.printh()
	#MaxHeap1.printh()
	with open(sys.argv[1]) as f:
		n = int(f.readline().strip())
		for k in range(n):
			in_data = f.readline().strip().split()
			a = int(in_data[0])
			if k == 0:	
				MaxHeap1.insert(a)
				print(a)
				"""
				MinHeap1.printh()
				print("MinHeap^^")
				MaxHeap1.printh()
				print("MaxHeap^^")
				"""
			if k == 1:
				if MaxHeap1.best() < a:
					MinHeap1.insert(a)
					print(((MaxHeap1.best() + MinHeap1.best())/2.0))
					"""
					MinHeap1.printh()
					print("MinHeap^^")
					MaxHeap1.printh()
					print("MaxHeap^^")
					"""
				else:
					MaxHeap1.insert(a)
					print(((MaxHeap1.best() + a) /2.0))
					"""
					MinHeap1.printh()
					print("MinHeap^^")
					MaxHeap1.printh()
					print("MaxHeap^^")
					"""
			if k > 1:
				#print(str(a) + " inputted")
				#if MinHeap1.size() == 1 and :
					#average all things in max heap
					#print("min empty")
				#if MaxHeap1.size() == 1:
					#avera gll things in min heap
					#print("max empty")
				if a <= MinHeap1.best():
					MaxHeap1.insert(a) 
					rebalance(MaxHeap1,MinHeap1)
					print(median(MaxHeap1,MinHeap1))
					"""
					MinHeap1.printh()
					print("MinHeap^^")
					MaxHeap1.printh()
					print("MaxHeap^^")
					"""
				if a > MaxHeap1.best():
					MinHeap1.insert(a)
					rebalance(MaxHeap1,MinHeap1)
					print(median(MaxHeap1,MinHeap1))
					"""
					MinHeap1.printh()
					print("MinHeap^^")
					MaxHeap1.printh()
					print("MaxHeap^^")
					"""	

def median(MaxHeap,MinHeap):
	if (MaxHeap.size()) > (MinHeap.size()):
		return MaxHeap.best() #returning 1 wrongly
	if (MinHeap.size()) > (MaxHeap.size()):
		return MinHeap.best()
	if MaxHeap.size() == MinHeap.size():
		return(((MinHeap.best() + MaxHeap.best())/2.0))

def rebalance(MaxHeap,MinHeap):
	#print("max heap size:  " + str(MaxHeap.size()))
	#print("min heap size:  " + str(MinHeap.size()))
	if (MaxHeap.size()) == (MinHeap.size()+2):
		MinHeap.insert(MaxHeap.remove())
	if (MinHeap.size()) == (MaxHeap.size()+2):
		MaxHeap.insert(MinHeap.remove())
	#heap1.printh()
	#heap2.printh()
	return

if __name__ == "__main__":
	driver()			