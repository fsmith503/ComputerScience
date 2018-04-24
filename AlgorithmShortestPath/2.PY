import sys
import copy
#run the project by franklinsmith$ python project0.py < inSample.txt
sys.setrecursionlimit(100000000)



def algorithm():
	graphs = int(sys.stdin.readline())
	#print("graphs")
	#print(graphs)
	for graph in range(graphs): 
		nodes = int(sys.stdin.readline())
		#print("nodes")
		#print(nodes)
		edges = int(sys.stdin.readline())
		#print("edges")
		#print(edges)
		adj_matrix = []
		for i in range(nodes):
			adj_matrix.append([0]*nodes)
		
		for k in range(edges):
				in_data = sys.stdin.readline().strip().split()
				a = int(in_data[0])
				b = int(in_data[1])
				#print(str(a-1) , end = ' ')
				#print(b-1)
				
				adj_matrix[a-1][b-1] = 1 

		#printing the adjacency matrix
		#for row in adj_matrix:
			#print(row)

		num_path = [0]*nodes
		num_path[0] = 1
		short_path = [-1]*nodes
		short_path[0] = 0
		long_path = [-1]*nodes
		long_path[0] = 0
		#print("num_path")
		#for a in range(nodes):
			#num_path.append(0)
		

		#for b in range(2,nodes):
			#num_path[b] = 0

		for c in range(0, nodes-1):
			for d in range(c+1, nodes):
				if (adj_matrix[c][d]) == 1:
					num_path[d] = num_path[c] + num_path[d]
					#update longest and shortest path values here also
					if (short_path[d]) != -1:
						short_path[d] = min(short_path[c] + 1, short_path[d])
					else:
						short_path[d] = short_path[c] + 1
					long_path[d] = max(long_path[c]+1, long_path[d])
		#print("end of logic")
		#print(num_path)
		print("graph num: " + str(graph+1))# of graphs))
		print("shortest path " + str(short_path[nodes-1]))
		print("longest path " + str(long_path[nodes-1]))
		print("number of paths " + str(num_path[nodes-1]))

# this starter code should work with either python or python3
if __name__ == "__main__":	
	algorithm()