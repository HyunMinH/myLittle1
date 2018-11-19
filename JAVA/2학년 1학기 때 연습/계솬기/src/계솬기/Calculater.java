package 계솬기;

import java.awt.FlowLayout;
import java.awt.GridLayout;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JPanel;
import javax.swing.JTextArea;
import javax.swing.JTextField;

public class Calculater extends JFrame {
	int WIDTH = 280, HEIGHT = 300;

	JPanel buttonPanel = new JPanel();

	JPanel numberPanel = new JPanel();
	JPanel operaterPanel = new JPanel();

	JTextField showNumField = new JTextField(20);

	JButton[] numberButton = new JButton[12];
	JButton[] operaterButton = new JButton[6];
	
	String curOperater = null;
	
	double preNum = 0;

	public Calculater() {
		this.setName("Calculater");
		this.setSize(WIDTH, HEIGHT);
		this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

		numberPanel.setLayout(new GridLayout(4, 3));

		for (int i = 0; i < 9; i++) {
			numberButton[i] = new JButton(Integer.toString(i + 1));
			numberButton[i].addActionListener(new NumberListener());
			numberPanel.add(numberButton[i]);
		}

		numberButton[9] = new JButton(".");
		numberButton[10] = new JButton("0");
		numberButton[11] = new JButton("00");

		for (int i = 9; i < 12; i++) {
			numberButton[i].addActionListener(new NumberListener());
			numberPanel.add(numberButton[i]);
		}

		operaterPanel.setLayout(new GridLayout(2, 3));

		operaterButton[0] = new JButton("+");
		operaterButton[1] = new JButton("-");
		operaterButton[2] = new JButton("*");
		operaterButton[3] = new JButton("/");
		operaterButton[4] = new JButton("%");
		operaterButton[5] = new JButton("=");
		

		for (int i = 0; i < 6; i++) {
			operaterButton[i].addActionListener(new OperaterListener());
			operaterPanel.add(operaterButton[i]);
		}

		buttonPanel.setLayout(new GridLayout(2,1));
		
		buttonPanel.add(numberPanel);
		buttonPanel.add(operaterPanel);

		this.setLayout(new FlowLayout());

		this.add(showNumField);
		this.add(buttonPanel);

		this.setVisible(true);
	}

	public static void main(String args[]) {
		Calculater myCalculater = new Calculater();

	}
	
	
	public class NumberListener implements ActionListener{
		
		public void actionPerformed(ActionEvent e){
			Object clicked = e.getSource();
			
			for(int i =0; i<12; i++){
				if(clicked == numberButton[i]){
					showNumField.setText(showNumField.getText() + numberButton[i].getText());
					return;
				}
			}
		}
	}
	
	
	public class OperaterListener implements ActionListener{
		
		public void actionPerformed(ActionEvent e){
			Object clicked = e.getSource();
			String clickedString = null;
			String numberString = new String();
			
			double curNum = Double.parseDouble(showNumField.getText());
			
			for(int i =0; i<5; i++){
				if(clicked == operaterButton[i]){
					curOperater = operaterButton[i].getText();
					break;
				}	
			}
			
			if(preNum == 0){
				preNum = curNum;
				showNumField.setText(null);
			}else{
				switch(curOperater){
				case "+":	preNum = Calculate.plus(preNum, curNum);	break;
				case "-":	preNum = Calculate.minus(preNum, curNum);	break;
				case "*":	preNum = Calculate.multiply(preNum, curNum);	break;
				case "/":	preNum = Calculate.divide(preNum, curNum);	break;
				case "%":	preNum = Calculate.modular(preNum, curNum);	break;
				case "=":	curOperater = null;	break;
				}
				
				numberString = "";
				numberString += preNum;
				showNumField.setText(numberString);
			}
		}
	}
}
