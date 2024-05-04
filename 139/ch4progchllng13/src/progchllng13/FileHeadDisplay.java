/**
 * 
 */
package progchllng13;
import javax.swing.*;
import java.io.*;
import java.util.Scanner;
/**
 * @author Luis Guzman
 *
 */
public class FileHeadDisplay {

	/**
	 * @param args
	 * @throws FileNotFoundException 
	 */
	public static void main(String[] args) throws FileNotFoundException {
		String filename = JOptionPane.showInputDialog("Please enter the file name.");
//		JOptionPane.showMessageDialog(null, filename);
		File inputfile = new File(filename);
		while (!inputfile.exists())
		{
			JOptionPane.showInputDialog("File not found. Please try again.\nPlease enter file name.");
			inputfile = new File(filename);
		}
		Scanner input = new Scanner(inputfile);
		int LineCounter = 0;
			
			while (LineCounter < 5 && input.hasNext())
				{
					JOptionPane.showMessageDialog(null, input.hasNext());
					LineCounter++;
				}
System.exit(0);
	}//end of main
}//end of FileHeadDisplay
