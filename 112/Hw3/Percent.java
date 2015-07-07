//L G
//3/21/10
/*PSEUDOCODE:Ask user for the total number of test questions and save it in
				 the correct variable. Ask user for the number of correct questions
				 save it in the total variable. Divide correct by total first, then
				 multiply by 100 save result in the grade variable. Display You got correct
				 variable out of total variable. Your percentage is grade variable on the screen.*/
import java.util.Scanner;
public class Percent
{
	public static void main (String [] args)
	{
	int total, correct;
	double grade;
	Scanner input = new Scanner ( System.in );
	System.out.println("What are the total number of questions on the test?");
	total = input.nextInt();
	System.out.println("What are the number of correct questions?");
	correct = input.nextInt();
	//cast used for calculation
	grade = (correct / (double) total) * 100;
	System.out.println("You got " + correct + " out of " + total + " correct.\n"
							  + "Your percentage is : " + grade + "%");
	}
}
