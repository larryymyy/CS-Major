import java.awt.Dimension;
import java.awt.FlowLayout;
import java.awt.event.MouseAdapter;
import java.awt.event.MouseEvent;

import javax.swing.*;

public class RightPanel extends JPanel {
	
	private JButton size_SMALL;
	private JButton size_MEDIUM;
	private JButton size_LARGE;
	private JButton clear;
	
	public RightPanel() {
		setPreferredSize(new Dimension((int)(MainFrame.SCREEN_WIDTH / 7 * MainFrame.SCALE), (int)(MainFrame.SCREEN_HEIGHT * MainFrame.SCALE)));
		setLayout(new FlowLayout());
		Dimension BUTTON_SIZE = new Dimension((int)(MainFrame.SCREEN_WIDTH / 7 * MainFrame.SCALE), (int)((MainFrame.SCREEN_HEIGHT * MainFrame.SCALE / 4)));
		
		// Setting up the small size button
		size_SMALL = new JButton("Small");
		size_SMALL.setPreferredSize(BUTTON_SIZE);
		MouseAdapter maSmall = new MouseAdapter() {
			@Override
			public void mouseClicked(MouseEvent e) {
				CanvasPanel.setSize(15);
			}
		};
		size_SMALL.addMouseListener(maSmall);
		add(size_SMALL);
		
		// Setting up the medium size button
		size_MEDIUM = new JButton("Medium");
		size_MEDIUM.setPreferredSize(BUTTON_SIZE);
		MouseAdapter maMedium = new MouseAdapter() {
			@Override
			public void mouseClicked(MouseEvent e) {
				CanvasPanel.setSize(30);
			}
		};
		size_MEDIUM.addMouseListener(maMedium);
		add(size_MEDIUM);
		
		// Setting up the large size button
		size_LARGE = new JButton("Large");
		size_LARGE.setPreferredSize(BUTTON_SIZE);
		MouseAdapter maLarge = new MouseAdapter() {
			@Override
			public void mouseClicked(MouseEvent e) {
				CanvasPanel.setSize(45);
			}
		};
		size_LARGE.addMouseListener(maLarge);
		add(size_LARGE);
		
		// Setting up the clear button
		clear = new JButton("Clear");
		clear.setPreferredSize(BUTTON_SIZE);
		MouseAdapter maClear = new MouseAdapter() {
			@Override
			public void mouseClicked(MouseEvent e) {
				CanvasPanel.points.clear();
			}
		};
		clear.addMouseListener(maClear);
		add(clear);
	}
	
}
