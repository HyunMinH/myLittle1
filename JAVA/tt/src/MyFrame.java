
import java.awt.BorderLayout;

import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JPanel;
import javax.swing.JTextField;

public class MyFrame extends JFrame {
		P1 typed = new P1();
		P2 flavour = new P2();
		P3 sidemenu = new P3();
		JPanel down = new JPanel();
		JTextField text = new JTextField();
		JButton b1,b2;
		/*typed.getsum+flavour.getsum+sidemenu.getsum;*/
	public MyFrame() {
		setTitle("피자주문");
		setSize(500,300);
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		setVisible(true);
		b1 = new JButton("주문");
		b2 = new JButton("취소");
		down.add(b1);
		down.add(b2);
		down.add(text);
		this.add(typed,BorderLayout.WEST);
		this.add(flavour,BorderLayout.CENTER);
		this.add(sidemenu,BorderLayout.EAST);
		this.add(down,BorderLayout.PAGE_END);
		text.setText(typed.getsum1()+flavour.getsum2()+sidemenu.getsum3());
	}
}
 
		