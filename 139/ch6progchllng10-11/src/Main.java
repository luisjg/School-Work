import javax.swing.JOptionPane;


public class Main {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		SavingsAccount myAccount = new SavingsAccount(100);
		myAccount.setAnnualInterestRate(0.05);
		double input;
		String userInput;
		
		userInput = JOptionPane.showInputDialog("Please enter the number of months.");
		input = Double.parseDouble(userInput);
		
		int i = 0;
		while(input >= i){
			JOptionPane.showInputDialog("Hmmm");
			i++;
		}
	}//end of main

}//end of Main