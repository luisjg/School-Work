public class RoomDimension {
	private double length;
	private double width;
	public RoomDimension(double len, double wid){
		length = len;
		width = wid;
	}//RoomDimension()
	public double getArea(){
		return (length * width);
	}//getArea()
	public String toString(){
		return("The carpet width= " + width + ", length= " + length + ".");
	}//toString()
}//class RoomDimension
