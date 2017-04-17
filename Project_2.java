//Franklin Smith

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
