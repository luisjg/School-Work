import javax.swing.JOptionPane;


public class RoomDemo {
		public static void main(String[] args) {
			String input;
			double length;
			double width;
			double price;
			input = JOptionPane.showInputDialog("Please enter the length of the carpet");
			if (input == null){
				System.exit(0);
			}//if null
			if (!input.isEmpty()){
			length = Double.parseDouble(input);
			while (length < 0){
				input = JOptionPane.showInputDialog("You have entered an " +
						"invalid number.\nTry again.\nPlease enter the length of the carpet");
				length = Double.parseDouble(input);
				}//while
			}//if !input.isEmpty()
			length = Double.parseDouble(input);
			
			input = JOptionPane.showInputDialog("Please enter the width of the carpet");
			if (input == null){
				System.exit(0);
			}//if null
			if (!input.isEmpty()){
			width = Double.parseDouble(input);
			while (width < 0){
				input = JOptionPane.showInputDialog("You have envered an + " +
						"invalid number.\nTry again.\nPlease enter the width of the carpet");
				width = Double.parseDouble(input);
				}//while
			}//if !input.isEmpty()
			width = Double.parseDouble(input);
			if (input == null){
				System.exit(0);
			}//if null
			input = JOptionPane.showInputDialog("Please enter the price per square foot of the carpet");
			if (!input.isEmpty()){
				price = Double.parseDouble(input);	
			while (width < 0){
				input = JOptionPane.showInputDialog("You have envered an + " +
				"invalid number.\nTry again.\nPlease enter the price per square" +
				"foot of the carpet");
				price = Double.parseDouble(input);
				}//while
			}//if !input.isEmpty()
			price = Double.parseDouble(input);
			RoomDimension roomDimension = new RoomDimension(length, width);
			RoomCarpet roomCarpet = new RoomCarpet(roomDimension, price);
			
			JOptionPane.showMessageDialog(null, roomCarpet.toString());
			System.exit(0);
	}//main()
}//class RoomDemo
