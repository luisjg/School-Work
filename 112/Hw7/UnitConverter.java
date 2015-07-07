import java.util.Scanner;
public class UnitConverter
{
	public static void main (String [] args)
	{
	int choice;
	Scanner keyboard = new Scanner(System.in);
	showMenu(input);
	}
	public static int showMenu(input)
	{
	System.out.println("METER CONVERSION");
	System.out.println("1) Convert to Kilometers");
	System.out.println("2) Convert to Inches");
	System.out.println("3) Convert to Feet");
	System.out.println("4) Quit the Program");
	System.out.println("\nPlease make a selection:");
	return choice = keyboard.nextInt();

	}
	
}