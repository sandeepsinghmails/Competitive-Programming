// Author: Sandeep Singh
// Date: May 2, 2018
// File: CreateGraph.cpp
// A simple representation of graph using STL
// References:
// [1] https://www.geeksforgeeks.org/graph-and-its-representations
// [2] https://www.geeksforgeeks.org/breadth-first-search-or-bfs-for-a-graph
#include<bits/stdc++.h>
using namespace std;

class Graph
{
private:
    // No. of Vertices
    int m_vertices;   
    // Adjacency List: An Array of Individual List for Each Node (Size = No. of Vertices)
    std::list<int> *adj;
public:
    // Constructor
    Graph(int vertices);
    // Add New Edge between vertex1 & vertex2
    void addEdge ( int vertex1, int vertex2 );
    // Print the entire Graph
    void printGraph ( );
};

Graph::Graph(int vertices):m_vertices(vertices)
{
    adj = new std::list<int>[m_vertices];
}

void Graph::addEdge(int vertex1, int vertex2)
{
    adj[vertex1].push_back(vertex2);
    adj[vertex2].push_back(vertex1);
}

void Graph::printGraph()
{
    // Traverse Each Array Index
    for (int i=0; i<m_vertices; i++)
    {
        cout << "Adjacency List of Vertex: " << i << endl << "head ";
        // Traverse each Individual list -- corresponding to this vertex
        for (auto elem : adj[i])
            cout << "-> " << elem;
        
        cout << endl;
    }
}

// Driver code
int main()
{
	Graph g(5);
	
	g.addEdge(0, 1);
	g.addEdge(0, 4);
	g.addEdge(1, 2);
	g.addEdge(1, 3);
	g.addEdge(1, 4);
	g.addEdge(2, 3);
	g.addEdge(3, 4);
	
	g.printGraph();
	
	return 0;
}
