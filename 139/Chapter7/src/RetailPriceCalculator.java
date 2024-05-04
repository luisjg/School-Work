//Luis Guzman

import java.awt.*;
import java.awt.event.*;
import javax.swing.*;

public class RetailPriceCalculator extends JFrame implements ActionListener {
	
	private JPanel panel1;
	private JPanel panel2;
	private JPanel panel3;
	private JPanel panel4;
	private JLabel label1;
	private JLabel label2;
	private JTextField textField1;
	private JTextField textField2;
	private JButton button1;
	private String input1, input2;
	private double cost, percent, retailPrice;
	
	public RetailPriceCalculator(){
		
		panel1 = new JPanel();
		panel2 = new JPanel();
		panel3 = new JPanel();
		panel4 = new JPanel();
		panel4.setLayout(new GridLayout(3,1));
		
		//Grid 1
		label1 = new JLabel("Please enter the wholesale cost:");
		panel1.add(label1);
		
		textField1 = new JTextField(10);
		textField1.addActionListener(this);
		panel1.add(textField1);
		/*"this" is used to add to current object

		 *RetailCalculator*/		
		
		//Grid 2
		label2 = new JLabel("Please enter the percentage:");
		panel2.add(label2);
		
		textField2 = new JTextField(10);
		textField2.addActionListener(this);
		panel2.add(textField2);
		/*"this" is used to add to current object

		 *RetailCalculator*/		
		
		//Grid 3
		button1 = new JButton("Calculate");
		panel3.add(button1);
		button1.addActionListener(this);
		/*"this" is used to add to current object

		 *RetailCalculator*/
		
		//add panels to the 3 by 1 grid
		panel4.add(panel1);
		panel4.add(panel2);
		panel4.add(panel3);
		
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		setTitle("Retail Price Calculator");
		setSize(300, 200);
		setVisible(true);
		setLocation(500, 400);
		getContentPane().add(panel4);
	}// RetailCostCalculator()

	public void actionPerformed(ActionEvent e) {
		input1 = textField1.getText();
		input2 = textField2.getText();
				if(!input1.isEmpty() && !input2.isEmpty()){
					cost = Double.parseDouble(input1);
					percent = Double.parseDouble(input2);
					retailPrice = cost * (1 + (percent/100));
					JOptionPane.showMessageDialog(this, "The item's retail price is: $" +
					retailPrice);
					}
				else
				{
					JOptionPane.showMessageDialog(this, "Please make sure you have "+ 
							"entered a number in both fields.");
				}//if else
			/*"this" is used to add to current object
			 * RetailCostCalculator()*/
		}//actionPerformed
}// class RetailCostCalculator