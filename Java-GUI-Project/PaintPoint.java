//Franklin Smith Project4 PaintPoint.java
//"I used the 'Paint with shapes and colors' example 
//provided on the course website as a starter template for this project".


import java.awt.Color;
import java.awt.Graphics;

public class PaintPoint {
	public static final int CIRCLE_SHAPE = 0;
	public static final int SQUARE_SHAPE = 1;
	public final Color clr;
	private int Size = 0;
	private final int _x;
	private final int _y;
	private final int _shape;
	
	public PaintPoint(int x, int y, int shape, Color C, int input_size) {  //constructor for the class PaintPoint
		_x = x;
		_y = y;
		_shape = shape;
		clr = C;
		Size = input_size;
	}
	
	public int getX() { //function returns X cord
		return _x;
	}

	public int getY() { //function returns Y cord
		return _y;
	}

	public int getShape() {  //function returns type of shape to be used for draw
		return _shape;
	}
	
	public void draw(Graphics g) { 
		g.setColor(clr);
		switch (_shape) {
		case CIRCLE_SHAPE:
			g.fillOval(_x, _y, Size, Size);
			break;
		case SQUARE_SHAPE:
			g.fillRect(_x, _y, Size, Size);
			break;
		}
	}
}
