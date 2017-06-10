import java.io.IOException;
import java.io.ObjectInputStream;
import java.io.ObjectOutputStream;
import java.net.InetAddress;
import java.net.ServerSocket;
import java.net.Socket;
import java.util.ArrayList;
import java.util.Random;
//when testing always run server first
public class ECHelper implements Runnable
{
	private String name_var;
	private ArrayList<Integer> String_Array_List = new ArrayList<Integer>();
	private static final int PORT = 1600;
	public ECHelper( String name) 
	{
		name_var = name;
	}	
	@Override
	public void run(){
		System.out.println("running client!");
		Socket socket = null;
		ObjectOutputStream outputStream = null;
		ObjectInputStream inputStream = null;
		try {
			InetAddress address = InetAddress.getLocalHost();
			socket = new Socket(address, PORT);
			outputStream = new ObjectOutputStream(socket.getOutputStream());
			inputStream = new ObjectInputStream(socket.getInputStream());	
			System.out.println("socket created");
			while(true){// infinite loop starts here, checked this loop and it works
				ArrayList<Integer> String_Array_List = new ArrayList<Integer>();
				
				Thread.sleep(1000); //sleep for one second here
				
				
				if (Main.sending) {
					//System.out.println("if statement test"); // worked
					for(int i = 0; i < 5; i++){
						//System.out.println("5 loop test");
						//ArrayList<Integer> String_Array_List = new ArrayList<Integer>();
						Random rand = new Random();
						int n = rand.nextInt(98) + 2;
						//100 is the maximum and the 2 is your minimum
						String_Array_List.add(n);
					}	
						
						System.out.println("Send:" + " " + String_Array_List);
						//outputStream = new ObjectOutputStream(socket.getOutputStream());
						//System.out.println("write object test print");
						//System.out.println(String_Array_List);
						outputStream.writeObject(String_Array_List);
						String_Array_List.clear();
						outputStream.flush();
						
						try{
							//inputStream = new ObjectInputStream(socket.getInputStream());	
							ArrayList<Integer> message = null;
							message = (ArrayList<Integer>) inputStream.readObject();
							System.out.println("Recieve:" + " " + message.toString());
							/*
							try {
								Thread.sleep(1000); //sleep for one second here
							} catch (InterruptedException e1) {
								// TODO Auto-generated catch block
								e1.printStackTrace();
							}
							*/
						}// end of try block
						catch (ClassNotFoundException e){
						}// end of catch block
					//} // end of for loop (5) iterations
				}// end of if Main.sending == true if statement
				if (Main.hash_input == true){
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
						finally {
						}
						System.out.println("client finished");
						break;
				}// end of if statement
		
		}// end of infinite for loop		
		}// end of try block
		catch (IOException | InterruptedException ex) {
			ex.printStackTrace();
		}// end of catch block
	}// end of run method
}//end of ECHelper class


