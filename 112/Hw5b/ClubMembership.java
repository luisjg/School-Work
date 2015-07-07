//L G
//Homework 5b
//4/27/10
/*PSEUDOCODE: Diplay a menu to user. Store users selection. Evaluate the
selection. Diplay appropriate message after evaluating user input.
Display total sales message when user quits.*/

import java.util.Scanner;
import java.text.DecimalFormat;

public class ClubMembership
{
	public static void main(String [] args)
	{
		//declare variables
		int choice;//to hold user input
		double TotalSales;
		double SixMonth = 0;
		double TwelveMonth = 0;
		Scanner keyboard = new Scanner(System.in);
		DecimalFormat formatter = new DecimalFormat("#0.00");

		do
			{
			//Diplay menu to user.
			System.out.println("BOOK CLUB MEMBERSHIP MENU:");
			System.out.println("1) Sell a Six Month Membership.");
			System.out.println("2) Sell a Twelve Month Membership.");
			System.out.println("3) Quit the Program.");
			System.out.println("\nMake a selection by choosing a number:");

			choice = keyboard.nextInt();

				if (choice == 1)
				{
				//Diplay message to user.
				SixMonth = SixMonth + 50.50;
				System.out.println("You have sold 1 Six Month Membership\n");
				}
				else if (choice == 2)
				{
				//Diplay message to user.
				TwelveMonth = TwelveMonth + 99.00;
				System.out.println("You have sold 1 Twelve Month Membership\n");
				}
				else if (choice != 3)
				{
				//Display error message to user.
				System.out.println("You have entered and Invalid value.\n");
				}
			}
		//To evaluate loop.
		while(choice != 3);

		//To calculate total.
		TotalSales = SixMonth + TwelveMonth;
		//Diplay the formatted total to user.
		System.out.println("The total book club membership sales were $"
									+ formatter.format(TotalSales) + ".");

	}
}
