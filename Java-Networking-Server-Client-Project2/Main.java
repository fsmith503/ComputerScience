import java.util.Scanner;
import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;

/*
I wrote a client which generates a list of 5 integers randomly in the
range [2,100), prints them, sends them to the server, and receives and 
prints the list of prime integers contained in the original list. My client
sleeps for 1 second everytime after it revieves and prints the prime integers.
My client keeps repeating this procedure until stopped by inputting "!". In 
order to keep my server responsive, the server doesnt shut down after it 
sends the prime integers back to the client.
 Use "!" to stop and start sending integers to the server, and use "#" to quit 
 the client. My client was able to read inputs while sending or recieving data.
 when you input "#" the client shuts down and quits

*/

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
