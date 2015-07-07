//L G
//3/10/10
/*PSEUDOCODE
Store 105.62 in the variable firstnum.
Store 89.352 in the variable secondnum.
Store 98.67 in the variable thirdnum.
Add firstnum + secondnum + thirdnum and store the result in the total variable.
Divide total by 3.0 and store the result in average variable.
Display on the screen The total is total variable on first line.
Display on the screen The average is average variable on second line.*/

public class Numbers
{
	public static void main (String[] args)
	{
		double firstnum = 105.62;
		double secondnum = 89.352;
		double thirdnum = 98.67;
		double total = firstnum + secondnum + thirdnum;
		double average = total / 3.0;

		System.out.println("The total is " +total +".");
		System.out.print("The average is " +average +".");
	}


}
