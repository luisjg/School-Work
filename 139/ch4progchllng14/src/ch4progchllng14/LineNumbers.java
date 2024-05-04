package ch4progchllng14;
import javax.swing.*;
import java.io.*;
import java.util.Scanner;

/**
 * @author Luis Guzman
 *
 */
public class LineNumbers {

	/**
	 * @param args
	 * @throws FileNotFoundException 
	 */
	public static void main(String[] args) throws FileNotFoundException {
		//ask user to enter the file name
		String filename = JOptionPane.showInputDialog("Please enter the file name.");
		File inputfile = new File(filename);
		
		//check if file exhists
		while(inputfile == null || !inputfile.exists()){
			filename = JOptionPane.showInputDialog("File not found, please try again.\nPlease enter file name.");
			inputfile = new File(filename);
			
		}//end of while
		Scanner input = new Scanner(inputfile);
		int LineCounter = 0;
		int x = 1;
		
		// display the file contents
		//file only has seven lines
		while (LineCounter < 7 && input.hasNext())
		{
			System.out.println(input.nextLine() + " " + x + ";");
			LineCounter++;
			x++;	
		}//end of while

	System.exit(0);
	}//end of main
}//end of LineNumbersm
