import sys
import random

def generate_input():
    with open('problem3.largeinput', 'w') as f:
        f.write("1000000\n")
        for i in range (999997):
            a = str(random.randint(-100000,100000))
            f.write("insert " + a)
            f.write("\n")
        f.write("inprint")
        f.write("\n")
        f.write("preprint")
        f.write("\n")
        f.write("postprint")
        f.write("\n")
            
def generate_output():
    with open('problem1.largeoutput', 'w') as f:
        res = [str(1) for _ in range(1000)]
        f.write(' '.join(res) + '\n')
        for _ in range(1000):
            f.write(str(1) + '\n')
        f.write('Empty\n')


if __name__ == '__main__':
    if sys.argv[1] == 'input':
        generate_input()
    elif sys.argv[1] == 'output':
        generate_output()