import java.util.Scanner;
import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;

public class Main {
	static String num_string;
	public static boolean sending = false;
	public static boolean hash_input = false;
	public static void main(String[] Args){
		ExecutorService executor = Executors.newCachedThreadPool();
		executor.submit(new ECHelper("Helper1"));
		Scanner string_take = new Scanner(System.in);
		
			
		while(true){ //infinite loop starts here
			//System.out.println("testing while loop");// only ran once??
			if(!sending)
				System.out.println("Enter '!' to start and stop, '#' to quit:");
			
			String num_string = string_take.next();
			
			if (num_string.contains("!"))  
				sending = !sending;  // or !sending or true
				//System.out.println("Boolean flipped");
			
			//System.out.println("First if executed");
			if (num_string.contains("#")){
				hash_input = true;
				//System.out.println("Breaking out");
				break;
			}
			
			
		}
		
		executor.shutdown();
		string_take.close();
	}
}


/* import java.util.Scanner;
import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;

public class Main {
	static String num_string;
	static boolean sending = false;
	static boolean hash_input = false;
	public static void main(String[] Args){
		ExecutorService executor = Executors.newCachedThreadPool();
		executor.submit(new ECHelper("Helper1"));
		Scanner string_take = new Scanner(System.in);
		while(true){
			System.out.println("Enter '!' to start and stop, '#' to quit:");
			String num_string = string_take.next();
			while(true){ //infinite loop starts here
				//System.out.println("testing while loop");// only ran once??
				if (num_string.contains("!") == true) { 
					sending = !sending;  // or !sending or true
					//System.out.println("Boolean flipped");
				}
				//System.out.println("First if executed");
				if (num_string.contains("#") == true){
					hash_input = true;
					//System.out.println("Breaking out");
					break;
				}
			}
			if (num_string.contains("#") == true){
				break;
			}
		}
		executor.shutdown();
		string_take.close();
	}
}
*/