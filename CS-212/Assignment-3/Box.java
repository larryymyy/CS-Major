
public class Box extends Rectangle implements Measurable {
	
	private double width, height, depth;
	
	public Box(double width, double height, double depth) {
		super(width, height);
		this.depth = depth;
	}
	
	@Override
	public double getArea() {
		return 2 * (this.width * this.height + this.height * this.depth + this.width * this.depth);
	}
}
