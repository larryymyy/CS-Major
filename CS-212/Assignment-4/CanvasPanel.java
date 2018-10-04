
import java.awt.Dimension;
import java.awt.Font;
import java.awt.Graphics;
import java.awt.GridLayout;
import java.awt.event.ComponentAdapter;
import java.awt.event.MouseAdapter;
import java.awt.event.MouseEvent;
import java.util.ArrayList;
import java.awt.Color;

import javax.swing.*;

public class CanvasPanel extends JPanel {
	
	public static ArrayList<Point> points = new ArrayList<Point>();
	private static Color color = new Color(0, 0, 0);
	private static int size = 15;
	
	public CanvasPanel() {
		setPreferredSize(new Dimension((int)(MainFrame.SCREEN_WIDTH/7 * 5 * MainFrame.SCALE), (int)(MainFrame.SCREEN_HEIGHT * MainFrame.SCALE)));
		setBackground(new Color(255, 255, 255));
		
		MouseAdapter adapter = new MouseAdapter() {
			@Override
			public void mouseDragged(MouseEvent e) {
				Point p = new Point(e.getX(), e.getY(), color, size);
				points.add(p);
				// System.out.println(points.size() + ": (" + e.getX() + ", " + e.getY() + ")");
				repaint();
			}
		};
		
		addMouseListener(adapter);
		addMouseMotionListener(adapter);
	}
	
	@Override
	public void paintComponent(Graphics g) {
		super.paintComponent(g);
		for(Point p : points) {
			g.setColor(p.getColor());
			g.fillOval(p.getX(), p.getY(), p.getSize(), p.getSize());
		}
	}
	
	public static void setColor(Color newColor) {
		color = newColor;
	}
	
	public static void setSize(int newSize) {
		size = newSize;
	}
	
}