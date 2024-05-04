import java.text.*;
public class RoomCarpet {
	private double carpetCost;
	private RoomDimension size;
	public RoomCarpet(RoomDimension dim, double cost){
		carpetCost = cost;
		size = dim;
	}//RoomCarpet()
	public double getTotalCost(){
		double price;
		price = (carpetCost * size.getArea());
		return price;
	}//getTotalCost()
	public String toString(){
		DecimalFormat formatter = new DecimalFormat("#0.00");
		return("The carpet cost is $" + formatter.format(getTotalCost()) + ".");
	}//toString()
}//class RoomCarpet
