import javax.swing.JOptionPane;


public class LandTract {
	private double length;
	private double width;

	public double area(){
		return (length * width);
	}//area()
	
	public boolean equals(LandTract obj){
//		return(length == obj.length && width == obj.width); //to compare lengths/widths
		return(area() == obj.area());//to compare areas
	}//equals()
	
	public String toString(){
		return("LandTrac width=" + width + ", length=" + length + ".");
	}//toString()
	
	public boolean userInput(){
		String len = JOptionPane.showInputDialog("Please enter the length");
		if(len == null){
			return(false);
		}//if len null
		double dbllength = Double.parseDouble(len);
		String wid = JOptionPane.showInputDialog("Please enter the width");
		if(wid == null){
			return(false);
		}//if wid null
		double dblwidth = Double.parseDouble(wid);
		this.length = dbllength;
		this.width = dblwidth;
		return(true);
	}//userInput()
}