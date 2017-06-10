//Franklin Smith
//CIS 212 PROJECT 3
//Rectangle Class

// Class named rectangle implements Measurable.
// Has a class constructor which takes arguments appropriate for
// creating a 2D rectangle and implements the getArea() method to return
// the area of the rectangle

public class Rectangle implements Measurable {
		 //class named Rectangle, implements measurable
		 //constructor for my rectangle class
		 //takes appropriate arguments for creating 2D rectangle
	protected double length;
	protected double width;
	public Rectangle(double a, double b){
			this.length = a;
			this.width = b;
			}
		 public double getArea()
		 {
		 return (this.length * this.width);
		 }
}
