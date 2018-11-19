import java.awt.Graphics;
import java.awt.GridLayout;
import java.awt.Image;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

import javax.swing.ImageIcon;
import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JPanel;

public class PanelDrive extends JFrame implements ActionListener{
	/**
	 * 
	 */
	private static final long serialVersionUID = 1L;
	private static final int WIDTH = 900;
	private static final int HEIGHT = 1200;
	
	private ImageIcon introBackGroundImage;
	private Graphics screenGraphics;
	private Image screenImage;
	private JLabel imgBox;
	
	private JButton[] buttons = new JButton[12];
	private JPanel panel = new JPanel(new GridLayout(4,3));
	
	
	
	public static void main(String args[]){
		PanelDrive mainFrame = new PanelDrive();
		mainFrame.setVisible(true);
	}
	
	public PanelDrive(){	
		this.setTitle("HyoDong");
		this.setSize(WIDTH, HEIGHT);
		this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		
		for(int i=0; i<12; i++){
			buttons[i] = new JButton();
			buttons[i].addActionListener(this);
			panel.add(buttons[i]);
		}
		
		introBackGroundImage = new ImageIcon("/Users/hanhyeonmin/Desktop/IntroBackGroundImage.png");
		imgBox = new JLabel(introBackGroundImage);
		
		imgBox.setLocation(0, 0);
		panel.setLocation(0, 0);
		
		
		this.add(imgBox);
		this.add(panel);
	}

	@Override
	public void actionPerformed(ActionEvent e) {
		// TODO Auto-generated method stub
		Object clickButton = e.getSource();
		
		for(int i=0; i<12; i++){
			if(clickButton.equals(buttons[i])){
				buttons[i].setVisible(false);
			}
		}
	}
}
