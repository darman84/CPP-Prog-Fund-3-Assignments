
#ifndef H_msTree
#define H_msTree

//***************************************************************
// Author: D.S. Malik
//
// class msTreeType
// This class specifies the operations to find a minimum
// spanning tree in a graph.
//****************************************************************

#include <iostream>
#include <fstream>
#include <iomanip>
#include <cfloat>
#include "graphType.h"

using namespace std;

class msTreeType: public graphType
{
public:
    void createSpanningGraph();
	  //Function to create the graph and the weight matrix.
	  //Postcondition: The graph using adjacency lists and 
	  //    its weight matrix is created.

    void minimumSpanning(int sVertex);
	  //Function to create a minimum spanning tree with
	  //root as sVertex. 
	  // Postcondition: A minimum spanning tree is created.
	  //     The weight of the edges is also saved in the 
	  //     array edgeWeights.

    void prim2(int sVertex);

    void printTreeAndWeight();
	  //Function to output the edges of the minimum
	  //spanning tree and the weight of the minimum
	  //spanning tree.
	  //Postcondition: The edges of a minimum spanning tree
	  //    and their weights are printed.

    msTreeType(int size = 0); 
      //Constructor
      //Postcondition: gSize = 0; maxSize = size;
      //    graph is an array of pointers to linked lists.
      //    weights is a two-dimensional array to store the weights
      //      of the edges.
      //    edges is an array to store the edges of a minimum
      //      spanning tree.
      //    egdeWeight is an array to store the weights of the
      //      edges of a minimum spanning tree.

    ~msTreeType();
      //Destructor
      //The storage occupied by the vertices and the arrays
      //weights, edges, and edgeWeights is deallocated.

protected:
    int source;
    double **weights;
    int *edges;
    double *edgeWeights;
};

void msTreeType::createSpanningGraph()
{
	ifstream infile;
	char fileName[50];

	int vertex;
	int adjacentVertex;

	cout << "Enter input file name: ";
	cin >> fileName;
	cout << endl;

	infile.open(fileName);

	if (!infile)
	{
		cout << "Cannot open input file." << endl;
		return;
	}

	infile >> gSize;

	for (int index = 0; index < gSize; index++)
	{
		infile >> vertex;
		infile >> adjacentVertex;

		while (adjacentVertex != -999)
		{
			graph[vertex].insertLast(adjacentVertex);
			infile >> adjacentVertex;
		} //end while
	} //end for

	for (int i = 0; i < gSize; i++)
		for (int j = 0; j < gSize; j++)
			weights[i][j] = DBL_MAX;

	int weight;

	infile >> vertex;
	while (infile)
	{
		infile >> adjacentVertex;
		while (adjacentVertex != -999)
		{
			infile >> weight;
			weights[vertex][adjacentVertex] = weight;
			infile >> adjacentVertex;
		}
		infile >> vertex;
	}

	infile.close();
} //createWeightedGraph

void msTreeType::minimumSpanning(int sVertex)
{
	int startVertex, endVertex;
	double minWeight;

	source = sVertex;

	bool *mstv;
    mstv = new bool[gSize];

	for (int j = 0; j < gSize; j++)
	{
		mstv[j] = false;
		edges[j] = source;
		edgeWeights[j] = weights[source][j];
	}

	mstv[source] = true;
	edgeWeights[source] = 0;

	for (int i = 0; i < gSize - 1; i++)
	{
		minWeight = DBL_MAX;

		for (int j = 0; j < gSize; j++)
			if (mstv[j])
				for (int k = 0; k < gSize; k++)
					if (!mstv[k] && weights[j][k] < minWeight)
					{
						endVertex = k;
						startVertex = j;
						minWeight = weights[j][k];
					}
		mstv[endVertex] = true;
		edges[endVertex] = startVertex;
		edgeWeights[endVertex] = minWeight;
	} //end for
} //end minimumSpanning

void msTreeType::printTreeAndWeight()
{
	double treeWeight = 0;

	cout << "Source Vertex: " << source << endl;
	cout << "Edges    Weight" << endl;

	for (int j = 0; j < gSize; j++)
	{
		if (edges[j] != j)
		{
			treeWeight = treeWeight + edgeWeights[j];
			cout << "("<<edges[j] << ", " << j << ")    "
				 << edgeWeights[j] << endl;
		}
	}

	cout << endl;
	cout << "A minimum spanning tree weight: " 
		 << treeWeight << endl;
} //end printTreeAndWeight

    //Constructor
msTreeType::msTreeType(int size)
           :graphType(size)
{
    weights = new double*[size];

    for (int i = 0; i < size; i++)
        weights[i] = new double[size];

    edges  = new int[size];

    edgeWeights = new double[size];
}

    //Destructor
msTreeType::~msTreeType()
{
    for (int i = 0; i < gSize; i++)
       delete [] weights[i];

    delete [] weights;
    delete [] edges;
    delete edgeWeights;
}


// This algorithm results in a minimum spanning tree, with minimum weight and no cycles
void msTreeType::prim2(int sVertex)
{
	int k;

	double minWeight;

	source = sVertex; //source is the starting point

	bool *visited;
    visited = new bool[gSize]; //allocates space for the visited array, array with bool vars

	for (int j = 0; j < gSize; j++)
	{
		visited[j] = false;
		edges[j] = source;
		edgeWeights[j] = weights[source][j];
	}

	visited[source] = true; //add the starting point to the visited list
	edgeWeights[source] = 0;

	for (int i = 0; i < gSize; i++)
	{
		minWeight = DBL_MAX; // sets minWeight to the max double value
		// k is the node that is not visited and has the smallest weight
		k = -1;
		for (int j = 0; j < gSize; j++)
			if (!visited[j] &&  edgeWeights[j] < minWeight)
			{
				k = j;
				minWeight = edgeWeights[j]; //setting the minWeight var
			}
		
		if (k != source && k != -1)
		{
			visited[k] = true;	
	
			for (int j = 0; j < gSize; j++)
				if (!visited[j])
					if( weights[k][j] < edgeWeights[j])
					{
						edges[j] = k;
						edgeWeights[j] = weights[k][j];
					}
		}
	} //end for

	cout << endl;
} //end prim2

#endif