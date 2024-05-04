import javax.swing.*;
import java.awt.event.*;

public class KiloConverterWindow extends JFrame
{

private JPanel panel;
private JLabel messageLabel;
private JTextField kiloTextField;
private JButton milesButton;
private JButton metersButton;
private final int WINDOW_WIDTH = 350;
private final int WINDOW_HEIGHT = 100;

	public KiloConverterWindow()
	{
		setTitle("Kilometer converter");
		setSize(WINDOW_WIDTH, WINDOW_HEIGHT);
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		buildPanel();
		add(panel);
		setVisible(true);
	}
	
	private void buildPanel()
	{
		messageLabel = new JLabel("Enter a distance in kilometers:");
		kiloTextField = new JTextField(10);
		milesButton = new JButton("Miles");
		metersButton = new JButton("Meters");
		milesButton.addActionListener(new MilesButtonListener());
		metersButton.addActionListener(new MetersButtonListener());
		panel = new JPanel();
		panel.add(messageLabel);
		panel.add(kiloTextField);
		panel.add(milesButton);
		panel.add(metersButton);
	}

	private class MilesButtonListener implements ActionListener
	{
		public void actionPerformed(ActionEvent e)
		{
		String input;
		double miles;
		
		input = kiloTextField.getText();
		
		miles = Double.parseDouble(input) * 0.6214;
		JOptionPane.showMessageDialog(null, input + " kilometers is "
		+ miles + " miles.");
		}
	}

	private class MetersButtonListener implements ActionListener
	{
		public void actionPerformed(ActionEvent e)
		{
		String input;
		double meters;
		
		input = kiloTextField.getText();
		
		meters = Double.parseDouble(input) * 1000;
		JOptionPane.showMessageDialog(null, input + " kilometers is "
		+ meters + " meters.");
		}
	}

}