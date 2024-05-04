public class Numbers
{
	public static void main (String [] args)
	{
	int x;
	x = 10;
	String message = "The loop has executed!";

	while (x < 50)
	{
	System.out.println(message);
	x = x + 10;
	}
	System.out.println("x = " + x);
	}
}