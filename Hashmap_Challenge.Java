
import java.util.*;
import java.util.Collection;
import java.util.Iterator;
import java.util.Set;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.Comparator;
import java.util.HashMap;
import java.util.Map.Entry;

// you can write to stdout for debugging purposes, e.g.
// System.out.println("this is a debug message");

class Solution {
    public int solution(int[] T) {
    int[] temp = new int[T.length];
    temp = T.clone();
    HashMap<Integer, Integer> hmap = new HashMap<Integer, Integer>();
    for(int i = 0; i < T.length; i++){
        if(hmap.containsKey(T[i]) == true){
			int val = hmap.get(T[i]);
			hmap.put(T[i], val + 1);
		}
		else{
			hmap.put(T[i], 1);
		}
    } // end of hash map adding
    for(int k = 0; k < temp.length; k++){
        if(hmap.containsKey(T[k]) == true){
            if(hmap.get(T[k]) > 1 && hmap.size() > (T.length/2)){
                hmap.remove(T[k]);
            }
        }    
    }// end of for loop
    return hmap.size();
    }// solution method  write your code in Java SE 8   
} // end of class solution
