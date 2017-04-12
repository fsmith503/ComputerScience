// Franklin Smith
// Project 1
// My Java program that calculates the sum of a list of positive integers entered by the user.
// You will repeatedly prompt the user to enter an integer and use special integer values to
// determine when to print the sum, clear the sum, and quit the application. Your program
// should:
//  Display text asking the user to enter an integer. You should indicate to the user that
// entering -3 will print the current sum, -2 will reset the sum to 0, and -1 will quit the application.
// For example:
// Enter a positive integer (-3 to print, -2 to reset, -1 to quit):

import java.util.Scanner; //program uses class Scanner

public class Project_1
{
	//main method begins execution of Java application
	public static void main(String[] args)
	{
		// create a Scanner to obtain input from the command window
		System.out.print("Please enter an integer( -3 to print, -2 to reset, -1 to quit):");
		Scanner sum_take = new Scanner(System.in);
		int num = sum_take.nextInt();
		
		int k = 0;

		while (num != -1) {
			if (num == -3){
				System.out.print("Sum:" + k);
				System.out.println();
				System.out.print("Please enter another integer:");
				num = sum_take.nextInt();// takes next number from user
			}
			else if (num == -2){
				k = 0;
				System.out.print(k);
				System.out.println();
				System.out.print("Please enter another integer:");
				num = sum_take.nextInt();// takes next number from user
			}
			else if (num > 0){
				k += num;
				System.out.print("Please enter another integer:");
				num = sum_take.nextInt();// takes next number from user
			}
			else if (num < 0 || num < -3){
				System.out.print("Please enter another intger:");
			}
		}	
		//System.out.println(arr.length);
		if (num == -1){
			System.out.print(k);
			System.out.println();
			System.exit(0);
		}
		sum_take.close();
	}
}
