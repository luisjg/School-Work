//L G
//Homework 4
//3/24/10
/*PSEUDOCODE: Declare variables. Get user input. Calculate singleTree cost.
				  Calculate treeCost cost. Calculate deliveryCost cost. Calculate total cost.
				  Display formatted results. */
import javax.swing.JOptionPane;
import java.text.DecimalFormat;

public class Trees_final
{
	public static void main (String [] args)
	{
	String input;
	int numTrees;
	int height;
	int delivery;
	double deliveryCost;
	double singleTree;
	double treeCost;
	double total;

	deliveryCost = 0;


	DecimalFormat formatter = new DecimalFormat("#,##0.00");

	input = JOptionPane.showInputDialog("How many trees would you like"
													+ " to purchase?");
	numTrees = Integer.parseInt(input);

	input = JOptionPane.showInputDialog("What is the desired height of the"
													 + " tree (to the nearest foot)?");
	height = Integer.parseInt(input);

	input = JOptionPane.showInputDialog("Will the trees be delivered?\n"
													+ "Please enter 1 for Yes or 0 for No.");
	delivery = Integer.parseInt(input);

	if (height < 3)
	{
	singleTree = 39.00;
	treeCost = singleTree * numTrees;
	}
	else if (height > 3 && height < 5)
	{
	singleTree = 69.50;
	treeCost = singleTree * numTrees;
	}
	else if (height > 6 && height < 8)
	{
	singleTree = 99.00;
	treeCost = singleTree * numTrees;
	}
	else
	{
	singleTree = 199.50;
	treeCost = singleTree * numTrees;
	}
	if (delivery == 1)
	{
		if (numTrees < 5)//to calculate and total with delivery at 10.00
		{
		deliveryCost = 10.00 * numTrees;
		total = treeCost + deliveryCost;
		JOptionPane.showMessageDialog(null, "Green Fields Landscaping\nEvergreen "
											+ "Tree Invoice\n\n" + numTrees + " trees at "
											+ formatter.format(singleTree) + " each:        $"
											+ formatter.format(treeCost) + "\nDelivery Charge: "
											+ "                 $" + formatter.format(deliveryCost) + "\n"
											+ "                                     ----------\n"
											+ "TOTAL:                                $" + formatter.format(total));
		}
		else if (numTrees >= 5)//to calculate and total with delivery at 50.00
		{
		deliveryCost = 50.00 * numTrees;
		total = treeCost + deliveryCost;
		JOptionPane.showMessageDialog(null, "Green Fields Landscaping\nEvergreen "
												+ "Tree Invoice\n\n" + numTrees + " trees at "
												+ formatter.format(singleTree) + " each:        $"
												+ formatter.format(treeCost) + "\nDelivery Charge: "
												+ "                   $" + formatter.format(deliveryCost) + "\n"
												+ "                                      ----------\n"
												+ "TOTAL:                                 $" + formatter.format(total));
		}
	}
	else//to calculate and display total with no delivery.
	{
	total = treeCost;
	JOptionPane.showMessageDialog(null, "Green Fields Landscaping\nEvergreen "
											+ "Tree Invoice\n\n" + numTrees + " trees at "
											+ formatter.format(singleTree) + " each:        $"
											+ formatter.format(treeCost) + "\nDelivery Charge: "
											+ "                   $" + formatter.format(deliveryCost) + "\n"
											+ "                                     ----------\n"
											+ "TOTAL:                               $" + formatter.format(total));
	}
	System.exit(0);
	}
}
