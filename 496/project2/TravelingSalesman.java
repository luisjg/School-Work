import java.util.ArrayList;
import java.util.List;

public class TravellingSalesman {
	private static final int BRUTE_FORCE = 0;
	private static final int GREEDY_METHOD = 1;
	private static final int MST_METHOD = 2;
	private static double mTotal = 0.0;
	private static double[] locx = { 20.0, 3.0, 10.0, 15.0, 20.0, 25.0, 30.0 };
	private static double[] locy = { 68.0, 10.0, 50.0, 100.0, 30.0, 110.0, 70.0 };
	private static String[] cityNames = { "A", "B", "C", "D", "E", "F", "G" };
	private static int n = 7; // 7 cities

	public static void main(String[] args) {
		double[][] G = new double[n][n];
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				G[i][j] = CalculateDistances(locx[i], locy[i], locx[j], locy[j]);
			}
		}

//		printArray(G,n);
		BruteForceMethod(G);
		GreedyMethod();
		MinimumSpanningTreeMethod();
	}

	public static void BruteForceMethod(double[][] G) {
		List<List<String>> order = new ArrayList<List<String>>();
		int[] tour = new int[n + 1];
		int[] temp = new int[n + 1];
		// permute the entire list
		order = permute(cityNames);

		// only get the tours that start and end with node 0
		// calculate the tour cost, and keep track of which is
		// the minimum cost
		int j = 0;
		int k = 0;
		double total = 0.0;
		for (List<String> row : order) {
			for (int i = 0; i < row.size(); i++) {
				if (row.get(0).equals("A")) {
					// initialize the total
					k = getNextNode(cityNames, n, row.get(i));
					temp[i] = k;
					total += G[j][k];
					j = k;
				}
			}
			//
			if (row.get(0).equals("A")) {
				temp[n] = 0;
				total += G[j][0];
				if (mTotal == 0)
					mTotal = total;
				else if (mTotal >= total){
					mTotal = total;
					System.arraycopy(temp, 0, tour, 0, temp.length);
				}
				total = 0;
			}
		}
		printOut(tour, BRUTE_FORCE);
	}

	public static void GreedyMethod() {
		System.out.println("\nGreedyMethod");
	}

	public static void MinimumSpanningTreeMethod() {
		System.out.println("\nMinimum Spanning Tree");
	}

	/* ((y2 - y1)^2 + (x2 - x1)^2)^1/2 */
	public static double CalculateDistances(double x1, double y1, double x2, double y2) {
		double distance;
		distance=Math.sqrt(Math.pow(x2-x1, 2) + Math.pow(y2-y1, 2));
//		distance = Math.hypot((y2 - y1), (x2 - x1));
		return distance;
	}

	public static int getNextNode(String[] cityNames, int size, String value) {
		int position = 0;
		for (int i = 0; i < size; i++) {
			if (cityNames[i].equals(value))
				position = i;
		}
		return position;
	}

	public static void printOut(int[] tour, int type) {
		switch (type) {
		case MST_METHOD:
			System.out.println("MST Tour: " + n + " Cities");
			break;
		case GREEDY_METHOD:
			System.out.println("Best Greedy Tour: " + n + " Cities");
			break;
		default:
			System.out.println("Optimal Tour: " + n + " Cities");
			break;
		}
		System.out.println("Min Cost: " + mTotal);

		for (int i = 0; i < tour.length; i++) {
			System.out.print(tour[i] + " ");
		}
		System.out.println();
		for (int j = 0; j < n; j++)
			System.out.print(cityNames[tour[j]] + " ");
		System.out.println(cityNames[0]);

		mTotal = 0;
	}

	// prints an arbitrary 2 dimensional int array with size s
	public static void printArray(double[][] print, int s) {
		for (int i = 0; i < s; i++) {
			for (int k = 0; k < s; k++)
				System.out.print(print[i][k] + " ");
			System.out.println();
		}
	}

	/*
	 * Permutation code source http://codereview.stackexchange.com/a/68735 O(n *
	 * n!)
	 */
	public static List<List<String>> permute(String[] cityNames) {
		// we use a list of lists rather than a list of arrays
		// because lists support adding in the middle
		// and track current length
		List<List<String>> permutations = new ArrayList<List<String>>();
		// Add an empty list so that the middle for loop runs
		permutations.add(new ArrayList<String>());

		for (int i = 0; i < cityNames.length; i++) {
			// create a temporary container to hold the new permutations
			// while we iterate over the old ones
			List<List<String>> current = new ArrayList<List<String>>();
			for (List<String> permutation : permutations) {
				for (int j = 0, n = permutation.size() + 1; j < n; j++) {
					List<String> temp = new ArrayList<String>(permutation);
					temp.add(j, cityNames[i]);
					current.add(temp);
				}
			}
			permutations = new ArrayList<List<String>>(current);
		}
		return permutations;
	}
}
