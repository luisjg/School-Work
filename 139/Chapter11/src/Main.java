
public class Main {
	public static void main(String[] args) {
		Exam[] exams = new Exam[3];
		exams[0] = new Exam(1.0);
		exams[1] = new Exam(2.0);
		exams[2] = new MidtermExam();
		
		for (int i = 0; i < exams.length; i++){
			exams[i].printInfo();
		}//for
		
		
//		Exam exam = new Exam(0);
//		System.out.println();
//		MidtermExam mexam = new MidtermExam();
	}//main
}//class Main
