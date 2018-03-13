import sys
import copy
sys.setrecursionlimit(100000000)

class Node:
	def __init__(self,x):
		self.data = x
		self.left = None
		self.right = None
		self.parent = None

class BST:
	def __init__(self):
		self.root = None
		self.size = 0

	def insert(self,x):
		tempbool = True
		new_node = Node(x)
		if self.size == 0:
			self.root = new_node
			self.size += 1
			tempbool = False
		current = self.root
		while tempbool:
			if new_node.data <= current.data: #x.data is wrong
				if current.left is None:
					current.left = new_node
					new_node.parent = current
					self.size += 1
					return
				else:
					current = current.left
					continue
			else:
				if current.right is None:
					current.right = new_node
					new_node.parent = current
					self.size += 1
					return
				else:
					current = current.right
					continue

	def tree_predecessor(self,x):
		if x.left != None:
			return self.tree_maximum(x.left)
		y = x.parent
		while y != None and x == y.left:
			x = y
			y = y.parent
		return y

	def best_path(self,n): #n is a node
		if n == None:
			return 0
		l = self.best_path(n.left)
		r = self.best_path(n.right)
		a = max(l,r) + str(n.data).count('5')
		return a 	

	def transplant(self,u,v):
		if u.parent == None:
			self.root = v
		elif u == u.parent.left:
			u.parent.left = v
		else:
			u.parent.right = v
		if v != None:
			v.parent = u.parent

	def tree_delete(self,z):
		z = self.tree_search(self.root, z)
		if z == None:
			return z
		else:
			if z.left == None:
				self.transplant(z,z.right)
				if z == self.root:
					self.root = z.right
			elif z.right == None:
				self.transplant(z,z.left)
				if z == self.root:
					self.root = z.left
			else:
				y = self.tree_minimum(z.right)
				if y.parent != z:
					self.transplant(y,y.right)
					y.right = z.right
					y.right.parent = y
				self.transplant(z,y)
				y.left = z.left
				y.left.parent = y
				if z == self.root:
					self.root = y
			self.size = self.size - 1
			return z			

	def tree_search(self,x,k):
		if x == None or k == x.data: 
			return x
		if k < x.data:
			return self.tree_search(x.left,k)
		else: 
			return self.tree_search(x.right,k)

	def iterative_tree_search(self,x,k):
		while x != None and k != x.key:
			if k < x.key:
				x = x.left
			else:
				x = x.right
		return x

	def tree_minimum(self,x):
		while x.left != None:
			x = x.left
		return x

	def tree_maximum(self,x):
		while x.right != None:
			x = x.right
		return x

	def tree_successor(self,x):
		if x.right != None:
			return self.tree_minimum(x.right)
		y = x.p
		while y != None and x == y.right:
			x = y
			y = y.p
		return y

	def inprint(self, root, holder):
		if root != None:
			self.inprint(root.left,holder)
			holder.append(root.data)
			self.inprint(root.right,holder)

	def preprint(self, root, holder):
		if root != None:
			holder.append(root.data)
			self.preprint(root.left,holder)
			self.preprint(root.right,holder)

	def postprint(self, root, holder):
		if root != None:
			self.postprint(root.left,holder)
			self.postprint(root.right,holder)
			holder.append(root.data)	

	def to_list_preorder(self):
		temp =[]
		if self.root != None:
			self.preprint(self.root,temp)
		return temp

	def to_list_inorder(self):
		temp =[]
		if self.root != None:
			self.inprint(self.root,temp)
		return temp

	def to_list_postorder(self):
		temp =[]
		if self.root != None:
			self.postprint(self.root,temp)
		return temp

def driver():
	binarysearchtree = BST()
	with open(sys.argv[1]) as f:
		n = int(f.readline().strip())
		for _ in range(n):
			in_data = f.readline().strip().split()
			if in_data [0] == "bpv":
				if binarysearchtree.root == None:
					print("TreeError")
				else:	
					print(binarysearchtree.best_path(binarysearchtree.root))
			if in_data[0] == "insert":
				binarysearchtree.insert(int(in_data[1]))
			elif in_data[0] == "remove":
				a = binarysearchtree.tree_delete(int(in_data[1]))
				if a == None:
					print("TreeError")
				else:
					None
			elif in_data[0] == "search":
				if binarysearchtree.tree_search(binarysearchtree.root,int(in_data[1])) != None:
					print("Found")
				else:
					print("NotFound")
			elif in_data[0] == "max":
				if binarysearchtree.root == None:
					print("Empty")
				else:
					print(binarysearchtree.tree_maximum(binarysearchtree.root).data)
			elif in_data[0] == "min":
				if binarysearchtree.root == None:
					print("Empty")
				else:
					print(binarysearchtree.tree_minimum(binarysearchtree.root).data)
			elif in_data[0] == "inprint":
				if binarysearchtree.root == None:
					print("Empty")
				else:
					return_val = binarysearchtree.to_list_inorder()
					temp_list = []
					for i in range (len(return_val)):
						temp_list.append(str(return_val[i]))
					print(" ".join(temp_list))
			elif in_data[0] == "preprint":
				if binarysearchtree.root == None:
					print("Empty")
				else:
					return_val = binarysearchtree.to_list_preorder()
					temp_list = []
					for i in range (len(return_val)):
						temp_list.append(str(return_val[i]))
					print(" ".join(temp_list))

			elif in_data[0] == "postprint":
				if binarysearchtree.root == None:
					print("Empty")
				else:
					return_val = binarysearchtree.to_list_postorder()
					temp_list = []
					for i in range (len(return_val)):
						temp_list.append(str(return_val[i]))
					print(" ".join(temp_list))

if __name__ == "__main__":
	driver()				
