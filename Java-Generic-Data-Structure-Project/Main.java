/*
The goal of this assignment is to provide me exposure to building a new 
generic data structure. Specifically, this project involved building
a new Set structure that maintains the "add" counts of its unique elements,
so that they can be iterated in sorted order with respect to how many times 
they've been added to the set. The Set implementation will be optimized for 
efficient add/remove/contains over efficient iteration. 

I Created a new class OccurrenceSet<T> that implements Set<T>. My 
OccurrenceSet implementation should created and maintained a HashMap<T, Integer>; 
doing so will allow me to easily track the integer "add" count for each element 
in the set. All methods functioned as specified in the Set documentation. 

The add and addAll methods will keep track of how many times an 
element has been added to the set. I am optimizing for efficient add, so add 
should be 0(1) and addAll should be 0(n) for n added elements. The remove, 
removeAll, and retainAll methods remove the necessary elements from the set 
completely. I am optimizing for efficient 
remove, so remove should be 0(1) and removeAll should be 0(n) for n removed elements.

The contains and containsAll methods ooperate in 0(1) 
and 0(n) time (i.e., for n query elements), respectively. The size method returns
the number of unique elements currently in the set (i.e., not considering "add" counts). 
This method is 0(1). The clear and isEmpty methods behave as documented.


The iterator and toArray methods return an Iterator or array, respectively, with 
elements sorted by their "add" counts in ascending order. I am optimizing for efficient 
add/contains over iteration, but these methods are still 0(n Ig n). 

I Added a toString method that returns a string representation of the elements in the list 
in sorted order (i.e., ascending with respect to their "add" counts). This method is 0(n Ig n). 

I Created a Main class that creates a few OccurrenceSets of various types to test 
the functionality of your new data structure. 
*/

public class Main{
	
	public static void main(String[] args){
		integer_set_test(args);
		string_set_test(args);
	}
	public static void integer_set_test(String[] args){
		OccurenceSet<Integer> intSet = new OccurenceSet<Integer>();
		intSet.add(1);
		intSet.add(3);
		intSet.add(5);
		intSet.add(5);
		intSet.add(3);
		intSet.add(3);
		intSet.add(3);
		intSet.remove(3);
		System.out.println(intSet.contains(3));
		System.out.println(intSet.toString());
		System.out.println(intSet.contains(2));
		System.out.println(intSet.size());
		intSet.clear();
		System.out.println(intSet.isEmpty());
		System.out.println(intSet.toArray());
		
	}
		
	public static void string_set_test(String[] args){
		OccurenceSet<String> stringSet = new OccurenceSet<String>();
		stringSet.add("hello");
		stringSet.add("hello");
		stringSet.add("world");
		stringSet.add("world");
		stringSet.add("world");
		stringSet.add("here");
		System.out.println(stringSet.toString());
		
		}
	}
		

