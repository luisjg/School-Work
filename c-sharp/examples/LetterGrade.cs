// Lesson 06 - Assignment
// Author - Mike Orsega
using System;

public class LetterGrade
{

  public static void Main()
  {
	double average;
	String strAverage;

     	// Get input from the user
     	System.Console.Out.Write("Enter your numerical average: ");
     	strAverage = System.Console.ReadLine();
     	average = Convert.ToDouble(strAverage);

	if (average >= 90)
	   Console.Out.WriteLine("A");
	else if (average >= 80)
	   Console.Out.WriteLine("B");
	else if (average >= 70)
	   Console.Out.WriteLine("C");
	else if (average >= 60)
	   Console.Out.WriteLine("D");
	else
	   Console.Out.WriteLine("F");
  }

}