// Lesson 05 - Assignment
// Author - Mike Orsega
using System;

public class CheckBook
{

  public static void Main()
  {
	double start=0.0, add=0.0, subtract=0.0, end=0.0;

	Console.Out.WriteLine("For the starting balance,");
	getDouble(ref start);

	Console.Out.WriteLine("\nFor the total of the deposits,");
	getDouble(ref add);

	Console.Out.WriteLine("\nFor the total withdrawals,");
	getDouble(ref subtract);

	balanceBook(start, add, subtract, ref end);

	Console.Out.WriteLine("The ending balance is " + end);
  }

  public static void getDouble(ref double value)
  {
     String strValue;

     // Get input from the user
     System.Console.Out.Write("Enter a value: ");
     strValue = System.Console.ReadLine();
     value = Convert.ToDouble(strValue);
  }

  public static void balanceBook(double beginning, double deposits, double withdrawals, ref double ending)
  {
     ending = beginning + deposits - withdrawals;
  }

}