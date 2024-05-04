package cipher;

import java.awt.event.*;
import javax.swing.*;
import java.awt.*;

public class UserInput extends JFrame implements ActionListener {
	private JPanel panel1;
	private JPanel panel2;
	private JPanel panel3;
	private JLabel label1;
	private JLabel label2;
	private JButton button1;
	private JButton button2;
	private JTextField textField1;
	private JTextField textField2;
	private String input1, input2;
	
	public UserInput(){
		
		panel1 = new JPanel();
		panel2 = new JPanel();
		panel3 = new JPanel();
		panel3.setLayout(new GridLayout(2,1));
		
		label1 = new JLabel("Enter to Decode.");
		panel1.add(label1);
		textField1 = new JTextField(10);
		panel1.add(textField1);
		button1 = new JButton("Decode");
		panel1.add(button1);
		button1.addActionListener(this);
		
		label2 = new JLabel("Enter to Encode.");
		panel2.add(label2);
		textField2 = new JTextField(10);
		panel2.add(textField2);
		button2 = new JButton("Encode");
		panel2.add(button2);
		button2.addActionListener(this);
		
		panel3.add(panel1);
		panel3.add(panel2);
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		setSize(300, 200);
		setVisible(true);
		setTitle("Jeagoss Cipher");
		getContentPane().add(panel3);
		
	}
	public void actionPerformed(ActionEvent e){
		input1 = textField1.getText();
		input2 = textField2.getText();
		if(e.getSource() == button1){
//			int[] ciper = new int {1, 2, 3, 4, 6};
			if(input1.equals("-1")){
				System.exit(0);
			}
		}
		if(e.getSource() == button2){
			if(input2.equals("-1")){
				System.exit(0);
			}
		}
	}
}
