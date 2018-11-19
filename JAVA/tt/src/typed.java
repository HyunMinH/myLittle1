
import java.awt.GridLayout;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

import javax.swing.JPanel;
import javax.swing.JRadioButton;

public class typed	extends JPanel {
	int sum;
	JRadioButton b1,b2,b3;
	typed(){
		setLayout(new GridLayout(0,3));
		
		JRadioButton b1 = new JRadioButton("Premium Special");
		b1.addActionListener(new listener());
		JRadioButton b2 = new JRadioButton("Premium");
		b2.addActionListener(new listener());
		
		JRadioButton b3 = new JRadioButton("Original");
		b3.addActionListener(new listener());
		this.add(b1);
		this.add(b2);
		this.add(b3);
		
	}
	
	
	public int getsum1() {
		return sum;
	}
	public class listener implements ActionListener{ 
	public void actionPerformed(ActionEvent e) {
		if(e.getSource() == b1) {
			sum=5000;
		}
		else if(e.getSource() == b2) {
			sum=3000;
		}
		else if (e.getSource() == b3) {
			sum=0;
		}
		
		}
	}
}

 