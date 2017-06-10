import java.io.IOException;
import java.io.ObjectInputStream;
import java.io.ObjectOutputStream;
import java.net.ServerSocket;
import java.net.Socket;
import java.util.ArrayList;
//when testing always run server first
public class Server {
	private static final int PORT = 1335;
	static boolean isPrime(int num) {
		 boolean isPrime = true;
		 int factors = 0;
		    for(Integer i=1; i<=num; i++){
		        if(num%i==0){ // ensure that you mod num not i
		        factors++;
		        }
		     }
		    // if factors count is equals to 2 then it is prime number else it's not prime number
		    if(factors == 2){
		        isPrime = true;
		    }    
		    else{
		        isPrime = false;
		    }
		    
		    return isPrime;
	}
	
	public static void main(String[] args) {
		//System.out.println("running server!");
		ServerSocket serverSocket = null;
		Socket socket = null;
		ObjectOutputStream outputStream = null;
		ObjectInputStream inputStream = null;	
		try {
			serverSocket = new ServerSocket(PORT);
			System.out.println("server socket created");
			socket = serverSocket.accept();
			System.out.println("got socket: " + socket);
			//print	the	list of	
			//integers	sent to	the	server,	and	later 
			//print	the	list of	prime integers received from the server.

			// Always flush an object output stream preemptively (see documents).
			outputStream = new ObjectOutputStream(socket.getOutputStream());
			//what i would send back to the client
			outputStream.flush();
			inputStream = new ObjectInputStream(socket.getInputStream());
			//print the list of prime integers sent to the server
			ArrayList<Integer> Input_Array_List = null;
			try{
			Input_Array_List = (ArrayList<Integer>) inputStream.readObject();
			}
			catch (ClassNotFoundException e){
			}
			ArrayList<Integer> Prime_Integer_Array_List = new ArrayList<Integer>();
			for(Integer num: Input_Array_List){
				if(isPrime(num) == true){
					Prime_Integer_Array_List.add(num);
				}
			}
			outputStream.writeObject(Prime_Integer_Array_List);
			outputStream.flush();
		} 
		catch (IOException ex) {
			ex.printStackTrace();
		} 
		finally {
			// Close resources in finally block so that they
			// get closed even if we hit an exception above.
			try {
				if (serverSocket != null) {
					serverSocket.close();
				}
				if (socket != null) {
					socket.close();
				}
				if (outputStream != null) {
					outputStream.close();
				}
				if (inputStream != null) {
					inputStream.close();
				}
			} 
			catch (IOException ex) {
				ex.printStackTrace();
			}
		}
		System.out.println("server finished");
	}
}