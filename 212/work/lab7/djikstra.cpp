#include <iostream>
using namespace std;
const int LEVELS = 8;
void shortestPath(int *, int*, int[LEVELS][LEVELS]);

int main() {
	int adjMatrix[LEVELS][LEVELS] = {
		{-1,  2,  4,  6, -1, -1, -1, -1, -1}
		{ 2,  3,  5, -1, -1, -1, -1, -1, -1}
		{ 4,  5, -1,  1,  2, -1, -1, -1, -1} 
		{ 6, -1,  1, -1, -1,  3, -1,  4, -1}
		{-1, -1,  2  -1, -1,  1,  5, -1,  3}
		{-1, -1, -1,  3,  1, -1,  4, -1, -1}
		{-1, -1, -1, -1,  5,  4, -1, -1, -1}
		{-1, -1, -1,  4, -1, -1, -1, -1, -1}
		{-1, -1, -1, -1,  1  -1, -1, -1, -1}
			};

	// An array to hold nodes and full path distances
	int nodes[LEVELS];
	int distances[LEVELS];

	// First we just set our nodes to a count up to the number of
	// levels. Here we label nodes 0 through 7 (thus 8 levels)
	for (int i = 0; i < LEVELS; i++) {
	 nodes[i] = i;
	}

	// Our first vertex is a starting vertex, so set it to one
	// and its distance will be 0.
 nodes[0] = -1;
	distances[0] = 0;

	// Set the distances according to our levels array defined above.
	// distances array keeps track of the legs and adds to them as we move through
	// paths of the graph
	for (int i = 1; i < LEVELS; i++) {
		distances[i] = adjMatrix[0][i];
	}

	// Ok, lets start at level 1 and move to level 7
	// Each time we call our function to evaluate the following...

	// 1. What paths are available to us (we use the nodes closes to our point)
	// 2. How far are they away?
	// 3. Take whichever is shortest path with the least cost.

	for (int curlevel = 1; curlevel < LEVELS; curlevel++) {
		shortestPath(nodes, distances, adjMatrix);
		cout << "Level " << curlevel << endl;

		// Just to show what the current distances are for each path as we
		// loop through the vertexs and evaluate.
		for (int i = 0; i < LEVELS; i++) {
			cout << distances[i] << " ";
		}
		cout << endl;

		// Show which vertexs have yet to be visted (-1 means visited)
		for (int i = 0; i < LEVELS; i++) {
			cout << nodes[i] << " ";
		}
		cout << endl;
	}
	return 0;
}

// shortestPath implements the algorithm for checking the vertexs and their
// relative path distances in relation to where we are in the graph.
void shortestPath(int  *nodes, int *distances, int adjMatrix[LEVELS][LEVELS]) {
	int minValue = 32767;
	int minNode = 0;

	// Loop through the vertexs to see if they have been visited
	// If they haven't, check their distance and see if it is smaller than
	// our current shortest distance. If so, set the new shortest distance
	// to minValue and label the node as the shortest
	for (int i = 0; i < LEVELS; i++) {
		if  nodes[i] == -1) { continue; }
		if (distances[i] > 0 && distances[i] < minValue) {
			minValue = distances[i];
			minNode = i;
		}
	}

	// Mark the new shortest distance vertex as visited
 nodes[minNode] = -1;

	// Add the distance to the overall path distance from start
	// to destination. The result is a list of values at the end which will
	// show the shortest paths between any two nodes. 
	for (int i = 0; i < LEVELS; i++) {
		if (adjMatrix[minNode][i] < 0) { continue; }
		if (distances[i] < 0) {
			distances[i] = minValue + adjMatrix[minNode][i];
			continue;
		}
		if ((distances[minNode] + adjMatrix[minNode][i]) < distances[i]) {
			distances[i] = minValue + adjMatrix[minNode][i];
		}
	}
}
