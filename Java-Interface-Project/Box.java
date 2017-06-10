//Franklin Smith
//CIS 212 PROJECT 3
//Box Class

// Implementing a new calls named box that extends rectangle
// Provided is a class constructor which takes arguments appropriate
// for creating a 3D box and implement the getArea() method to return
// the total surface area of the box
public class Box extends Rectangle{
	//class called Box Implements measurable
	private double height;
		//constructor for my box class
		public Box(double b1, double b2, double b3){
			super(b1,b2);
			this.height = b3;
		}
		@Override
		public double getArea()
		{
		return (2*(this.height * this.width) + (2*(this.height * this.length)) +(2*(this.width * this.length)));
		}
}

