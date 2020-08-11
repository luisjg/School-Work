#include <iostream>
#include "QueueP.h"
#include "StackP.h"
using namespace std;

// Simulate customers lining up for a movie
//   One movie uses a stack to line up customers
//   Other movie uses a queue to line up customers
//   Will see which will cause the longest wait

int main()
{
  Stack aStack;
  Queue aQueue;

  cout << "Please enter seed for movie line simulaton: ";
  int seed;
  cin >> seed;
  srand(seed);

  customer movie;
  int num1, num2;
  int longestWait1 = 0;    // longest wait for stack movie
  int longestWait2 = 0;    // longest wait for queue movie
  int totalWaitGrp1 = 0;   // total wait time for group for stack movie
  int totalWaitGrp2 = 0;   // total wait time for group for queue movie
  int totalWaitCst1 = 0;   // total wait time for customers for stack movie
  int totalWaitCst2 = 0;   // total wait time for customers for queue movie
  int totalCust1 = 0;      // total number of customers for stack movie
  int totalCust2 = 0;      // total number of customers for queue movie
  int totalGroups1 = 0;    // total number of groups for stack movie
  int totalGroups2 = 0;    // total number of groups for queue movie
  int time, wait;
  cout << "\nFor \"Blood in the Corral\" (stack line)\n\n";
  // Can enqueue everyone then dequeue them later.
  //    However, with the stack, need to remove customers as soo as the 
  for (time = TIME_START; time < TIME_END; time++) // enqueue everyone
  {
	  num1 = rand()%GROUP_SIZE;
	  num2 = rand()%GROUP_SIZE;
	  if (num1 > 0)
	  {
		  movie.arrival = time;
		  movie.number = num1;
		  totalGroups1++;
		  totalCust1+=num1;
		  aStack.push(movie);
	  }
	  if (num2 > 0)
	  {
		  movie.arrival = time;
		  movie.number = num2;
		  totalGroups2++;
		  totalCust2+=num2;
		  aQueue.enqueue(movie);
	  }
	  if (time >= TIME_OFFICE) // process stack customers
	  {
		  if (!aStack.isEmpty())
          {
	         aStack.getTop(movie);
	         if (movie.arrival <= time)
	         {
		       aStack.pop();
	           cout << "Customer arrived at " << movie.arrival << " and bought ticket at " << time;
		       wait = time - movie.arrival;
			   totalWaitGrp1 += wait;
			   totalWaitCst1 += wait * movie.number;
		       cout << ", " << movie.number << " person(s) had to wait " << wait << endl;
		       if (wait > longestWait1)
			      longestWait1 = wait;
			 }
		   }
	  }
  }


  // time should be 51;
  while (!aStack.isEmpty())
  {
	  aStack.getTop(movie);
	  if (movie.arrival <= time)
	  {
		  aStack.pop();
	      cout << "Customer arrived at " << movie.arrival << " and bought ticket at " << time;
		  wait = time - movie.arrival;
		  totalWaitGrp1 += wait;
		  totalWaitCst1 += wait * movie.number;
		  cout << ", " << movie.number << " person(s) had to wait " << wait << endl;
		  if (wait > longestWait1)
			  longestWait1 = wait;
	  }
	  time ++;
  }

  // Now do the queue
  time = TIME_OFFICE;
  cout << "\nFor \"Romance at the Corral\" (queue line)\n\n";
  while (!aQueue.isEmpty())
  {
	  aQueue.getFront(movie);
	  if (movie.arrival <= time)
	  {
		  aQueue.dequeue();
	      cout << "Customer arrived at " << movie.arrival << " and bought ticket at " << time;
		  wait = time - movie.arrival;
		  totalWaitGrp2 += wait;
		  totalWaitCst2 += wait * movie.number;
		  cout << ", " << movie.number << " person(s) had to wait " << wait << endl;
		  if (wait > longestWait2)
			  longestWait2 = wait;
	  }
	  time ++;
  }

  cout << "\n\nLongest wait for stack was " << longestWait1 << " for " << totalGroups1 << " groups with " << totalCust1
	   << " customers\n  with average wait for groups of " << 1.0*totalWaitGrp1/totalGroups1
	   << "\n and average wait per customer of " << 1.0*totalWaitCst1/totalCust1<< endl;
  cout << "\nLongest wait for queue was " << longestWait2 << " for " << totalGroups2 << " groups with " << totalCust2
	   << " customers\n  with average wait for group of " << 1.0*totalWaitGrp2/totalGroups2
  	   << "\n and average wait per customer of " << 1.0*totalWaitCst2/totalCust2<< endl << endl;

  system("pause");
  return 0;
}

