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
import java.util.Scanner; //program uses class Scanner

public class Project_2 {
	
	public static void main(String[] args)
	{
		System.out.print("Please enter an integer array length:"); //prompting user for array length input
		Scanner take1 = new Scanner (System.in);
		int len = take1.nextInt(); //assigning length variable to input given
		try {
		int[]ray = new int[len]; //creating array of variable length
		System.out.print(ray); //prints array
		System.out.print(ray.length); //printing the length of an array
		System.out.println(); //prints blank line
		}
		catch(NegativeArraySizeException e)
		{
		System.out.print("Please re-enter an array length within the expected range:");
		int raylength = take1.nextInt(); //takes next integer which should be array length
		if (raylength >= 1){
		int[]ray = new int[raylength];  
		System.out.print(ray); //prints array
		System.out.print(ray.length); //prints array length
		}
		}
		double density = 0.0;
		System.out.print("Please Enter a double precision aray density:"); // prompting user for density value
		density = take1.nextDouble(); // gets density input from user
		if (density > 0 && density <= 1 ){		
		System.out.print(density);
		System.out.println();
		}
		else{
		System.out.print("Please re-enter a double precision array density amount within the expected range(0.0, 1.0):");
		density = take1.nextDouble();
		System.out.print(density);
		System.out.println();
		}	
	}
	 /*
	  	[10]	Write	a	method which	takes	an	integer	length	and	
	  	an array	density	of	type	double	as	
		arguments	and	returns	a	new	array	of	
		type	int representing	a	dense	array.
	  
	  */
	public static void func1(int a, double b)
	{
	//int[]ray2 = new int[a]; //making array of length integer a	
	//Array{int}(a);
	}
}
