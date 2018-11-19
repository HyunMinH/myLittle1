import java.awt.Graphics;
import java.awt.GridLayout;
import java.awt.Image;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

import javax.swing.ImageIcon;
import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JPanel;

public class PanelDrive extends JFrame implements ActionListener{
	/**
	 * 
	 */
	private static final long serialVersionUID = 1L;
	private static final int WIDTH = 898;
	private static final int HEIGHT = 1198;
	
	private Image introBackGroundImage;
	private Graphics screenGraphics;
	private Image screenImage;
	
	private JButton[] buttons = new JButton[12];
	private JPanel panel = new JPanel(new GridLayout(4,3));
	
	
	public static void main(String args[]){
		new PanelDrive();
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
		
		System.out.println(getClass().getResource("/Users/hanhyeonmin/Desktop/CORD[]/JAVA/자바 스윙 연습2/src/images/introBackGroundImage.png"));
		
		introBackGroundImage = new ImageIcon(PanelDrive.class.getResource("/Users/hanhyeonmin/Desktop/CORD[]/JAVA/자바 스윙 연습2/src/images/introBackGroundImage.png")).getImage();
		
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
	
	
	public void paint(Graphics g){
		screenImage = createImage(PanelDrive.WIDTH, PanelDrive.HEIGHT);
		screenGraphics = screenImage.getGraphics();
		screenDraw(screenGraphics);
		g.drawImage(screenImage, 0, 0, null);
	}

	private void screenDraw(Graphics g) {
		// TODO Auto-generated method stub
		g.drawImage(introBackGroundImage, 0, 0, null);
		this.repaint();
	}
}
