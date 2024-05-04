import java.text.*;
import javax.swing.*;

public class RainCalculator {
	public static void main(String[] args) {
		final int NUM_MONTHS = 12;
		double[] rainFall = new double[NUM_MONTHS];
		DecimalFormat formatter = new DecimalFormat("#0.00");
		getTotal(rainFall);
		RainFall month = new RainFall(rainFall);
		JOptionPane.showMessageDialog(null, "The total rain fall is " +
						month.getTotal() + "\nThe average rain fall is "
						+ formatter.format(month.getAverage()) + "\nThe "
						+ "highest rain fall was " + month.getHighestMonth()
						+ "\nThe lowest rain fall was "+ month.getLowestMonth());
		System.exit(0);
	}//main()

	private static void getTotal(double[] array) {
		String input;
		for(int i = 0; i < array.length; i++){
			input = JOptionPane.showInputDialog("Enter the total rainfall" +
					"for month " + (i + 1) + ".");
			if(input == null){
				System.exit(0);
			}//if input is null
				while(input.isEmpty()){
					input = JOptionPane.showInputDialog("Make sure you have" +
							"entered a number. \nPlease enter the total rain" +
							"fall for month " + (i + 1) + ".");
						if(input == null){
							System.exit(0);
						}//if input null
				}//while input isEmpty
			array[i] = Double.parseDouble(input);
				while(array[i] < 0){
					input = JOptionPane.showInputDialog("You have entered an" +
							"invalid number.\nPlease try again.\nEnter the" +
							"total rain fall for month " + (i + 1) + ".");
						if(input == null){
							System.exit(0);
						}//if input is null
								if(input.isEmpty()){
									input = JOptionPane.showInputDialog("Make sure" +
											"you have entered a number.\nPlease enter" +
											"the total rain fall for month " + (i + 1) +
											".");
								}//if input isEmpty
						if(input == null){
							System.exit(0);
						}//if input null
				array[i] = Double.parseDouble(input);
				}//while
		}//for
	}//getTotal()
}//RainCalculator