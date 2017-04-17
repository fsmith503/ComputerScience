//Franklin Smith
/*
1.	I wrote a java program that prompts the user for an integer array length and a double-precision array density.
I used it to create the arrays for experiement. I caught exceptions due to user entering unparsable input and prompting them
to reenter the value(s).
I also prompted the user to reenter the values if theyre outside of expected range.

2.	This is a method that takes an int length and a double array ensity and returns an array of type int.

3.	This method takes an int length and an array density of type double as arguments and returns a new Array list which
represents a sparse array.

4. 	This Method takes a dense array as an argument and returns a new equivalent sparse array.

5. 	This method takes a sparse array and an integer length as arguments and returns a new equivalent dens array.

6. 	This method takes a sparse array as an argument and prints max value in the array, along with the original index value in the array.

7. 	This method uses the system.nanoTime() method to reord amount of time taken to run each of the above methods.





*/

//Franklin Smith

//package project2;

import java.util.ArrayList;
import java.util.Random;
import java.util.Scanner;
import java.util.InputMismatchException; 

/**********************************************************************/
/*#2*/
/**********************************************************************/

public class project2 {
	private static int[] dense(int length, double density){//#2
		int densearray[] = new int[length];
		
		Random numdouble = new Random();
		Random numint = new Random();
		for(int counter = 0; counter < length; counter++){
			int ranint = numint.nextInt((1000000 - 0) + 1) + 0;
			double randoub = numdouble.nextDouble()*(1 - 0) + 0;
			
			if(randoub > density){
				densearray[counter] = 0;
			}
			else{
				densearray[counter] = ranint;
			}
		}
		return densearray;
	}
	
	private static int denseLength(int[] dense){
		int length = 0;
		for(int index = 0; index < dense.length; index++){
			if (dense[index] > 0){
				length++;
			}
		}
		return length;
	}
	
	/**********************************************************************/
	/*#3*/
	/**********************************************************************/
	
	private static ArrayList<int[]> sparceArray(int length, double density){//#3

		Random numdouble = new Random();
		Random numint = new Random();
		ArrayList<int []> sparse = new ArrayList<int []>();
		for(int counter = 0; counter < length; counter++){
			
			int ranint = numint.nextInt((1000000 - 0) + 1) + 0;
			double randoub = numdouble.nextDouble()*(1 - 0) + 0;
			
			if(randoub < density){
				
				int temp[] = new int[2];
				temp[0] = counter;
				temp[1] = ranint;
				sparse.add(temp);
			}
		}
		return sparse;

}
	/**********************************************************************/
	/*#4*/
	/**********************************************************************/
	
	private static ArrayList<int[]> denseToSparse(int[] dense){//#4
		ArrayList<int[]> sparse = new ArrayList<int []>();
		for(int counter = 0; counter < dense.length; counter++){
			if(dense[counter] > 0)
			{
				int temp[] = new int[2];
				temp[0] = counter;
				temp[1] = dense[counter];
				sparse.add(temp);
			}
		}
		return sparse;
	}
	
	/**********************************************************************/
	/*#6*/
	/**********************************************************************/
		
	public static int printMaxDense(int[] max){//#6
		int maximum = 0;
		for(int counter = 0; counter < max.length; counter++){
			if(max[counter] > maximum){
				maximum = max[counter];
			}
		}
		return maximum;
	}
	
	public static int printMaxDensePosition(int[] max){
		int maximum = 0;
		int maxCounter = 0;
		for(int counter = 0; counter < max.length; counter++){
			if(max[counter] > maximum){
				maximum = max[counter];
				maxCounter = counter;
			}
			
		}
		return maxCounter;
	}
	
	/**********************************************************************/
	/*#5*/
	/**********************************************************************/
	
	public static int[] sparseToDense (ArrayList<int[]> sparse){//#5
		int[] outArray = new int[sparse.get(sparse.size()-1)[0] + 1];
		
		for(int[] a : sparse){
			int index = a[0];
			int value = a[1];
			outArray[index] = value;
		}
		return outArray;
	}
	
		
	/**********************************************************************/
	/*#7*/
	/**********************************************************************/
	
