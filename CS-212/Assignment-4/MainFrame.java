import java.awt.BorderLayout;
import java.awt.Color;
import java.awt.Dimension;
import java.awt.FlowLayout;
import java.awt.Font;

import javax.swing.*;

public class MainFrame extends JFrame {
	
	// Scaling constants
	public final static int SCREEN_WIDTH = 1920;
	public final static int SCREEN_HEIGHT = 1080;
	public static double SCALE;
	
	public final static Font DEFAULT_FONT = new Font("Dialog", Font.BOLD, 24);
	
	// Constructor
	public MainFrame() {
		super("Assignment 4 - Kevin A. Conte");
		setFont();
		SCALE = Math.max(1, new JLabel().getFont().getSize() / 15);
		setLayout(new FlowLayout(FlowLayout.LEFT));
		
		LeftPanel l = new LeftPanel();
		add(l);
		CanvasPanel c = new CanvasPanel();
		add(c);
		RightPanel r = new RightPanel();
		add(r);
	}
	
	// Setting the fonts of the components
	public void setFont() {
		UIManager.put("Label.font", DEFAULT_FONT);
		UIManager.put("Button.font", new Font("Dialog", Font.BOLD, 36));
	}
}