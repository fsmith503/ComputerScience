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
		self.upheap2(len(self.list)-1)
		#self.upheap(self.list[len(self.list)])
		   	
	def list_remove(self):
		"""
		#removes the key with highest priority and returns it
		"""
		if len(self.list) <= 2:
			return self.list.pop()[2]
		else:
			a = self.list[1]
			self.list[1] = self.list.pop()
			if len(self.list) == 1:
				print("HeapError")
			else:
				self.downheap(1)
			return a[2]  
		          
	def list_look(self):
		return self.list[1]

	def swap(self,x,y):
		temp1 = self.list[x]
		temp2 = self.list[y]
		self.list[x] = temp2
		self.list[y] = temp1

	def upheap1(self,i):
		if len(self.list) == 1:
			None
		elif self.list[i] < self.list[i//2]:
			self.swap(i,i//2)
			self.upheap1(i//2)

	def upheap2(self,i):
		"""
		"""		
		parent = i//2
		while i > 1 and self.list[parent] > self.list[i]:
			x = self.list[parent]	
			self.list[parent] = self.list[i]
			self.list[i] = x
			i = parent
			parent = i//2		

	def upheap(self,i):
		"""
		"""
		print(self.list)
		print(i)
		if len(self.list) <= 2:
			None
		elif len(self.list) == 3:
			if self.list[i//2][0] == self.list[i][0]:
					self.up_counter_checker(i,i//2)	 #fix
			elif self.list[i][0] > self.list[i//2][0]:
				self.swap(i,i//2)

		elif len(self.list) > 3:
				if self.list[i//2][0] == self.list[i][0]:
					self.counter_checker(i,i//2)
				elif self.list[i][0] < self.list[i//2][0]:
					self.swap(i,(i//2))
					self.downheap((i))	
		
	def up_counter_checker(self,x,y):
		if self.list[x][1] < self.list[y][1]:
			#self.swap(i,i+1)
			None
		if self.list[x][1] > self.list[y][1]:
			self.swap(x,y)

	def down_counter_checker(self,x,y):
		if self.list[x][1] < self.list[y][1]:
			#self.swap(i,i+1)
			None
		if self.list[x][1] > self.list[y][1]:
			self.swap(x,y)

	def downheap(self,i):
		"""
		max-heap property
		"""
		if len(self.list) <= 2:
			None
		elif len(self.list) == 3:
			if self.list[i][0] == self.list[i+1][0]:
					self.down_counter_checker(i,i+1)	
			elif self.list[i][0] > self.list[i+1][0]:
				self.swap(i,i+1)

		elif len(self.list) > 3:
			if (2*i) > len(self.list) or ((2*i)+1) > len(self.list):
				None
			else:
				if self.list[2*i][0] == self.list[(2*i)+1][0]:
					self.down_counter_checker(2*i,(2*i)+1)
				elif self.list[2*i][0] > self.list[(2*i)+1][0]:
					self.swap(i,(2*i)+1)
					self.downheap((2*i)+1)
				elif self.list[2*i][0] < self.list[(2*i)+1][0]:
					self.swap(i,(2*i))
					self.downheap((2*i))

	def list_size(self):
		return len(self.list)-1

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
		return self.heap.list_size()
	
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
	TierA_Heap = Heap()
	TierB_Heap = Heap()
	with open(sys.argv[1]) as f:
		n = int(f.readline().strip())
		counter = 0
		for item in range(n):
			in_data = f.readline().strip().split()
			if in_data[1] == "A":
				in_data[1] = counter
				counter += 1
				in_data[2] = int(in_data[2])
				in_data.reverse()
				TierA_Heap.insert(tuple(in_data))
			if in_data[1] == "B":
				in_data[1] = counter
				counter += 1
				in_data[2] = int(in_data[2])
				in_data.reverse()
				TierB_Heap.insert(tuple(in_data))
		while TierA_Heap.size() > 0:
			print(TierA_Heap.remove())	
		while TierB_Heap.size() > 0:
			print(TierB_Heap.remove())
				
if __name__ == "__main__":
	driver()

