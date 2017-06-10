//Franklin Smith Project4 PaintPanel.java
//"I used the 'Paint with shapes and colors' example 
//provided on the course website as a starter template for this project".

import java.awt.Color;
import java.awt.Graphics;
import java.awt.event.MouseAdapter;
import java.awt.event.MouseEvent;
import java.util.ArrayList;

import javax.swing.JPanel;

public class PaintPanel extends JPanel {
	public final ArrayList<PaintPoint> _points; //creating array list of types paint point
	private Color _globalColor;
	private int _currentShape;
	private int _globalSize = 10;
	
	public PaintPanel() {
		_points = new ArrayList<>(); // assigns points to new array list
		_globalColor = Color.BLACK;  // setting global color variable to black
		_currentShape = PaintPoint.SQUARE_SHAPE; // setting _currentshape variable to square
		
		MouseAdapter adapter = new MouseAdapter() {
			@Override
		    public void mouseDragged(MouseEvent e) { // if the mouse is dragged
				PaintPoint point = new PaintPoint(e.getX(), e.getY(), _currentShape, _globalColor, _globalSize);
				//Paint point is called and passed in parameters or x & y coordinates, shape, color, and size
				_points.add(point); // the element point is added to the array list _points
				repaint(); //repaint is called where the pixel is actually painted
			}
		};
		
		addMouseListener(adapter);
		addMouseMotionListener(adapter);
	}
	
	@Override
	public void paintComponent(Graphics g) {
		super.paintComponent(g);
		
		//g.setColor(_globalColor);
		for (PaintPoint point : _points) {
			point.draw(g);
		}
	}
	
	public void setSize(int size){
		_globalSize = size;
	}
	
	public void setGlobalColor(Color color) {
		_globalColor = color;
		repaint();
	}
	
	public void setShape(int shape) {
		_currentShape = shape;
	}
}
