//Same as Average.java but with pop-up.
import javax.swing.JOptionPane;
public class avg
{
	public static void main (String args[])
		{
		double a, b ,c, avg;
		String input;

		input = JOptionPane.showInputDialog("Please enter your first test score.");
		a = Double.parseDouble(input);
		input = JOptionPane.showInputDialog("Please enter your second test score.");
		b = Double.parseDouble(input);
		input = JOptionPane.showInputDialog("Please enter your third test score.");
		c = Double.parseDouble(input);
		avg = ( a + b + c ) / 3;
		JOptionPane.showMessageDialog(null, "Your average test score is " + avg);

		System.exit(0);
		}
}
