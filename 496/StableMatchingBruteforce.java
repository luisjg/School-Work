import java.io.File;
import java.io.FileInputStream;
import java.io.IOException;
import java.util.Scanner;

public class StableMatchingBruteforce{

	public static void main(String[] args){
		char input;
		Scanner keyboard = new Scanner(System.in);
		File file = new File("input.txt");
		FileInputStream reader = null;
		do{
			printMenu();
			input = keyboard.next().charAt(0);
			if(input == 'A'){
				System.out.println("Reading from input.txt...");
				System.out.println("Items read:");
				try{
					reader = new FileInputStream(file);
					int inChar;
					// read first item size n of the lists and number of people
					int count = reader.read() - '0';
					System.out.println("N = " + count);
					// initialize array with n we just read
					int[][] priorityList = new int[count][count];
					// start filling up the array
					int j = 0;
					// for(int i = 0; i<count; i++){
						while(reader.available() > 0){
							inChar = reader.read() -'0';
							if(inChar >= 0 && inChar <= 9){
								// priorityList[j][i] = inChar;
								System.out.print(inChar);
								if((j%count) == 0){
									System.out.println("\nJ = " + j);
									j++;
								}
							}
						}
					// }
					System.out.println();
					// reader.close();
					// System.gc();
				} catch(IOException e){
					e.printStackTrace();
				}

			}
			else if(input == 'B'){
				System.out.println("You chose B.\n");
			}
			else if(input == 'C'){
				System.out.println("Good Bye.");
			}
			else{
				System.out.println("Error! Try Again!");
			}
		}while(input != 'C');
	}

	public static void printMenu(){
		System.out.println("Welcome to Stable Matching Bruteforce");
		System.out.println("--------------------------------------");
		System.out.println("Please Select an option");
		System.out.println("A) Read from input.txt");
		System.out.println("B) Generate Randomly");
		System.out.println("C) Quit");
	}
}
