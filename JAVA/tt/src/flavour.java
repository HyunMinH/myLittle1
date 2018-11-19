
import java.awt.GridLayout;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

import javax.swing.JPanel;
import javax.swing.JRadioButton;

public class flavour extends JPanel {
	int sum;
	private JRadioButton b1,b2,b3,b4,b5;
	public flavour() {
		setLayout(new GridLayout(0,5));
		
		JRadioButton b1 = new JRadioButton("Combination");
		b1.addActionListener(new listener());
		JRadioButton b2 = new JRadioButton("Vegetarian");
		b2.addActionListener(new listener());
		JRadioButton b3 = new JRadioButton("Garden");
		b3.addActionListener(new listener());
		JRadioButton b4 = new JRadioButton("Lovers");
		b4.addActionListener(new listener());
		JRadioButton b5 = new JRadioButton("SeaFood");
		b5.addActionListener(new listener());
		this.add(b1);
		this.add(b2);
		this.add(b3);
		this.add(b4);
		this.add(b5);

	}
	public class listener implements ActionListener{
		
	
	public void actionPerformed(ActionEvent e) {
		if(e.getSource() == b1) {
			sum=10000;
		}
		else if(e.getSource() == b2) {
			sum=11000;
		}
		else if (e.getSource() == b3) {
			sum=12000;
		}
		else if(e.getSource() == b4) {
			sum = 13000;
		}
		else if(e.getSource() == b5) {
			sum =15000;
		}


	}
	int getsum2() {
		return sum;
	}

}
}