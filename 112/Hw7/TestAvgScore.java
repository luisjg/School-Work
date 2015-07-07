import java.util.Scanner;
public class TestAvgScore
{
	public static void main (String [] args)
	{
	double test1;
	double test2;
	double test3;
	double test4;
	double test5;
	double avgGrade;


	Scanner keyboard = new Scanner(System.in);
	
	System.out.println("Please enter your 1st test score.");
	test1 = keyboard.nextInt();
	System.out.println("Please enter your 2nd test score.");
	test2 = keyboard.nextInt();
	System.out.println("Please enter your 3rd test score.");
	test3 = keyboard.nextInt();
	System.out.println("Please enter your 4th test score.");
	test4 = keyboard.nextInt();
	System.out.println("Please enter your 5th test score.");
	test5 = keyboard.nextInt();

	avgGrade = calcAverage(test1, test2, test3, test4, test5); 
	System.out.println("The average is " + avgGrade);
	System.out.println();
	
	determineGrade(avgGrade);

	}
	
		public static double calcAverage(double t1, double t2, double t3, double t4, double t5)
		{
		return (t1+t2+t3+t4+t5)/5;
		}
			public static void determineGrade(double Grade)
			{
			
				if (Grade > 90)
				{
				System.out.println("Your grade is an A.");
				}
				else if (Grade > 80 && Grade < 89)
				{
				System.out.println("Your grade is a B.");
				}
				else if (Grade > 70 && Grade < 79)
				{
				System.out.println("Your grade is a C.");
				}
				else if (Grade > 60 && Grade < 69)
				{
				System.out.println("Your grade is a D.");
				}
				else
				{
				System.out.println("Your grade is an F.");
				}
			} 
}