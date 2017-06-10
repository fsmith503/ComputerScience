import java.util.Collection;
import java.util.Iterator;
import java.util.Set;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.Comparator;
import java.util.HashMap;
import java.util.Map.Entry;

//I used the "HashMap sorting by value"
//example provided on the course web site as a starter template for this project
// I used the Array List and Set method definitions as a source for guidance on this 
// project which are hosted at these links below 
// https://docs.oracle.com/javase/7/docs/api/java/util/Set.html
// https://docs.oracle.com/javase/7/docs/api/java/util/ArrayList.html


public class OccurenceSet<T> implements Set<T> {
	HashMap<T, Integer> hmap = new HashMap<T, Integer>();
	@Override
	public boolean add(T arg0) {
		boolean temp1 = false;
		if(hmap.containsKey(arg0) == true){
			int temp = hmap.get(arg0);
			hmap.put(arg0, temp + 1);
			temp1 = true;
		}
		else{
			hmap.put(arg0, 1);
		}
		// TODO Auto-generated method stub
		return temp1;
	} //end of add method

	@Override
	public boolean addAll(Collection<? extends T> c) {
		int temp2 = 0;
		boolean temp1 = false;
		for(T k: c){
			temp1 = add((T) k);
			if(temp1 == false){
				temp2++;			
			}
		}
		if(temp2 > 0){
			temp1 = true;	
		}
		// TODO Auto-generated method stub
		return temp1;
	} // end of addAll method

	@Override
	public void clear() {
		hmap.clear();
		// TODO Auto-generated method stub
	} // end of clear method

	@Override
	public boolean contains(Object o) {
		boolean temp1 = true;
		temp1 = hmap.containsKey(0);
		// TODO Auto-generated method stub
		return temp1;
	} // end of contains method

	@Override
	public boolean containsAll(Collection<?> c) {
		boolean temp1 = true;
		for(Object key: c){
			if(hmap.containsKey(key) == true){
				temp1 = true;// do nothing
			}
			else{
				temp1 = false;
				return temp1;
			}
		}return temp1;
		// TODO Auto-generated method stub
	} // end of containsAll method

	@Override
	public boolean isEmpty() {
		boolean temp1 = true;
		if(hmap.size() == 0){
			temp1 = true;
		}
		return temp1;
		// TODO Auto-generated method stub
	} // end of isEmpty method

	@Override
	public Iterator<T> iterator() {
		java.util.Set<Entry<T, Integer>> tempSet = hmap.entrySet();
		ArrayList<Entry<T, Integer>> temp_list = new ArrayList<>(tempSet);
		Collections.sort(temp_list,
				new Comparator<Entry<T,Integer>>() {
			@Override
			public int compare(Entry<T, Integer> item1,Entry<T, Integer> item2) {
				return item1.getValue().compareTo(item2.getValue());
			}
		});
		Iterator<T> iterator1 = new Iterator<T>(){
			int counter_var = 0;
			public void remove(){
				temp_list.remove(counter_var);
			}
			@SuppressWarnings("unchecked")
			public T next() {
				return (T) temp_list.get(counter_var++);
			}
			public boolean hasNext(){
				return counter_var < temp_list.size();
			}	
		};
		// TODO Auto-generated method stub
		return iterator1;	
	} // end of iterator method

	@Override
	public boolean remove(Object o) {
		boolean temp1 = true;
		if(hmap.get(o) != null){
			hmap.remove(o);
		}
		else{
			temp1 = false;
		}
		// TODO Auto-generated method stub
		return temp1;
	} // end of remove method

	@Override
	public boolean removeAll(Collection<?> c) {
		boolean temp1 = false;
		for(Object k :c){
			if(hmap.get(k)!= null){
				hmap.remove(k);
				temp1 = true;
			}
			else {
				temp1 = false;
			}	
		}
		// TODO Auto-generated method stub
		return temp1;
	} // end of removeAll method

	@Override
	public boolean retainAll(Collection<?> l) {
		Set<T> hmap_key_set = hmap.keySet();
		boolean temp1 = false;
		ArrayList<T> hash_map_key_set_list = new ArrayList<T>(hmap_key_set);
		for(T k: hash_map_key_set_list){
			if(l.contains(k) == false){
				remove(k);
				temp1 = true;
			}
		}
		// TODO Auto-generated method stub
		return temp1;
	} // end of retainAll method

	@Override
	public int size() {
		return hmap.size();
		// TODO Auto-generated method stub
	} // end of size method

	@SuppressWarnings("unchecked")
	@Override
	public Object[] toArray() {
		//T[] keys = (T[]) new Object [hmap.size()];
				Object[] finalRay = new Object[hmap.size()];
				int temp_var = 0;
				Iterator<T> iterator1 = iterator();
				while(iterator1.hasNext()) {
					finalRay[temp_var] = iterator1.next();
					finalRay[temp_var] = ((Entry<T, Integer>) finalRay[temp_var]).getKey();
					temp_var++;
				}
				return finalRay;
		// TODO Auto-generated method stub
	} // end of toArray method

	public String toString(){
		Object[] temp_array = toArray();
		String[] input_var = new String[temp_array.length];
		int len = temp_array.length;
		for ( int k = 0; k < len; k++){
			input_var[k] = temp_array[k].toString();
		}
		return Arrays.toString(input_var);
	} // end of to string method
	
	@SuppressWarnings("hiding")
	@Override
	public <T> T[] toArray(T[] a) {
		Arrays.sort(a);
		return a;
		// TODO Auto-generated method stub
	} // end of toArray method
} // end of OccurenceSet<T> class