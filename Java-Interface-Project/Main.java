//Franklin Smith
//CIS 212 PROJECT 3


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



