public class RainFall {
	private double[] rainFall;
	public RainFall(double[] r){
		rainFall = new double[r.length];
		for(int i = 0; i < r.length; i++){
			rainFall[i] = r[i];
		}//for
	}//RainFall()
	public double getTotal(){
		double total = 0.0;
		for(int i = 0; i < rainFall.length; i++){
			total += rainFall[i];
		}//for
	return total;
	}//getTotal()
	public double getAverage(){
		return getTotal() / rainFall.length;
	}//getAverage()
	public String getHighestMonth(){
		int highest = 0;
		for(int i = 1; i < rainFall.length; i++){
			if(rainFall[i] > rainFall[highest]){
			highest = i;
			}//if
		}//for
	return getMonth(highest);
	}//getHighestMonth()
	/**
	 * switch to get the month names instead of index value*/
	private String getMonth(int monthName) {
		switch (monthName){
		case 0 : return "month 1";
		case 1 : return "month 2";
		case 2 : return "month 3";
		case 3 : return "month 4";
		case 4 : return "month 5";
		case 5 : return "month 6";
		case 6 : return "month 7";
		case 7 : return "month 8";
		case 8 : return "month 9";
		case 9 : return "month 10";
		case 10 : return "month 11";
		case 11 : return "month 12";
		default : return "Error";
		}//switch
	}//getMonth()
	public String getLowestMonth(){
		int lowest = 0;
		for(int i = 1; i < rainFall.length; i++){
			if(rainFall[i] < rainFall[lowest]){
				lowest = i;
			}//if
		}//for()
	return getMonth(lowest);
	}//getLowestMonth()
}//RainFall class
