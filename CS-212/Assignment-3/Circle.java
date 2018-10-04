import java.lang.Math;
public class Circle implements Measurable {
	
	private double radius;
	
	public Circle(double radius) {
		this.radius = radius;
	}
	
	@Override
	public double getArea() {
		return (this.radius * this.radius) * (Math.PI);
	}
}