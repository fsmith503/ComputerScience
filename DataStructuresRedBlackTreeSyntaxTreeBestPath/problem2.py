import sys
import copy
sys.setrecursionlimit(100000000)

class STNode:
    def __init__(self, x):
        self.key = x
        self.left = None
        self.right = None

class SyntaxTree:
    def init_helper(self, i, l):
        if i >= len(l):
            return None

        node = STNode(l[i])
        node.left = self.init_helper(2 * i, l)
        node.right = self.init_helper(2 * i + 1, l)
        return node

    def __init__(self, l):
        self.root = self.init_helper(1, l)

    def parentheses_walk(self,root,list):
            if root == None:
                return 
            if root.left == None and root.right == None:
                list.append(root.key)
            else:
                list.append("(")
                self.parentheses_walk(root.left,list)
                list.append(root.key)
                self.parentheses_walk(root.right,list)
                list.append(")")

    def evaluate(self,node):
        #if node is leaf (left and right children are none):
        if node.left == None and node.right == None: 
            return node.key
        else:
            left_eval = self.evaluate(node.left)
            right_eval = self.evaluate(node.right)
            if node.key == "+": 
                return int(left_eval) + int(right_eval)
            if node.key == "*": 
                return int(left_eval) * int(right_eval)
            if node.key == "-": 
                return int(left_eval) - int(right_eval)
    
    def inprint(self, root, holder):
            if root != None:
                self.inprint(root.left,holder)
                holder.append(root.key)
                self.inprint(root.right,holder)

def driver():
    with open(sys.argv[1]) as f:
        n = int(f.readline().strip())
        symbol_list = [None] + f.readline().strip().split()  #I forgot that the indexing scheme assumes a one-indexed list. Try this in the driver instead, and it should build the tree correctly
    ST = SyntaxTree(symbol_list) #Creating the syntax tree
    temp = [] # initializing an empty list
    ST.parentheses_walk(ST.root, temp) # paretheses walk, stores finished items with paretheses in temp
    output_list = ''.join(temp)
    print(output_list)
    print(ST.evaluate(ST.root))

if __name__ == "__main__":
    driver()
