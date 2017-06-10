//Franklin Smith
//CIS 212 PROJECT 3
//Sphere Class

// Implementing a new class named Sphere that extends Circle. Provided is a 
// class constructor which takes arguments appropriate for creating a 3D sphere and implements
// the getArea() method to return the surface area of the sphere

public class Sphere extends Circle{
	//class called Sphere that implements measurable
	private double radius;
	//constructor for my sphere class
	public Sphere(double r){
		super(r);
		this.radius = r;
	}
	@Override
	public double getArea(){
		return (4 * Math.PI * (this.radius * this.radius));
}
}
