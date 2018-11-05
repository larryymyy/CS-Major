import java.lang.Math;
public class Sphere extends Circle implements Measurable {
	
	private double radius;
	
	public Sphere(double radius) {
		super(radius);
	}
	
	@Override
	public double getArea() {
		return 4 * (Math.PI) * (radius * radius);
	}
}