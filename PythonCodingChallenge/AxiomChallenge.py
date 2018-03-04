#Franklin Smith
import math

def sum_for_loop(array):
	"""
	Write a function that compute the sum of the 
	numbers in a given list using a for-loop
	"""
	sum = 0
	for i in array:
		sum += i
	return sum

def sum_while_loop(array):
	"""
	Write a function that compute the sum of the 
	numbers in a given list using a while-loop
	"""
	sum = 0
	index = 0
	while index < len(array):
		sum += array[index]
		index += 1
	return(sum)

def sum_recursive(array):
	"""
	Write a function that compute the sum of the 
	numbers in a given list using recursion
	"""
	if len(array) == 0:
		return 0
	else:
		return array[0] + sum_recursive(array[1:]) 

def combine_lists(array1,array2):
	"""
	Write a function that combines two lists by alternatingly taking elements. For example: given 
	the two lists [a, b, c] and [1, 2, 3], the function should return [a, 1, b, 2, c, 3].
	"""
	list = []
	for item1, item2 in zip(array1, array2):
		list.append(item1)
		list.append(item2)   
	return list

def fibonacci(n):
	"""
	Write a function that computes the list of the first 100 Fibonacci 
	numbers. By definition, the first two numbers in the Fibonacci sequence 
	are 0 and 1, and each subsequent number is the sum of the previous two. 
	As an example, here are the first 10 Fibonnaci numbers: 0, 1, 1, 2, 3, 5, 8, 13, 21, and 34
	"""
	f = []
	a = 0
	b = 1
	if n == 0 or n == 1:
		print n
	else:
		f.append(a)
		f.append(b)
		while len(f) != n:
			temp = a + b
			f.append(temp)
			a = b
			b = temp
	print f    	

def driver():
	input_array = [1,2,3,4,5]
	input_arrayt1 = ["a","b","c"]
	input_arrayt2 = [1,2,3]
	print(sum_for_loop(input_array))
	print(sum_while_loop(input_array))
	print(sum_recursive(input_array))
	print(combine_lists(input_arrayt1,input_arrayt2))
	fibonacci(100)

# this code should work with either python or python3
if __name__ == "__main__":
	driver()