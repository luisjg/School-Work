import java.util.ArrayList;

class ExtraCreditProblem{
  public static void main(String[] args){
    // problem 4a
    int size=5;
    char[] label ={'a','b','c','d','e'};
    ArrayList<Character> sort=new ArrayList<>();
    int[][] graph={{0,0,0,1,0},
                   {1,0,1,0,0},
                   {0,0,0,0,0},
                   {0,0,1,0,0},
                   {1,0,0,1,0}};

    // look for columns that have all 0's
    int i=0;
    int count=0;
    while(i<size){
      for(int k=0; k<size; k++){
        if(graph[k][i] == 0){
          count++;
        }
        if(count == size){
          for(int j=0;j<size;j++){
            if(graph[i][j] == 1)
              graph[i][j] = 0;
            graph[j][i]=-1;
          }
          sort.add(label[i]);
          i=-1;
        }
      }
      count=0;
      i++;
    }

    for(int k=0;k<sort.size();k++)
      System.out.println(sort.get(k));
  }

  public static void printArray(int[][] print,int s){
    for(int i=0; i<s; i++){
      for(int k=0; k<s; k++)
        System.out.print(print[i][k] + " ");
    System.out.println();
    }
  }

  public static void printMenu(){

  }
}
