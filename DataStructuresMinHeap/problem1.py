"""
Franklin Smith CIS 313 Problem1.py
"""
import sys
def driver():
    with open(sys.argv[1]) as f:
    	x,y = f.readline().strip().split()
    	have_num = int(x)
    	want_num = int(y)
    	have_words = f.readline().strip().split()
    	letter_words = f.readline().strip().split()
   	word_count = [have_num, want_num]
    want_counter = 0 
    if have_num < want_num:
      print("NO")
      sys.exit()
    dict = {}
    for i in have_words:
      if i in dict:
        dict[i] = dict[i]+1
      else:
        dict[i] = 1
    for w in letter_words:
      if w in dict:
        if dict[w] <= 0:
          print("NO")
          sys.exit()
        dict[w] = dict[w]-1
        want_counter += 1
      else:
        print("NO")
        sys.exit()
    if want_counter == want_num:
      print("YES")
      sys.exit()

if __name__ == "__main__":
    driver()