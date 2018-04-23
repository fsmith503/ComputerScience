import sys
import copy
#run the project by franklinsmith$ python project0.py < inSample.txt
sys.setrecursionlimit(100000000)

def driver():
    #with open(sys.argv[1]) as f:
        #n = int(f.readline().strip())
        n = int(sys.stdin.readline())
        for _ in range(n):
            #in_data = f.readline().strip().split()
            #print(in_data)
            line = sys.stdin.readline().strip().split()
            #print(line)
            a = int(line[0])
            b = int(line[1])
            math_sum = a + b
            mult_sum = a * b
            print(str(math_sum) + " " + str(mult_sum))
            #print(a + b) 
            #print(a * b)



# this starter code should work with either python or python3
if __name__ == "__main__":
    driver()