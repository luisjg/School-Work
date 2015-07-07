//L G
//3/15/10
//Homework 3
/*PSEUDOCODE:Ask the user for his first score and save it to the a variable.
				 Ask the user for his second score and save it to the b variable.
				 Ask the user for his third scores and save it to the c variable.
				 Add the variables a + b + c first and then divied by 3 save the
				 result in the avg variable. Display The average of the scores
				 a variable, b variable and c variable is avg variable on the screen.*/

import java.util.Scanner;

public class Average
{
	public static void main (String [] args)
	{
	int a, b, c;
	Scanner keyboard = new Scanner( System.in );
	System.out.println("Please enter your first score.");
	a = keyboard.nextInt();
	System.out.println("Please enter your second score.");
	b = keyboard.nextInt();
	System.out.println("Please enter your third score.");
	c = keyboard.nextInt();
	double avg;
	avg = (a + b + c) / 3.0;
	System.out.println("The average of the scores " + a + ","
							 + b + ",and " + c + " is " + avg + ".");
	}
}
