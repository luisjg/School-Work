//Luis Guzman
//Homework 3
//3/21/10
/*PSEUDOCODE: Display dialog that asks the user for the retail price of
				 circuit board and save it to the input variable. Convert input
				 to a double and save it to RetailPrice variable. Multiply
				 RetailPrice by .4 and save result in the profit variable.
				 Diplay dialog message Profit is profit variable*/
import javax.swing.JOptionPane;
public class Circuit_board
{
	public static void main (String args[])
		{
		double profit, RetailPrice;
		String input;
		input = JOptionPane.showInputDialog("What is the retail price of "
														+ "the circuit board?");
		//convert input to a double and save it in the RetailPrice variable.
		RetailPrice = Double.parseDouble(input);
		profit = RetailPrice * .4;
		JOptionPane.showMessageDialog(null, "Profit is " + profit);
		
		System.exit(0);
		}
}