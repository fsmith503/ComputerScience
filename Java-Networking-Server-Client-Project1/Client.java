import java.io.IOException;
import java.io.ObjectInputStream;
import java.io.ObjectOutputStream;
import java.net.InetAddress;
import java.net.ServerSocket;
import java.net.Socket;
import java.util.ArrayList;
import java.util.Scanner; //program uses class Scanner
//when testing always run server first

public class Client {
	private static final int PORT = 1335;
	public static void main(String[] args) {
		System.out.println("running client!");
		Socket socket = null;
		ObjectOutputStream outputStream = null;
		ObjectInputStream inputStream = null;
		try {
			InetAddress address = InetAddress.getLocalHost();
			socket = new Socket(address, PORT);
			System.out.println("socket created");
			System.out.print("Please enter an list of integers, enter ! to quit:");
			Scanner string_take = new Scanner(System.in);
			String num_string = string_take.next();
			ArrayList<Integer> String_Array_List = new ArrayList<Integer>();
			while (num_string.contains("!") == false ) {
				int result = Integer.parseInt(num_string);
				String_Array_List.add(result);	
				System.out.println();
				System.out.print("Please enter another integer:");
				num_string = string_take.next();// takes next number from user
				}
			// Always flush an object output stream preemptively (see documents).
			System.out.println("Send:" + " " + String_Array_List);
			outputStream = new ObjectOutputStream(socket.getOutputStream());
			outputStream.writeObject(String_Array_List);
			outputStream.flush();
			inputStream = new ObjectInputStream(socket.getInputStream());			
			ArrayList<Integer> message = null;
			try{
			message = (ArrayList<Integer>) inputStream.readObject();
			}
			catch (ClassNotFoundException e){
			}
			System.out.println("Recieve:" + " " + message.toString());
		} 
		catch (IOException ex) {
			ex.printStackTrace();
		} 
		finally {
			// Close resources in finally block so that they
			// get closed even if we hit an exception above.
			try {
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
		System.out.println("client finished");
	}
}
