//Franklin Smith
//CIS 212 PROJECT 3
/*
For this project, i implemented a hierarchy of java classes that shared
a common interface. I then created a data structure using this interface type
and populated it with various instances of classes inheriting from the interface.

I implemented a enw interface named Measureable with a single method named 
getArea() which takes no arguments and returns a double.

I implemented a new class named rectangle that implements Measureable. I 
provided a class constructor which takes arguments appropriate for creating
a 2D rectangel and implements the getArea() method to return the area of the
rectangle.

I implemented a new class named Box that extends Rectangle. I provided a class
constructor which takes arguments appropriate for creading a 3D box and implements
the getArea() method to return the total surface area of the box.

I implemented a new class named circle that implements measurable. I provided
a class constructor which takes arguments appropriate for creating a 2D circle
and I implemented the getArea() method to return the area of the circle.

I implemented a new class named Sphere that extends Circle. I provided a class
constructor which takes arguments appropriate for creating a 3D sphere and 
implemented the getArea() method to return the surface area of the sphere.

I implemented a new class named Main with a public static main() mehtod and
private static nextDoube() and calculateSum() Methods:

The nextDboue() method shoudl simply return a doubel on the range (0.0, 1.0]
the calculateSum() method should take an arrayList of type measureable as an
argument and return the sum of all areas in the list.
The main() method should create an ArayList of type Measureable and populate 
that list with 1000 random instances of my measureable classes from parts 2-5.
There is a 25% of that each instance is one of the four classes.
I use the nextDouble() method to generate random dimensions to pass into the 
Measurable constructors. I track the number of instances of each class created
and I print the results.
Finally i called the calcualteSum() method and print the result.
*/

import java.util.ArrayList;
import java.util.Random;
public class Main {
	public static void main(String[] args){
		//create array list of type measurable
		//populate list with 1000 random instances of my
		//measurable classes 
		//(25% chance of that each instance is one of the four classes)
		// random double then generated
		//0.0-0.25 Rectangle
		//0.25-0.50 Circle
		//0.50-0.75 Sphere 
		//0.75-1.00 Box
		int rectangle_count = 0; // counter initialized for rectangle classes created
		int circle_count = 0; // counter initialized for circle classes created
		int sphere_count = 0; // counter initialized for sphere classes created
		int box_count = 0; // counter initialized for box classes created
		ArrayList<Measurable> list1 = new ArrayList<Measurable>(); // create array list of type measurable
		for(int l = 1; l <= 1000; l++){ // for 1000 times
			double temp = nextDouble(); // random double generated
			if(temp < .25){
				double width = nextDouble(); // rectangle width assigned to random double
				double height = nextDouble(); // rectangle height assigned to random double
				rectangle_count = rectangle_count +1; // increase rectangle class count by 1 
				list1.add(new Rectangle(width,height)); // populate list1 with instance of rectangle class
			}
			if(temp > .25 && temp < .50){
				double circleradius = nextDouble(); // circle radius assigned to random double
				circle_count = circle_count + 1; // increase circle class count by 1
				list1.add(new Circle(circleradius)); // populate list1 with instance of circle class
			}	
			if(temp > .50 && temp < .75){
				double sphereradius = nextDouble(); // sphere radius assigned to random double
				sphere_count = sphere_count + 1; // increase sphere class count by 1
				list1.add(new Sphere(sphereradius)); // populate list 1 with instance of sphere class
			}
			if(temp > .75 && temp <= 1.0){
				double boxside1 = nextDouble(); // box length assigned to random double
				double boxside2 = nextDouble(); // box width assigned to random double
				double boxside3 = nextDouble(); // box height assigned to random double
				box_count = box_count + 1; // increase box class count by 1
				list1.add(new Box(boxside1,boxside2,boxside3)); // populate list1 with instance of box class
			}
		}
		
		String count_result = String.format("rects: %1$d boxes: %2$d circles: %3$d spheres: %4$d", rectangle_count, circle_count, sphere_count, sphere_count, box_count);
		System.out.println(count_result);
		System.out.println("Sum: " + calculateSum(list1));
	}
	private static double nextDouble(){
		// nextDouble method returns a double on the range (0.0, 1.0]
		// (0.0 exclusive to 1.0 inclusive) so that there are no 0.0 areas
		Random numdouble = new Random();
		double k = numdouble.nextDouble();
		while(k < java.lang.Double.MIN_VALUE){
			k = numdouble.nextDouble();	
		}
		return k;
	}
	private static double calculateSum(ArrayList<Measurable> ray){
		// calculateSum method takes and ArrayList of type Measurable as an 
		// argument and returns the sum of all areas in the list.
		double sum_counter = 0;
		for (int i = 0; i < ray.size(); i++) {
			sum_counter +=(ray.get(i)).getArea();
		}
		return sum_counter;
	}
}



