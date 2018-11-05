/*
 * Kevin A. Conte
 * 951620146
 * 
 * Assignment 3
 * 10/16/2017
 */


import java.util.*;

public class Main {

	public static void main(String[] args) {
		ArrayList<Measurable> shapes = new ArrayList<Measurable>();
		
		int rectCount = 0, boxCount = 0, circleCount = 0, sphereCount = 0;
		
		// Creating 1000 shapes
		// 25% chance for each shape to be generated
		for(int i = 0 ; i < 1000; i++) {
			
			double chance = nextDouble();
			
			// Rectangle
			if(chance < 0.25) {
				shapes.add(new Rectangle(nextDouble(), nextDouble()));
				rectCount++;
			}
			
			// Box
			else if(chance >= .25 && chance < 0.50) {
				shapes.add(new Box(nextDouble(), nextDouble(), nextDouble()));
				boxCount++;
			}
			
			// Circle
			else if(chance >= 0.50 && chance < 0.75) {
				shapes.add(new Circle(nextDouble()));
				circleCount++;
			}
			
			// Sphere
			else {
				shapes.add(new Sphere(nextDouble()));
				sphereCount++;
			}
		}
		
		// Displaying the counts of each shape
		System.out.println("Rectangle Count: " + rectCount);
		System.out.println("Box Count: " + boxCount);
		System.out.println("Circle Count: " + circleCount);
		System.out.println("Sphere Count: " + sphereCount);
		
		// Summing up the areas of the shapes
		System.out.println("Sum of Areas: " + calculateSum(shapes));
		
		System.exit(0);
	}
	
	// Selecting a random value between (0.0 and 1.0]
	private static double nextDouble() {
		Random rand = new Random();
		double num = rand.nextDouble() + Double.MIN_VALUE;
		return num;
	}
	
	// Calculating the sum of the areas of the shapes
	private static double calculateSum(ArrayList<Measurable> shapes) {
		double sum = 0;
		for(int i = 0; i < shapes.size(); i++) {
			sum += shapes.get(i).getArea();
		}
		return sum;
	}
	
}
