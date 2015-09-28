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
				printCase(input);
				try{
					reader = new FileInputStream(file);
					int inChar;
					// read first item size n of the lists and number of people
				  int count = reader.read() - '0';
					// initialize arrays with n we just read
					int[][] preferenceList = new int[2*count][count];
					// start filling up the preferences
					int i=0;
					int j=0;
					while(reader.available() > 0){
						inChar = reader.read() - '0';
						if(inChar >= 0 && inChar <= 9){
							preferenceList[j][i] = inChar;
							i++;
							if(i == count){
								i=0;
								j++;
								if(j == 2*count)
									j=0;
							}
						}
					}
					reader.close();
				} catch(IOException e){
					e.printStackTrace();
				}

			}
			else if(input == 'B'){
				printCase(input);
			}
			else if(input == 'C'){
				System.out.println("What is the size of n?");
			}
			else if(input == 'D'){
				System.out.println("Good Bye.");
			}
			else{
				System.out.println("Error! Try Again!");
			}
		} while(input != 'D');
	}

	public static void printMenu(){
		System.out.println("Welcome to Stable Matching Bruteforce");
		System.out.println("--------------------------------------");
		System.out.println("Please Select an option");
		System.out.println("A) Read first test case");
		System.out.println("B) Read second test case");
		System.out.println("C) Generate Randomly");
		System.out.println("D) Quit");
	}

	public static void printCase(char flag){
		if(flag == 'A')
			System.out.println("Reading first test case...");
		else
			System.out.println("Reading second test case...");
	}
}
