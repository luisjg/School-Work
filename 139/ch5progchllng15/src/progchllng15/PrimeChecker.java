/**
 * 
 */
package progchllng15;

import java.io.File;

import javax.swing.JOptionPane;

/**
 * @author Luis GUzman
 *
 */
public class PrimeChecker {
	public static void main(String[] args) {
		boolean cond = true;
		String input;
		int userValue;
		
		while (cond){
			input = JOptionPane.showInputDialog("Welcome to Prime Checker." +
					"\n\nPlease enter the number 1 to start the program." + 
					"\nAny other number will quit the program.");
			
			if (!input.equals("1")){
					cond = false;
			}
				else
				{
						userValue = Integer.parseInt(input);
						primeNumbers(userValue);
//						System.out.println(userValue);
//						JOptionPane.showMessageDialog(null, "That is " + (isPrime(userValue) ? "" : "not ") + "a prime number.");
				}
//			if (isPrime(userValue))
//			{
//				JOptionPane.showMessageDialog(null, "That is a Prime number");
//			}
//			else
//			{
//				JOptionPane.showMessageDialog(null, "This is not a prime number");
//			}
		}//end while
System.exit(0);
}//end main
	
	public static boolean isPrime(int number){
	boolean primeFlag = true;
	int i = 2;
		while (i < (number / 2) && primeFlag){
			primeFlag = (number % i !=0);
			i++;
		}
//	for (int i = 2; i < number - 1; i++)
//	{
//		if (number % i == 0)
//		{
//			primeFlag = false;
//			break;
//		}
//	}//for
			return(primeFlag);
	}//end isPrime()
	public static void primeNumbers(int num){
		int i = 1;
		while (i <= 100){
		File prime = new File(System.out, true);
		;
		i++;
		}//while
	}
}//end PrimeChecker