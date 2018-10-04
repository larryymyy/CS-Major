
import java.awt.Color;

public class Point {
	private int x;
	private int y;
	private Color c;
	private int POINT_SIZE = 20;
	
	public Point(int x, int y, Color c, int size) {
		this.x = x;
		this.y = y;
		this.c = c;
		this.POINT_SIZE = size;
	}
	
	public int getX() {
		return this.x;
	}
	public int getY() {
		return this.y;
	}
	
	public Color getColor() {
		return this.c;
	}
	
	public int getSize() {
		return POINT_SIZE;
	}
}
