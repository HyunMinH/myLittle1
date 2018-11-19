												 import java.awt.GridLayout;

import javax.swing.BorderFactory;
import javax.swing.ButtonGroup;
import javax.swing.JPanel;
import javax.swing.JRadioButton;

class ToppingPanel extends JPanel { 
	private JRadioButton Combi, Vt, gd, ML,SF; 
	private ButtonGroup bg;
	
	public ToppingPanel() { 
		setLayout(new GridLayout(4, 1)); 
		Combi = new JRadioButton("Combination(10.0)", true);
		Vt = new JRadioButton("Vegetarian(11.0)");
		gd = new JRadioButton("garden(12.0)");
		ML = new JRadioButton("Meat Lovers(13.0)");
		SF = new JRadioButton("Sea Food(15.0)");
		
		
		bg = new ButtonGroup();
		bg.add(Combi);
		bg.add(Vt);
		bg.add(gd);
		bg.add(ML);
		bg.add(SF);
		setBorder(BorderFactory.createTitledBorder("¸À"));
		add(Combi);
		add(Vt);
		add(gd);
		add(ML);
		add(SF);
	
	}
	
}

 
			