// Lesson 04 - Assignment
// Author - Mike Orsega
using System;

public class RightTriangle
{
  public static void Main()
  {
     // Declare Variables
     double side1, side2, hyp;
     string strSide1, strSide2;

     // Get input from the user
     System.Console.Out.Write("Enter the length of the first side: ");
     strSide1 = System.Console.ReadLine();
     side1 = Convert.ToDouble(strSide1);

     System.Console.Out.Write("Enter the length of the second side: ");
     strSide2 = System.Console.ReadLine();
     side2 = Convert.ToDouble(strSide2);

     // Calculate the hypotenuse
     hyp = calcHypotenuse(side1, side2);

     // Display the result
     System.Console.Out.WriteLine("The length of the hypotenuse is " + hyp);
  }

  public static double calcHypotenuse(double one, double two)
  {
    double hypotenuse = Math.Sqrt(Math.Pow(one, 2) + Math.Pow(two, 2));
    return hypotenuse;
  }
}