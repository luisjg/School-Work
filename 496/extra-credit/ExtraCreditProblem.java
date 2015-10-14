import java.util.ArrayList;

class ExtraCreditProblem{
  private static ArrayList<Character> mSort = new ArrayList<>();

  public static void main(String[] args){
    // problem 4a
    int size=5;
    char[] label ={'a','b','c','d','e'};
    int[][] graph={{0,0,0,1,0},
                   {1,0,1,0,0},
                   {0,0,0,0,0},
                   {0,0,1,0,0},
                   {1,0,0,1,0}};
    //made up problem
    int madeUpSize=10;
    char[] madeUpLabel={'0','1','2','3','4','5','6','7','8','9'};
    int[][] madeUp= {{0,1,0,0,0,0,1,1,0,0},
    		         {0,0,0,1,1,0,1,0,0,0},
    		         {0,0,0,0,1,0,0,0,0,1},
    		         {0,0,0,0,0,0,0,0,0,0},
    		         {0,0,0,0,0,1,0,0,1,0},
    	           {0,0,0,0,0,0,0,0,0,0},
    		         {0,0,1,0,0,0,0,0,0,0},
    		         {0,0,0,1,0,0,0,0,0,0},
    		         {0,0,0,1,0,0,0,0,0,0},
    	           {0,0,0,0,0,1,0,0,0,0}};

    System.out.println("Original matrix, problem 4");
    printArray(graph,size);
    System.out.println();

    /*solve problem 4*/
    topologicalSort(graph, label, size);

    //print the array and the sorted list
    System.out.println("Empty Matrix denoted by -1");
    printArray(graph, size);

    System.out.println("\nSort order: ");
    printArrayList(mSort);
    System.out.println();
    mSort.clear();

    System.out.println("Original matrix, made up");
    printArray(madeUp, madeUpSize);
    System.out.println();

    /*solve made up problem*/
    topologicalSort(madeUp, madeUpLabel, madeUpSize);

    //print the array and the sorted list
    System.out.println("Empty Matrix denoted by -1");
    printArray(madeUp, madeUpSize);

    System.out.println("\nSort order: ");
    printArrayList(mSort);
    System.out.println();
    mSort.clear();

  }

  //prints an arbitrary 2 dimensional int array with size s
  public static void printArray(int[][] print, int s){
    for(int i=0; i<s; i++){
      for(int k=0; k<s; k++)
        System.out.print(print[i][k] + " ");
    System.out.println();
    }
  }

  //Topological Sort
  public static void topologicalSort(int[][] graph, char[] label, int size){
	//look for columns that have all 0's
	    int i=0;
	    int count=0;
	    while(i<size){
	      //traverse the column starting at i=0
	      for(int k=0; k<size; k++){
	    	//count the number of 0's in the column
	        if(graph[k][i] == 0){
	          count++;
	        }
	        //if the number of 0's equals the size of n
	        //meaning we found a column with n number of 0's
	        //which would mean a node with no incoming edges
	        if(count == size){
	          //traverse the row's j using column i
	          for(int j=0;j<size;j++){
	        	//delete the 1's that correspond to node i
	            if(graph[i][j] == 1)
	              graph[i][j] = 0;
	            //delete node i column by marking it as -1
	            graph[j][i]=-1;
	          }
	          //add the node we just found to the arraylist
	          mSort.add(label[i]);
	          //in order to traverse the columns from the
	          //beginning, we must reset i
	          i=-1;
	        }
	      }
	      //reset the count and increment i
	      count=0;
	      i++;
	    }
  }

  //prints a char ArrayList
  public static void printArrayList(ArrayList<Character> print){
	  for(int i=0; i<print.size(); i++)
		  System.out.print(print.get(i) + " ");
	  System.out.println();
  }
}
