//Franklin Smith Project4 Main Java
//I used the 'Paint with shapes and colors 
//example provided on the course website as a starter template for this project".
/*
In this project I got exposure to Java Swing and I built a user
interface witha mix of standard of custom widgets. In this project
I involved creating a simple interactive paint application.
In this project i made a java application that opens a UI window.

I implemented a class to serve as a template for points to be drawn
to the screen. Each point has a distinct 2D position, color, and size,
so the class has private instance variables to represent this state.

I added a canvas to my window which draws points when the user clicks the 
canvas or drags the mouse on the canvas. My application maintains an 
ArrayList of instances of my point class from the class above, my mouse
listeners create instances of the class and add them to the list while my
implementation of the Jpanel paint Component method should point all instances
in the list to the screen.

I added 4 buttons to my window which allows the user to select the current
point color. This point color affected any points drawn from the time the color
is selected until the time that another color is selected.

I added 3 buttons to my window which allows the user to select the current 
point size. The point size affected any points drawn from the time the size
is selected until the time that another size is selected.

I added a clear button to my frame which when clicked immediately clears 
anything that has been drawn to my canvas.




*/



import javax.swing.JFrame;

public class Main {
	public static void main(String[] args) {	
		MainFrame frame = new MainFrame(); //creates GUI
		frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE); //exits on close
		frame.pack();
		frame.setVisible(true); //boolean true sets frame to visible
	}
}
