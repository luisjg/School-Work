//This program gets the number of movie tickets sold for the past 7 days and then computes//the total movie tickets sold for the entire week
import java.util.Scanner;
public class MovieTickets
{   
public static void main(String[] args)
   {     
			//declare variables
	      Scanner keyboard = new Scanner(System.in);
			int dailyTickets;
			int totalTickets = 0;  //initialize the total tickets to zero, this is
			                       //the accumulator variable we'll keep our running total in
			int numDays = 1;       //this is our while loop counter
			
			//loop will ask the user for the number of tickets sold each day, print
			//the number of tickets sold each day and
			//then calculate and print the total tickets sold for the week
			while(numDays <= 7)
			{    
				System.out.println("Please enter the tickets sold on day " + numDays + ":");
				dailyTickets = keyboard.nextInt();
				
				//add the number of tickets sold that day to the overall total
				totalTickets = totalTickets + dailyTickets;
				numDays++;  //our counter so our loop will terminate properly
			}
			
			//WHY IS THIS OUTSIDE THE LOOP?  WE ONLY WANT TO PRINT THE TOTAL ONCE
			//AFTER THE DAILY TICKETS FOR EACH DAY HAVE BEEN ADDED
			System.out.println("The total tickets sold for the week = " + totalTickets);
		}
}
