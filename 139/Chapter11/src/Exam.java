
public class Exam {
	protected double score;
	public Exam(double d){
//		System.out.println("Creating an Exam object");
		setScore(d);
	}//Exam()
	protected void setScore(double d){
//		System.out.println("Setting the store to " + d + " in Exam class.");
		this.score = d;
	}//setScore Overridden
	protected void printInfo(){
		System.out.println("This is an Exam.");
	}// printInfo()
}//class Exam