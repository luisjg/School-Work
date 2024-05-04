// Lesson 07 - Assignment
// Author - Mike Orsega
using System;

public class YearInSchool
{

  public static void Main()
  {
	int year, choice;
	String strYear, strChoice;

     	// Get input from the user
     	Console.Out.Write("Enter your year number in school (1 - 4): ");
     	strYear = Console.ReadLine();
     	year = Convert.ToInt32(strYear);

	if (year < 1 || year > 4)
		Console.Out.WriteLine("Invalid year number");
	else
	{
	   Console.Out.Write("\n\nWould you like to use an If (1) or a Switch (2)? ");
	   strChoice = Console.ReadLine();
	   choice = Convert.ToInt32(strChoice);

	   if(choice == 1)
		Console.Out.WriteLine("\n\nUsing an if, you are a " + GetRankIf(year));
	   else
		Console.Out.WriteLine("\n\nUsing a switch, you are a " + GetRankSwitch(year));
	}
  }

  public static String GetRankIf(int _year)
  {
	if (_year == 1)
	  return "Freshman";
	if (_year == 2)
	  return "Sophomore";
	if (_year == 3)
	  return "Junior";
	if (_year == 4)
	  return "Senior";
	return "Error";
  }

  public static String GetRankSwitch(int _year)
  {
	switch(_year)
	{
	  case 1: return "Freshman";
	  case 2: return "Sophomore";
	  case 3: return "Junior";
	  case 4: return "Senior";
	  default: return "Error";
	}
  }

}