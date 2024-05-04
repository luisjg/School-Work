
public abstract class BankAccount {
	double balance;
	double deposit;
	double withdrawal;
	double annualInterest;
	double monthlyCharges;
	public BankAccount(double bal, double interest){
	balance = bal;
	annualInterest = interest;
	}
	public double deposit(double depos){
		deposit += depos;
		return deposit;
	}
	public double withdraw(double withd){
		withdrawal -= withd;
		return withdrawal;
	}
	public double calcInterest(){
		double monthlyIntRate;
		double monthlyInterest;
		monthlyIntRate = (annualInterest/12);
		monthlyInterest = balance * monthlyIntRate;
		balance = balance + monthlyInterest;
		return balance;
	}
	public void monthlyProcess(){
		monthlyCharges = balance - monthlyCharges;
		calcInterest();
		monthlyCharges = 0.0;
		balance = 0.0;
		withdrawal = 0.0;
	}
}
