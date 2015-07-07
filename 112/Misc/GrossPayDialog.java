import javax.swing.JOptionPane
;//Calculates a user's gross pay using dialog boxes
public class GrossPayDialog
{
   public static void main(String[]args)
	   {      //for reading the input to convert to numerical data
		      String inputStr;
				String name;
			   int hours;
				double payRate;
				double grossPay;
				//get the user's name
				name = JOptionPane.showInputDialog("What's your name?");
				//get the hours worked
				inputStr = JOptionPane.showInputDialog("How many hours did you work?");
				//convert the input to an int
				hours = Integer.parseInt(inputStr);
				//get the pay rate
				inputStr = JOptionPane.showInputDialog("What is your hourly pay rate?");
				//convert the input to an double
				payRate = Double.parseDouble(inputStr);
				//calculate the gross pay
				grossPay = hours * payRate;
				//Display the results
				JOptionPane.showMessageDialog(null, "Hello " + name + "." +
														" Your gross pay is $" + grossPay);
				System.exit(0);
				}
}
