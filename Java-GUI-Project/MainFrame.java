//Franklin Smith Project4 MainFrame.java
//"I used the 'Paint with shapes and colors' 
//example provided on the course website as a starter template for this project".

import java.awt.BorderLayout;
import java.awt.Color;
import java.awt.Dimension;
import java.awt.GridLayout;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import javax.swing.JButton;
import javax.swing.JColorChooser;
import javax.swing.JFrame;
import javax.swing.JPanel;

public class MainFrame extends JFrame {
	private final PaintPanel _paintPanel; //sets PaintPanel to private
	
	public MainFrame() {
		super("PAINTING USER INTERFACE BY FRANKLIN SMITH"); //sets text label at the top of the canvas
		setLayout(new BorderLayout());
		_paintPanel = new PaintPanel(); //creates canvas gui window
		_paintPanel.setPreferredSize(new Dimension(400, 400)); //sets dimensions of canvas gui window
		add(_paintPanel, BorderLayout.CENTER); // adds gui canvas to the center
		
		JButton squareButton = new JButton("Square"); //creates button titled "square"
		squareButton.addActionListener(new ActionListener() {  // creates action listener when button is clicked
			@Override
			public void actionPerformed(ActionEvent e) {
				_paintPanel.setShape(PaintPoint.SQUARE_SHAPE); //action performed when button is clicked, changes the shape to square			
			}			
		});
		
		JButton smallButton = new JButton("Small"); // creates button titled "small"
		//Setting pen size for small button to 5
		smallButton.addActionListener(new ActionListener(){ //creates action listener when button is clicked
			@Override
			public void actionPerformed(ActionEvent e){  
				_paintPanel.setSize(5);  //action performed when button is clicked changes the size of the pen to 5
			}
		});
		
		JButton mediumButton = new JButton("Medium"); //creates button titled "medium"
		//Setting pen size for medium button to 10
		mediumButton.addActionListener(new ActionListener(){ //creates action listener when button is clicked
			@Override
			public void actionPerformed(ActionEvent e){
				_paintPanel.setSize(10);  //action performed when button is clicked changes the size of pen to 10
			}
		});
		
		JButton largeButton = new JButton("Large"); //creates button titled "large"
		//Setting pen size for large button to 20
		largeButton.addActionListener(new ActionListener(){ //creates action listener when button is clicked
			@Override
			public void actionPerformed(ActionEvent e){
				_paintPanel.setSize(20);  // action performed when button is clicked changes the size of the pen to 20
			}
		});
		
		JButton circleButton = new JButton("Circle"); //creates button titled "circle"
		circleButton.addActionListener(new ActionListener() { //creates action listener when button is clicked
			@Override
			public void actionPerformed(ActionEvent e) {
				_paintPanel.setShape(PaintPoint.CIRCLE_SHAPE); // action performed when button is clicked changes the shape of the pen to circle		
			}			
		});
		
		JPanel shapeButtonPanel = new JPanel(new GridLayout(1, 2)); // this is the button layout panel for the square and circle buttons
		shapeButtonPanel.add(squareButton);
		shapeButtonPanel.add(circleButton);
		
		JButton chooseColorButton = new JButton("Choose Color"); //creates button titled "choose color"
		chooseColorButton.addActionListener(new ActionListener() {  //creates action listener when button is clicked
			@Override
			public void actionPerformed(ActionEvent e) {
				// MainFrame.this is this for the current MainFrame instance.
				Color color = JColorChooser.showDialog(MainFrame.this, // color chooser comes up
						"Chooser a color!", Color.GREEN);

				// color will be null if the user hit cancelled.
				if (color != null) {
					_paintPanel.setGlobalColor(color);
				}
			}			 
		});
		
		JButton blackColorButton = new JButton("Black");  // creates a button titled "black"
		blackColorButton.addActionListener(new ActionListener() { //creates action listener when button is clicked
			@Override
			public void actionPerformed(ActionEvent e){
				_paintPanel.setGlobalColor(Color.BLACK); // action performed when button is clicked changes the color of the pen to black
			}
		});
			
		JButton greenColorButton = new JButton("Green"); // creates a button titled "green"
		greenColorButton.addActionListener(new ActionListener() { //creates action listener when button is clicked
			@Override
			public void actionPerformed(ActionEvent e){
				_paintPanel.setGlobalColor(Color.GREEN); // action performed when button is clicked changes the color of the pen to green
			
			}
		});
		
		JButton yellowColorButton = new JButton("Yellow"); // creates a button titled "yellow"
		yellowColorButton.addActionListener(new ActionListener() {  //creates action listener when button is clicked
			@Override
			public void actionPerformed(ActionEvent e){
				_paintPanel.setGlobalColor(Color.YELLOW); // action performed when button is clicked changes the color of the pen to yellow
			}
		});
		
		JButton grayColorButton = new JButton("Gray"); //creates a button titled "Gray"
		grayColorButton.addActionListener(new ActionListener() {  //creates action listener when button is clicked
			@Override
			public void actionPerformed(ActionEvent e){
				_paintPanel.setGlobalColor(Color.GRAY); //action performed when button is clicked changes the color of the pen to gray
			}
		});
		
		JButton clearButton = new JButton("Clear"); //creates a button titled "clear"
		//button clears the array list which should clear the canvas
		clearButton.addActionListener(new ActionListener(){ //creates action listener when button is clicked
			@Override
			public void actionPerformed(ActionEvent e){
			_paintPanel._points.clear(); //action performed when the button is clicked clears the array list which contains the points should clear the canvas
			repaint();
			}
		
		});

		JPanel buttonPanel = new JPanel(new GridLayout(4, 1)); //button panel layout 4 rows 1 column for the color button section
		buttonPanel.add(blackColorButton);
		buttonPanel.add(greenColorButton);
		buttonPanel.add(yellowColorButton);
		buttonPanel.add(grayColorButton);
		//buttonPanel.add(shapeButtonPanel); uncomment if want to add shape button!
		//buttonPanel.add(chooseColorButton); uncomment if want to add choose color extra program function
		add(buttonPanel, BorderLayout.WEST); // border layout is WEST so puts buttons on left side border of the GUI
	
		JPanel westbuttonPanel = new JPanel(new GridLayout(4,1)); //button panel layout 4 rows 1 column for the size button section
		westbuttonPanel.add(smallButton);
		westbuttonPanel.add(mediumButton);
		westbuttonPanel.add(largeButton);
		westbuttonPanel.add(clearButton);
		add(westbuttonPanel, BorderLayout.EAST); // border layout is EAST so put buttons on right side border of the GUI
		
	}
}
