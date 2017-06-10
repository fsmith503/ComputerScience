//Franklin Smith Project4 Main Java
//I used the 'Paint with shapes and colors 
//example provided on the course website as a starter template for this project".

import javax.swing.JFrame;

public class Main {
	public static void main(String[] args) {	
		MainFrame frame = new MainFrame(); //creates GUI
		frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE); //exits on close
		frame.pack();
		frame.setVisible(true); //boolean true sets frame to visible
	}
}