	public static int maxSparce(ArrayList <int[]> sparse){//#7
		int maxNumber = 0;
		for(int[] a : sparse){
			if (a[1] > maxNumber){
				maxNumber = a[1];
			}
		}
		return maxNumber;

	}
	public static int maxSparcePosition(ArrayList <int[]> sparse){
		int[] outArray = new int[sparse.get(sparse.size()-1)[0] + 1];
		int maxNumber = 0;
		int maxIndex = 0;
		for(int[] a : sparse){
			int index = a[0];
			int value = a[1];
			outArray[index] = value;
		}
		for(int index = 0; index < sparse.get(sparse.size()-1)[0] + 1; index++){
			if(outArray[index] > maxNumber){
				maxNumber = outArray[index];
				maxIndex = index;
			}
		}
		return maxIndex;
	}

	
	/**************************************************************************/
	/*#1*/
	/**************************************************************************/
	
	public static void main(String[] args) {//#1
		Scanner scanner = new Scanner(System.in);
		double density = 0;
		int length = 0;
		
		boolean check = true;
		
		try{
		System.out.print("Enter array length: ");
		
		length = scanner.nextInt();
		}
		catch(InputMismatchException exception){
		while(!scanner.hasNextInt()){
			scanner.next();
			System.out.print("This is not an integer, try again:");
			}
		length = scanner.nextInt();
		}
		
		try{
		System.out.print("Enter density: ");
		while(check)
		{
			while(!scanner.hasNextDouble()){
				scanner.next();
				System.out.print("This is not a double value, try again:");
			}
			density = scanner.nextDouble();
			while(density > 1.0 || density < 0.0){
				
				System.out.print("Please enter a number between 0 and 1: ");
				density = scanner.nextDouble();
			}
			if(density <= 1.0 && density >= 0)
				check = false;
		}
		
		}
		catch(InputMismatchException exception){
			while(!scanner.hasNextDouble()){
				scanner.next();
				System.out.print("This is not a double value, try again:");
			}
			density = scanner.nextDouble();
		}
		scanner.close();
		
		
		
		/**********************************************************************/
		/*#8*/
		/**********************************************************************/
		
		ArrayList<int []> SA = sparceArray(length, density);
		
		double beforeTime = System.nanoTime();
		int[] DA = dense(length, density);
		double afterTime = System.nanoTime();
		double totalTime = afterTime - beforeTime;
		System.out.println("Create dense length: " + length + " time: " + totalTime / 1000000);
		
		double beforeTime2 = System.nanoTime();
		denseToSparse(DA);
		double afterTime2 = System.nanoTime();
		double totalTime2 = afterTime2 - beforeTime2;
		System.out.println("Convert to sparse length: " + denseLength(DA) + " time: " + totalTime2 / 1000000);
		
		double beforeTime3 = System.nanoTime();
		ArrayList<int []> STD = sparceArray(length, density);
		double afterTime3 = System.nanoTime();
		double totalTime3 = afterTime3 - beforeTime3;
		System.out.println("create sparse length: " + SA.size() + " time: " + totalTime3 / 1000000);
		
		double beforeTime4 = System.nanoTime();
		sparseToDense(STD);
		double afterTime4 = System.nanoTime();
		double totalTime4 = afterTime4 - beforeTime4;
		System.out.println("convert to dense length: " + SA.get(SA.size()-1)[0] + " time: " + totalTime4 / 1000000);

		System.out.println("find max (dense): " + printMaxDense(DA) + " at: " + printMaxDensePosition(DA));
		
		double beforeTime5 = System.nanoTime();
		printMaxDense(DA);
		double afterTime5 = System.nanoTime();
		double totalTime5 = afterTime5 - beforeTime5;
		System.out.println("dense find time: " + totalTime5 / 1000000);
		
		System.out.println("find max (sparse): " + maxSparce(SA) + " at: " + maxSparcePosition(SA));
		
		double beforeTime6 = System.nanoTime();
		maxSparce(SA);
		double afterTime6 = System.nanoTime();
		double totalTime6 = afterTime6 - beforeTime6;
		System.out.println("sparse find time: " + totalTime6 / 1000000);
		

	}	
}
		
		
		
		
		



