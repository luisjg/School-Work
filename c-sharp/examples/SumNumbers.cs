// Lesson 08 - Assignment
// Author - Mike Orsega
using System;

public class SumNumbers
{

  public static void Main()
  {
	int number, sum = 0;
	String strNumber;

     	// Get input from the user
     	Console.Out.Write("Enter a number (999 to quit): ");
     	strNumber = Console.ReadLine();
     	number = Convert.ToInt32(strNumber);

	while (number != 999)
	{
	   sum = sum + number;
	   Console.Out.Write("Enter a number (999 to quit): ");
	   strNumber = Console.ReadLine();
	   number = Convert.ToInt32(strNumber);
	}

	Console.Out.WriteLine("\n\nThe sum of your numbers is " + sum);

  }


}