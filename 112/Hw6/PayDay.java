//L G
//5/5/10
/*PSEUDOCODE: Display message on screen that asks users for number
of days worked save input in variable numDays. Input validation to
check for invalid numbers. Display on screen the pay for each number
of days. Display formatted total pay.*/

import java.util.Scanner;
import java.text.DecimalFormat;

public class PayDay
{
	public static void main (String [] args)
	{
		//declare vairables
		//and initialize values
		int numDays = 0;
		double singleTotal = 1;
		double totalPay = 0;
		Scanner choice = new Scanner(System.in);
		DecimalFormat formatter = new DecimalFormat("#,##0.00");

		//display prompt to user and save his input
		System.out.println("Please enter the number days worked.");
		numDays = choice.nextInt();


		//input validation
		while (numDays < 1)
		{
		//display error message to screen
		//ask user for new input and save to variable
		System.out.println("You have entered an invalid value.\nPleace try"
							+ " again.\n\nPlease enter the number of days worked.");
		numDays = choice.nextInt();
		}
			//loop start
			//diplays on screen pay for each day
			for (int counter = 1; counter <= numDays; counter++)
			{
			//to calculate for day 1
			if (counter == 1)
			{
			singleTotal = singleTotal;

			}
			//to calculate the rest of the days
			else
			{
			singleTotal = singleTotal * 2;
			}
			//display the pay for each day and formatted singlePay
			System.out.println("PAY for Day " + counter + ":\t$"
									+ formatter.format(singleTotal));
			//to calculate totalPay
			totalPay = totalPay + singleTotal;
			}
		//display the formatted totalPay to screen
		System.out.println();
		System.out.println("TOTAL PAY FOR " + numDays + " DAYS: $"
									+ formatter.format(totalPay));
	}
}
