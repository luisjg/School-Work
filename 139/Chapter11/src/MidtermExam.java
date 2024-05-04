
public class MidtermExam extends Exam {
	public MidtermExam() {
		super(0);
//		System.out.println("Creating a MidtermExam object");
		setScore(0);
	}//MidtermExam()
	protected void setScore(double d){
//		System.out.println("Setting the store to " + d + " in MidtermExam class.");
		this.score = d;
	}//setScore() Override
	protected void printInfo(){
		System.out.println("This is a MitermExam.");
	}// printInfo()
}//class MidtermExam
