public class LandTractDemo {
	public static void main(String[] args) {
		LandTract lt1, lt2;
		lt1 = new LandTract();
		lt2 = new LandTract();
		if(!lt1.userInput()){
			return;
		}
		if(!lt2.userInput()){
			return;
		}
		System.out.println("Land Tract #1 has the area of "
				+ lt1.area());
		System.out.println("Land Tract #2 has the area of "
				+ lt2.area());
		if(lt1.equals(lt2)){
			System.out.println("The two Land Tract's are equal.");
		}
		else {
			System.out.println("The two Land Tract's are not equal.");
		}
	}//main()
}//class LandTractDemo
