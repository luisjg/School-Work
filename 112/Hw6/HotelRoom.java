//L G
//5/5/10

/*PSEUDOCODE: Display message on screen that asks user for number of floors
Save input in variable. Validate input with input validation. Start loop that
displays message to user for rooms on each floor. Save input to variable
Validate input with input validation. Display message that asks user for number
of occupied rooms. Save input to variable. Calculate values. Display results on
screen.*/

import java.text.DecimalFormat;
import java.util.Scanner;
public class HotelRoom
{
	public static void main (String [] args)
	{
		//declare and initialize variables
		int maxFloors;
		int rooms = 0;
		int filledRooms = 0;
		int totalRooms = 0;
		int occupiedRooms = 0;
		double roomPercent = 0;

		DecimalFormat formatter = new DecimalFormat("#0");
		Scanner choice = new Scanner (System.in);

		//display error message on screen and ask user for new input
		//save the new input in variable
		System.out.println("How many floors does the hotel have?");
		maxFloors = choice.nextInt();

		//input validation
		while (maxFloors < 1)
		{
			//display error message
			//ask user for new input and save it to variable
			System.out.println("You have entered an invalid number.\n"
										+ "Please try again.");
			maxFloors = choice.nextInt();
		}
			//loop start
			//asks user for number of rooms empty and filled
			for (int counter = 1; counter <= maxFloors; counter++)
			{
				//used to skip the 13th floor
				if (counter < 13 || counter > 13)
				{
				System.out.println("How many rooms are there in floor "
										+ counter + "?");
				rooms = choice.nextInt();

					//input validation
					while (rooms < 10)
					{
					//display error message on screen
					//ask user for new input and save it to variable
					System.out.println("You have entered an invalid value."
										+ "\nHow many rooms are there in floor "
										+ counter);
					rooms = choice.nextInt();
					}
				//display message on screen
				//save user input in variable
				System.out.println("How many rooms are occupied?");
				filledRooms = choice.nextInt();

				//to calculate totalRooms
				totalRooms = totalRooms + rooms;
				//to calculate occupied rooms
				occupiedRooms = occupiedRooms + filledRooms;
				//to calculate roomPercent
				roomPercent = ((double)occupiedRooms / totalRooms) * 100;
				}

			}
		//display value of totalRooms, occupiedRooms and formatted roomPercent
		//on screen
		System.out.println("The Hotel has " + totalRooms + " Total Rooms\n"
								 + occupiedRooms + " of the Rooms are Occupied.\n"
								 + formatter.format(roomPercent)
								 + " % of the Rooms are Occupied.");
	}
}
