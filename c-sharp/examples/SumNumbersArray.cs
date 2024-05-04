// Lesson 09 - Assignment
// Author - Mike Orsega
using System;

public class SumNumbersArray
{

   public static void Main()
   {
      int[] numbers = new int[100];
      int number, count = 0;
      double sum= 0.0, average;
      String strNumber;

      do
      {
         // Get input from the user
         Console.Out.Write("Enter a number (999 to quit): ");
         strNumber = Console.ReadLine();
         number = Convert.ToInt32(strNumber);

         // Store the user's input
         numbers[count] = number;
         // Increment the variable that's keeping track of the
         //  number of user's numbers (we'll use it later)
         count++;
      } while(count < numbers.Length && number != 999);

      // Check to see if the user entered 999 to exit early
      if (number == 999)
      {
         // The user entered 999 to quit, don't include that
         //  value in the average calculation.  NOTE
         //  the 999 is still in the array, but we won't
         //  look at it when calculating the average
         count = count - 1;
      }

      // Compute the sum all all numbers entered.  NOTE: This is
      //  different than the size of the array (the number of possible spots
      //  to put a number) because the user may have only entered 'count'
      //  values
      for(int i=0; i < count; i++)
      {
         sum = sum + numbers[i];
      }

      // Make sure the user entered at least one number
      if (count > 0)
      {	
         // The average is the sum of the numbers divided by the number of numbers
         average = sum / count;
         // Display the result.  Note: \n is the newline character and each one will
         //  advance the output cursor one line - which helps break up the output for the user
         Console.Out.WriteLine("\n\nThe average of your numbers is " + average);
      }
      else
      {
         Console.Out.WriteLine("\n\nNo numbers were entered, so no average can be calculated.");
      }
  }
}