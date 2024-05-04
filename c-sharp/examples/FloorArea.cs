// Lesson 03 - Assignment
// Author - Mike Orsega

public class FloorArea
{
  public static void Main()
  {
     // Declare Variables
     double length, width, area, cost, total;
     string strLength, strWidth, strCost;

     // Get input from the user
     System.Console.Out.Write("Enter the length of the room in feet: ");
     strLength = System.Console.ReadLine();
     length = System.Convert.ToDouble(strLength);

     System.Console.Out.Write("Enter the width of the room in feet: ");
     strWidth = System.Console.ReadLine();
     width = System.Convert.ToDouble(strWidth);

     System.Console.Out.Write("Enter the cost of the carpet per square foot: ");
     strCost = System.Console.ReadLine();
     cost = System.Convert.ToDouble(strCost);


     // Calculate the area
     area = length * width;

     // Calculate the total cost
     total = area * cost;

     // Display the result
     System.Console.Out.WriteLine("The area is " + area);
     System.Console.Out.WriteLine("The total cost is $" + total);
  }
}