import java.awt.Color;
import java.awt.Dimension;
import java.awt.FlowLayout;
import java.awt.GridLayout;
import java.awt.event.MouseAdapter;
import java.awt.event.MouseEvent;

import javax.swing.*;

public class LeftPanel extends JPanel {

	private JButton colorRed;
	private JButton colorGreen;
	private JButton colorBlue;
	private JButton colorBlack;
	
	public LeftPanel() {
		setPreferredSize(new Dimension((int)(MainFrame.SCREEN_WIDTH / 7 * MainFrame.SCALE), (int)(MainFrame.SCREEN_HEIGHT * MainFrame.SCALE)));
		setLayout(new FlowLayout());
		Dimension BUTTON_SIZE = new Dimension((int)(MainFrame.SCREEN_WIDTH / 7 * MainFrame.SCALE), (int)((MainFrame.SCREEN_HEIGHT * MainFrame.SCALE / 4)));
		
		// Setting up the Red Button
		colorRed = new JButton("Red");
		colorRed.setPreferredSize(BUTTON_SIZE);
		MouseAdapter maRed = new MouseAdapter() {
			@Override
			public void mouseClicked(MouseEvent e) {
				CanvasPanel.setColor(new Color(175, 0, 0));
			}
		};
		colorRed.addMouseListener(maRed);
		add(colorRed);
		
		// Setting up the Green Button
		colorGreen = new JButton("Green");
		colorGreen.setPreferredSize(BUTTON_SIZE);
		MouseAdapter maGreen = new MouseAdapter() {
			@Override
			public void mouseClicked(MouseEvent e) {
				CanvasPanel.setColor(new Color(0, 175, 0));
			}
		};
		colorGreen.addMouseListener(maGreen);
		add(colorGreen);
		
		// Setting up the Blue Button
		colorBlue = new JButton("Blue");
		colorBlue.setPreferredSize(BUTTON_SIZE);
		MouseAdapter maBlue = new MouseAdapter() {
			@Override
			public void mouseClicked(MouseEvent e) {
				CanvasPanel.setColor(new Color(0, 0, 175));
			}
		};
		colorBlue.addMouseListener(maBlue);
		add(colorBlue);
		
		// Setting up the Black Button
		colorBlack = new JButton("Black");
		colorBlack.setPreferredSize(BUTTON_SIZE);
		MouseAdapter maBlack = new MouseAdapter() {
			@Override
			public void mouseClicked(MouseEvent e) {
				CanvasPanel.setColor(new Color(0, 0, 0));
			}
		};
		colorBlack.addMouseListener(maBlack);
		add(colorBlack);
	}
}
