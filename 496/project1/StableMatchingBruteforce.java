import java.io.File;
import java.io.FileInputStream;
import java.io.IOException;
import java.util.Scanner;

public class StableMatchingBruteforce{

	public static void main(String[] args){
		char input;
		int inChar;
		int count;
		Scanner keyboard = new Scanner(System.in);
		File file = null;
		FileInputStream reader = null;
		do{
			printMenu();
			input = keyboard.next().charAt(0);
			if(input == 'A'){
				printCase(input);
				try{
					file = new file("testcase0.txt");
					reader = new FileInputStream(file);
					// read first item size n of the lists and number of people
				  count = reader.read() - '0';
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
				try{
					file = new file("testcase1.txt");
					reader = new FileInputStream(file);
					// read first item size n of the lists and number of people
					count = reader.read() - '0';
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
			else if(input == 'C'){
				printCase(input);
				try{
					file = new file("testcase2.txt");
					reader = new FileInputStream(file);
					// read first item size n of the lists and number of people
					count = reader.read() - '0';
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
			else if(input == 'D'){
				System.out.println("What is the size of n?");
			}
			else if(input == 'E'){
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
		System.out.println("A) Read test case 0")
		System.out.println("B) Read test case 1");
		System.out.println("C) Read test case 2");
		System.out.println("D) Generate Randomly");
		System.out.println("E) Quit");
	}

	public static void printCase(char flag){
		if(flag == 'A')
			System.out.println("Reading test case 0...");
		else if(flag == 'B')
			System.out.println("Reading test case 1...");
		else
			System.out.println("Reading test case 2...");
	}
}
