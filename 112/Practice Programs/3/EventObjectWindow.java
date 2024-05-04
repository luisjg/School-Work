import javax.swing.*;
import java.awt.event.*;

public class EventObjectWindow extends JFrame
{
	private JButton button1;
	private JButton button2;
	private JButton button3;
	private JPanel panel;
	private final int WINDOW_WIDTH = 300;
	private final int WINDOW_HEIGHT = 90;
	
	
	public EventObjectWindow()
	{
	 setTitle("Event Object Window");
	 
	 setSize(WINDOW_WIDTH, WINDOW_HEIGHT);
	 
	 setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
	 
	 button1 = new JButton("Button 1");
	 button2 = new JButton("Button 2");
	 button3 = new JButton("Button 3");
	 
	 button1.addActionListener(new ButtonListener());
	 button2.addActionListener(new ButtonListener());
	 button3.addActionListener(new ButtonListener());
	 
	 panel = new JPanel();
	 panel.add(button1);
	 panel.add(button2);
	 panel.add(button3);
	 
	 add(panel);
	 
	 setVisible(true);
	}
	
	private class ButtonListener implements ActionListener
	{
		public void actionPerformed(ActionEvent e)
		{
			String actionCommand = e.getActionCommand();
			
			if (actionCommand.equals("Button 1"))
			{
			JOptionPane.showMessageDialog(null, "You clicked the first button");
			}
			else if (actionCommand.equals("Button 2"))
			{
			JOptionPane.showMessageDialog(null, "You clicked the second button");
			}
			else if (actionCommand.equals("Button 3"))
			{
			JOptionPane.showMessageDialog(null, "You clicked the third button");
			}
		}
	}
}