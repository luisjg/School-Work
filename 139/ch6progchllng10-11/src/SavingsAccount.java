
public class SavingsAccount {
	//fields
	private double annualInterestRate;
	private double balance;
	
	//constructors
	public SavingsAccount(){
		annualInterestRate = 0.0D;
		balance = 0.0D;
		
	}//SavingsAccount
	public SavingsAccount(double startingBalance){
		annualInterestRate = 0.0D;
		balance = startingBalance;
	}//SavingsAccount(double)
	
	//methods
	public void deposit(double amount){
		balance += amount;
	}//deposit(double)
	
	public void withdraw(double amount){
		balance -= amount;
	}//deposit(double)
	
	public void addMonthlyInterest(){
		balance *= (1 + annualInterestRate / 12D);
	}////addMonthlyInterest
	
	public void setAnnualInterestRate(double interestRate){
		this.annualInterestRate = interestRate;
	}//setAnnualInterestRate(double)
	
	public double getBalance(){
		return(this.balance);
	}//getBalance()
	
}//class SavingsAccount