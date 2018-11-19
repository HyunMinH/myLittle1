
import java.awt.FlowLayout;
import java.awt.GridLayout;

import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JPanel;
import javax.swing.JTextArea;
import javax.swing.JTextField;

import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public class PannelDemo extends JFrame implements ActionListener{
	public static final int WIDTH = 240;
	public static final int HEIGHT = 360;
	private static final int NUMBER_OF_DIGITS = 0;
	
	public JTextArea lcdText = new JTextArea(10, 20);
	private int result = 0;
	
	public static void main(String args[]){
		PannelDemo gui = new PannelDemo();
		gui.setVisible(true);
	}
	
	public PannelDemo(){
		setTitle("hehe");
		setSize(WIDTH, HEIGHT);
		this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		
		this.setLayout(new FlowLayout(FlowLayout.LEADING, 0, 0));
		
		JPanel lcdPanel = new JPanel();
		lcdText.setText(Integer.toString(0));
		
		lcdPanel.add(lcdText);
		
		JPanel keyPanel = new JPanel();
		keyPanel.setLayout(new GridLayout(4,3));
		
		JButton[] buttons = new JButton[12];
		
		for(int i=0; i<12; i++){
			buttons[i] = new JButton(Integer.toString(i+1));
			buttons[i].addActionListener(this);
			keyPanel.add(buttons[i]); 
		}
		
		this.add(lcdPanel);
		this.add(keyPanel);
	}
	
	

	@Override
	public void actionPerformed(ActionEvent e) {
		String buttonString = e.getActionCommand();
		String hello;
		
		for(int i=0; i<12; i++){
			if(buttonString.equals(Integer.toString(i+1))){
				hello = Integer.toString(i+1);
				lcdText.setText(hello);
			}
		}
	}
}
