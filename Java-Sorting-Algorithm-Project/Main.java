import java.io.IOException;
import java.nio.file.DirectoryStream;
import java.nio.file.Files;
import java.nio.file.Path;
import java.nio.file.Paths;
import java.util.ArrayList;
import java.util.Scanner;
import java.util.concurrent.TimeUnit;
import java.io.*;
import java.util.*;

public class Main {

	public static void main(String[] args){
		File file = new File("Assignment5_phonebook.txt");
		//File file = new File("smaller.txt");
		ArrayList<PhoneBookEntry> temp_list = new ArrayList<PhoneBookEntry>(); 
		try{
			Scanner sc1 = new Scanner(file);
			while(sc1.hasNextLine()){
				if(sc1.hasNext()){	
					String pn = sc1.next();
					String ln = sc1.next();
					String fn = sc1.next();
					temp_list.add(new PhoneBookEntry(fn,ln,pn));
				}
			}
		}
		catch(FileNotFoundException e){
		e.printStackTrace();
		}
		//test cases
		//ArrayList<PhoneBookEntry> sorted_list1 = merge_sort(temp_list);
		//System.out.println("Merge sort completed");
		//System.out.print(alphabetical(sorted_list1));
		//System.out.print(alphabetical(temp_list));
		//write_out(temp_list, "new");
		//selection_sort(temp_list); //selection_sort test
		//sorting_time();
	} //end of main method
		
	public static void write_out(ArrayList<PhoneBookEntry> input_list,String input){
		try{
			BufferedWriter out = new BufferedWriter(new FileWriter("output.txt"));	
			for(int k = 0; k < input_list.size(); k++){
				String f = input_list.get(k).get_first_name();
				String l = input_list.get(k).get_last_name();
				if (f.contains(input) || l.contains(input)){ //took out f.toLowerCase()
					out.write(input_list.get(k).get_number() + " " + input_list.get(k).get_last_name() + " " + input_list.get(k).get_first_name()+ "\n");
				}
			}
		out.close();
		}
		catch(IOException e){
			System.out.println("Exception");
		}
	} //end of write_out method
	
	  public static ArrayList<PhoneBookEntry> selection_sort(ArrayList<PhoneBookEntry> RayList){
		ArrayList<PhoneBookEntry> temp_list3 = new ArrayList<PhoneBookEntry>(); //makes new array list of type phone book entry
		temp_list3.addAll(RayList);
			for(int i = 0; i < temp_list3.size(); i++){
				int small_index = smallest(temp_list3, i);
				PhoneBookEntry temp = temp_list3.get(small_index);
				temp_list3.set(small_index, temp_list3.get(i));
				temp_list3.set(i, temp);
			}
			return temp_list3;
	   } // end of selection_sort method
	
		public static int smallest(ArrayList<PhoneBookEntry> temp4, int start_pos){
			int smallest = start_pos;
			for(int k = start_pos; k < temp4.size(); k++){
				String var1 = temp4.get(k).get_sorting_name();
				String var2 = temp4.get(smallest).get_sorting_name();
				if((var1.compareTo(var2)) < 0){
					smallest = k;
				}
			}
			return smallest; //index position of smallest element in list
			} // end of smallest method which is a helper method for selection sort
		
		public static ArrayList<PhoneBookEntry> merge_sort(ArrayList<PhoneBookEntry> RayList1){
			if(RayList1.size() <= 1 ){
				return RayList1;
			}
			ArrayList<PhoneBookEntry> temp_list4 = new ArrayList<PhoneBookEntry>(); //makes new array list of type phone book entry
			temp_list4.addAll(RayList1); //adds items from input array list to new list we can work on
			return merge_work(temp_list4);
		} //end of merge_sort	
		
