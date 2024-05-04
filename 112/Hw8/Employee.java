public class Employee
{
private String name;
private String idNumber;
private String department;
private String position;
private int yearsWorked;

public Employee (String name, String idNumber)
{

}
public Employee ()
{
}

	public void setYears(int y)
	{
	if (yearsWorked > 0)
	{
	yearsWorked = y;
	}
	else
	{
	yearsWorked = 0;
	}
	}
}