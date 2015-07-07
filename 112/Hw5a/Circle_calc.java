//L G
//4/16/10
/*PSEUDOCODE: Display Circle Calculator Menu. Save the user input in
				  choice variable. If choice 1 ask user for the radius
				  and save it in the radius variable. Calculate pi*radius *radius
				  and save it in the area variable. Display The Area of the circle
				  is the formatted area variable on screen.
				  If choice 2 ask user for radius and save it in the radius variable.
				  Calculate the circumference and save it in the circumference
				  variable. Diplay The circumference of the cirlce is the formatted
				  circumference variable on screen. If choice 3 display You have
				  chosen to quit the program. Set a default to display You have
				  entered an invalid selection.*/

import java.util.Scanner;
import java.text.DecimalFormat;

public class Circle_calc
{
	public static void main (String [] args)
	{
	//declare variables.
	int choice;
	int radius;
	double area;
	double circumference;
	Scanner keyboard = new Scanner(System.in);

	//format pattern to four decimal places.
	DecimalFormat formatter = new DecimalFormat("#0.0000");

	//display the menu to user.
	System.out.println("CIRCLE CALCULATOR MENU:");
	System.out.println("1)\tCalculate the Area of a Circle.");
	System.out.println("2)\tCalculate the Circumference of a Circle.");
	System.out.println("3)\tQuit the Program.");
	System.out.println("\nMake a selection by choosing a number:");

	//save user input in choice variable.
	choice = keyboard.nextInt();

	if (choice == 1) //to calculate the Area
	{
	System.out.println("What is the Radius of the Circle?");
	radius = keyboard.nextInt();
	area = Math.PI * radius * radius;
	//diplay the message and the formatted area variable.
	System.out.println("The Area of the circle is "
								+ formatter.format(area));
	}
	else if (choice == 2) //to calculate the Circumference.
	{
	System.out.println("What is the Radius of the Circle?");
	radius = keyboard.nextInt();
	circumference = 2 * radius * Math.PI;
	//diplay the message and the formatted circumference variable.
	System.out.println("The Circumference of the circle is "
								+ formatter.format(circumference));
	}
	else if (choice == 3) //display the quit program message.
	{
	System.out.print("You have chosen to quit the program.");
	}
	else //display the default message.
	{
	System.out.print("You have made an invalid selection.");
	}

	}
}