		public static ArrayList<PhoneBookEntry> merge_work(ArrayList<PhoneBookEntry> merge_list){
			
			//chop array in half
			int k = merge_list.size();
			int mid = k/2;
			if (k<2){
				return merge_list;	
			}
			ArrayList<PhoneBookEntry> left_list = new ArrayList<PhoneBookEntry>();
			ArrayList<PhoneBookEntry> right_list = new ArrayList<PhoneBookEntry>();
			for(int i = 0; i <= (k-1); i++){
				if(i < mid){
					left_list.add(merge_list.get(i));
				}
				else if(i == mid || mid < i){
					right_list.add(merge_list.get(i));
				}
			}
			ArrayList<PhoneBookEntry> sorted_left = merge_work(left_list);
			ArrayList<PhoneBookEntry> sorted_right = merge_work(right_list);
			ArrayList<PhoneBookEntry> sorted_list = merge_combine(sorted_left,sorted_right);
			return sorted_list;
		}// end of merge_work
		
		public static ArrayList<PhoneBookEntry> merge_combine(ArrayList<PhoneBookEntry> list1, ArrayList<PhoneBookEntry> list2){
			int list1_index = 0;
			int list2_index = 0;
			ArrayList<PhoneBookEntry> final_list = new ArrayList<PhoneBookEntry>();
			while(list1_index != list1.size() && list2_index != list2.size()){
				String L1Last_name = list1.get(list1_index).get_last_name();
				String L2Last_name = list2.get(list2_index).get_last_name();
				int compare_result = L1Last_name.compareTo(L2Last_name); 
				if(compare_result < 0 ){
					// L1Last_name < L2Last_name
					final_list.add(list1.get(list1_index));
					list1_index = list1_index + 1;
				}
				if(compare_result == 0 ){
					// L1Last_name == L2Last_name
					final_list.add(list1.get(list1_index));
					list1_index = list1_index + 1;
				}
				if(compare_result > 0 ){
					// L1Last_name > L2Last_name
					final_list.add(list2.get(list2_index));
					list2_index = list2_index + 1;	
				}
			}
			if(list1_index != list1.size()){
				//Finish out list 1
				for (; list1_index < list1.size();list1_index++){
					final_list.add(list1.get(list1_index));
				}
			}
			else{
				for (; list2_index < list2.size();list2_index++){
					final_list.add(list2.get(list2_index));
				}
				//Finish out list 2
			} 
			return final_list;
		} //end of merge combine method
		
		public static Boolean alphabetical(ArrayList<PhoneBookEntry> input_list){
			int index_count_1 = 0;
			int index_count_2 = 1;
			Boolean result = true;
			int k = input_list.size();
			int i = 0;
			while(i < k-1){
				int compare = input_list.get(index_count_1).get_last_name().compareTo(input_list.get(index_count_2).get_last_name());
				if(compare < 0){
				// a comes before b
				index_count_1++;
				index_count_2++;
				i++;
				result = true;
				}
				if(compare == 0){
				// a is equal to b
				index_count_1++;
				index_count_2++;
				i++;
				result = true;
					
				}
				if(compare > 0){
				// a comes after b
				result = false;
				break;
				}
				compare = 0;
			}
			return result;
		} // end of alphabetical method
		
		public static void sorting_time(){
			File file = new File("Assignment5_phonebook.txt");
			//File file = new File("smaller.txt");
			ArrayList<PhoneBookEntry> temp_list = new ArrayList<PhoneBookEntry>(); 
			try{
				Scanner sc1 = new Scanner(file);
				while(sc1.hasNextLine()){
					if(sc1.hasNext()){	
						String pn = sc1.next();
						String ln = sc1.next();
						String fn = sc1.next();
						temp_list.add(new PhoneBookEntry(fn,ln,pn));
					}
				}
			}
			catch(FileNotFoundException e){
			e.printStackTrace();
			}
			double startTime = System.nanoTime();
			selection_sort(temp_list);
			double endTime = System.nanoTime();
			double startTime1 = System.nanoTime();
			merge_sort(temp_list);
			double endTime1 = System.nanoTime();
			System.out.println("Selection Sort:" + ((endTime - startTime) / 100000000));
			System.out.println("Merge Sort:" + ((endTime1 - startTime1) / 100000000));
		} //end of sorting_time method
} //end of Main class




