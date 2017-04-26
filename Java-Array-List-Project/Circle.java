//Franklin Smith
//CIS 212 PROJECT 3
//Circle Class

// implementing a new class called circle that implements Measurable
// Provided is a class constructor which takes arguments appropriate for creating
// a 2d circle and implements the getArea() method to return the area of the circle
public class Circle implements Measurable{
	//class called circle implements Measurable
	private double radius;
	// constructor for my circle class
	public Circle(double c1){
		this.radius = c1;
	}
	public double getArea(){
		return (Math.PI *2* this.radius);
	}	
}
