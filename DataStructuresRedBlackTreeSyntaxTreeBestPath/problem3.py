import sys
import copy
sys.setrecursionlimit(100000000)

class NilNode:
	def __init__(self):
		self.color = "black"
		self.data = None
		self.left = None
		self.right = None

class Node:
	def __init__(self,x,y):
		self.data = x
		self.left = y
		self.right = y
		self.parent = y
		self.color = "red"

class RBT:
	def __init__(self):
		self.size = 0
		self.Nil = NilNode()
		self.root = self.Nil

	def RB_Transplant(self,u,v):
		if u.parent == self.Nil: #if u.parent == None:
			self.root = v
		elif u == u.parent.left:
			u.parent.left = v
		else: 
			u.parent.right = v
		v.parent = u.parent			

	def Left_Rotate(self,x):
		y = x.right
		x.right = y.left
		if y.left != self.Nil:
			y.left.parent = x
		y.parent = x.parent
		if x.parent == self.Nil: #if x.parent == None: #if p[x] = nil[T]
			self.root = y
		elif x == x.parent.left:
			x.parent.left = y
		else:
			x.parent.right = y
		y.left = x
		x.parent = y

	def Right_Rotate(self,x):
		y = x.left
		x.left = y.right
		if y.right != self.Nil:
			y.right.parent = x
		y.parent = x.parent
		if x.parent == self.Nil:
			self.root = y
		elif x == x.parent.right:
			x.parent.right = y
		else:
			x.parent.left = y 
		y.right = x
		x.parent = y	

	def RB_Insert(self,y):
		z = Node(y,self.Nil)
		y = self.Nil
		x = self.root
		while x != self.Nil and x != None:
			y = x
			if z.data < x.data:
				x = x.left 
			else:
				x = x.right
		z.parent = y
		if y == self.Nil:
			self.root = z
		elif z.data < y.data:
			y.left = z
		else:
			y.right = z
		z.left = self.Nil
		z.right = self.Nil
		z.color = "red"
		self.RB_Insert_Fixup(z)

	def RB_Insert_Fixup(self,z):
		while z.parent.color == "red":
			if z.parent == z.parent.parent.left:
				y = z.parent.parent.right
				if y.color == "red":
					z.parent.color = "black"
					y.color = "black"
					z.parent.parent.color = "red"
					z = z.parent.parent
				else:
					if z == z.parent.right:
						z = z.parent
						self.Left_Rotate(z)
					z.parent.color = "black"
					z.parent.parent.color = "red"
					self.Right_Rotate(z.parent.parent)			
			else:
				y = z.parent.parent.left
				if y.color == "red":
					z.parent.color = "black"
					y.color = "black"
					z.parent.parent.color = "red"
					z = z.parent.parent
				else:
					if z == z.parent.left:
						z = z.parent
						self.Right_Rotate(z)
					z.parent.color = "black"
					z.parent.parent.color = "red"
					self.Left_Rotate(z.parent.parent)
		self.root.color = "black"

	def Tree_Minimum(self,x):
		while x.left != self.Nil:
			x = x.left
		return x

	def Tree_Maximum(self,x):
		while x.right != self.Nil:
			x = x.right
		return x	

	def RB_Delete(self, z):
		y = z
		y_originalcolor = y.color
		if z.left == self.Nil:
			x = z.right
			self.RB_Transplant(z,z.right)
		elif z.right == self.Nil:
			x = z.left
			self.RB_Transplant(z,z.left)
		else:
			y = self.Tree_Minimum(z.right)
			y_originalcolor = y.color
			x = y.right
			if y.parent == z:
				x.parent = y
			else:
				self.RB_Transplant(y,y.right)
				y.right = z.right
				y.right.parent = y 
			self.RB_Transplant(z,y)
			y.left = z.left
			y.left.parent = y
			y.color = z.color
		if y_originalcolor == "black":
			self.RB_Delete_Fixup(x)

	def RB_Delete_Fixup(self,x):
		while x != self.root and x.color == "black":
			if x == x.parent.left:
				w = x.parent.right 
				if w.color == "red":
					w.color = "black"
					x.parent.color = "red"
					self.Left_Rotate(x.parent)
					w = x.parent.right
				if w.left.color == "black" and w.right.color == "black":
					w.color = "red"
					x = x.parent
				elif w.right.color == "black":
					w.left.color = "black"
					w.color = "red"
					self.Right_Rotate(w)
					w = x.parent.right
				w.color = x.parent.color
				x.parent.color = "black"
				w.right.color = "black"
				self.Left_Rotate(x.parent)
				x = self.root
			else:
				print("test2")
				w = x.parent.left 
				if w.color == "red":
					w.color = "black"
					x.parent.color = "red"
					self.Right_Rotate(x.parent)
					w = x.parent.left
				if w.right.color == "black" and w.left.color == "black":
					w.color = "red"
					x = x.parent
				elif w.left.color == "black":
					w.right.color = "black"
					w.color = "red"
					self.Left_Rotate(w)
					w = x.parent.left
				w.color = x.parent.color
				x.parent.color = "black"
				w.left.color = "black"
				self.Right_Rotate(x.parent)
				x = self.root			
		x.color = "black"


	def inprint(self, root, holder):
		if root != self.Nil:
			self.inprint(root.left,holder)
			holder.append(root.data)
			self.inprint(root.right,holder)
			
	def to_list_inorder(self):
		temp =[]
		if self.root != self.Nil:
			self.inprint(self.root,temp)
		return temp			

	def tree_search(self,x,k):
		if x == self.Nil or k == x.data: 
			return x
		if k < x.data:
			return self.tree_search(x.left,k)
		else: 
			return self.tree_search(x.right,k)	

def driver():
	RedBlackTree = RBT()
	with open(sys.argv[1]) as f:
		n = int(f.readline().strip())
		for _ in range(n):
			in_data = f.readline().strip().split()
			if in_data[0] == "insert":
				RedBlackTree.RB_Insert(int(in_data[1]))
			elif in_data[0] == "remove":
				a = int(in_data[1])
				b = RedBlackTree.tree_search(RedBlackTree.root,a)
				if b != RedBlackTree.Nil:
					RedBlackTree.RB_Delete(b)
				else:
					print("TreeError")
			elif in_data[0] == "search":
				if RedBlackTree.tree_search(RedBlackTree.root,int(in_data[1])) != RedBlackTree.Nil:
					print("Found")
				else:
					print("NotFound")
			elif in_data[0] == "max":
				if RedBlackTree.root == RedBlackTree.Nil:
					print("Empty")
				else:
					print(RedBlackTree.Tree_Maximum(RedBlackTree.root).data)
			elif in_data[0] == "min":
				if RedBlackTree.root == RedBlackTree.Nil:
					print("Empty")
				else:
					print(RedBlackTree.Tree_Minimum(RedBlackTree.root).data)
			elif in_data[0] == "inprint":
				if RedBlackTree.root == RedBlackTree.Nil:
					print("Empty")
				else:
					return_val = RedBlackTree.to_list_inorder()
					temp_list = []
					for i in range (len(return_val)):
						temp_list.append(str(return_val[i]))
					print(" ".join(temp_list))
			
if __name__ == "__main__":
	driver()