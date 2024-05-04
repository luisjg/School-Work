import java.util.Scanner;
public class blah
{
	public static void main (String args [])
	{
		int rooms = 0;
		int maxFloors = 0;
		int totalRooms = 0;
		
		Scanner choice = new Scanner(System.in);
		System.out.println("How many floors does the hotel have?");
		maxFloors = choice.nextInt();
		
		while (maxFloors < 1)
		{
		System.out.println("You have entered an invalid number. "
								  + "Please try again.\nHow many floors"
								  + "does the hotel have?");
		maxFloors = choice.nextInt();
		}
		
		for(int counter = 1; counter <= maxFloors; counter++)
		{
			if (counter < 13 || counter > 13)
			{
			System.out.println("How many rooms are in floor " + counter + "?");
			rooms = choice.nextInt();
			
			while (rooms < 10)
			{
			System.out.println("You have entered an invalid number. Please Try again.\n" + 
									"How many rooms are in floor " + counter + "?");
			rooms = choice.nextInt();
			}
			totalRooms = totalRooms + rooms;
			}
		}
		System.out.println("The total is: " + totalRooms);
		System.out.println("Percent");
	}
}
