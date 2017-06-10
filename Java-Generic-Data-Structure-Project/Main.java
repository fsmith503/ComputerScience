
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
		

