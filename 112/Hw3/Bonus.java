//L G
//3/21/10
/*PSEUDOCODE:Ask user for his name save it to the name variable. Ask user how
				 many cars he sold save it to the CarsSold variable. Multiply
				 CarsSold by 1000 and save result in the bonus variable. Display
				 Hello name variable, your bonus for this month is $bonus variable.*/
import java.util.Scanner;

public class Bonus
{
	public static void main (String[] args)
	{
	int bonus, CarsSold;
	String name;
	Scanner input = new Scanner ( System.in );
	System.out.println("What is your name?");
	name = input.nextLine();
	System.out.println("How many cars did you sell this month?");
	CarsSold = input.nextInt();
	bonus = CarsSold * 1000;
	System.out.println("Hello " + name + ", your bonus for this month is $"
							 + bonus + ".");
	}
}
