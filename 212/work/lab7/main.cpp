#include "graph.h" 
#include <iostream>

using namespace std;

int main()
{
	Graph simple(4);
	int v, w;
	int weight;
	Edge * e[10];
	int size = 3;
	e[0] = new Edge(0, 1, 6);
	e[1] = new Edge(0, 3, 8);
	e[2] = new Edge(1, 2, 4);

	for (int i = 0; i < 3; i++)
		simple.add(*(e[i]));

   /* do
	{
		cout << "Enter nodes to connect (-1 to end): ";
		cin >> v >> w;
		if (v >= 0 && w >= 0)
		{
		  cout << "Enter weight: ";
		  cin >> weight;
		  {
			Edge e(v,w,weight);
			simple.add(e);
		  }
		}
	} while (v >= 0 && w >= 0);
	*/
	cout << "Dump the graph" << endl;
	for (auto it = simple.adjList.begin(); it != simple.adjList.end(); ++it)
		for (auto m = (*it).begin(); m != (*it).end(); ++m)
			cout << (*m).first << " " << (*m).second << endl;
	int choice = 0;
	do
	{
	  for (v = 0; v < simple.getNumVertices(); v ++)
		for (w = 0; w < simple.getNumVertices(); w ++)
		{
			if (w == v)
				continue;
			cout << v << " to " << w << endl;
			//cout << "Use findEdge\n";
			std::map<int, int>::iterator m = simple.findEdge(v, w);
			if (m == simple.adjList[v].end()) 
				cout << "Didn't find edge\n";
			else
				cout << "Found edge with weight of " << m->second << endl;
	/*			
			cout << "Use findEdge2\n";
			int weight = simple.findEdge2(v, w);

			if (weight == -1)
				cout << "Did not find the edge\n";
			else
				cout << "The edge has a weight of " << weight << endl; */
		}
		cout << "1 - add edge\n";
		cout << "2 - delete edge\n";
		cout << "3 - quit\n";
		cin >> choice;
		Edge *edge = NULL;
		std::map<int, int>::iterator m2;
		switch (choice)
		{
			case 1 : 
				cout << "vertices to add an edge: ";
				cin >> v >> w;
				cout << "weight to edge: ";
				cin >> weight;
				edge = new Edge(v, w, weight);
				simple.add(*edge);
				break;
			case 2: cout << "vertices to remove an edge: ";
				cin >> v >> w;
				m2 = simple.findEdge(v, w);
			    if (m2 == simple.adjList[v].end()) 
				   cout << "Didn't find edge\n";
				else
				{
					edge = new Edge(v, w, m2->second);
					simple.remove(*edge);
				}
				break;
			case 3: cout << "quit\n";
				break;
			default: cout << "Invalid choice\n";
		}
		
	} while (choice != 3);

			
	system("pause");
	return 0;
}