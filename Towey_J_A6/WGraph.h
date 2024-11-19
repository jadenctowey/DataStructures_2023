//TOOK FROM ASSIGNMENT 

#ifndef WGraph_H
#define WGraph_H

#include "PQueue.h"
#include "Edge.h"
#include <cstdlib>
#include <deque>
#include <set>
#include <stack>
#include <iostream>
#include <limits> // allows us to get min and max
#include <vector>


//a weighted, undirected WGraph implemented with adjacency matrix
//fixed size

typedef unsigned int VertexID;

class WGraph{
public: 
  WGraph();
  WGraph(unsigned int sz);
  ~WGraph();
  void addEdge(VertexID i, VertexID j, double w); // now includes a double for the weight of the edge
  void removeEdge(VertexID i, VertexID j);
  bool areAdjacent(VertexID i, VertexID j);
  double cheapestCost(VertexID i, VertexID j); // will give us the cheapest path between two vertices
  void calcFW(); // will calculate the Floyd-Warshall algo and create a connectivity matrix that gives us the shortest path from every node to every other node 
  unsigned int findSet(unsigned int node, std::vector<std::set<unsigned int> >& sets);
  void mergeSets(unsigned int set1, unsigned int set2, std::vector<std::set<unsigned int> >& sets);
  void computeMST();

private:
  double** m_adj; // Adjacency matrix: is there an edge between two vertices and what's the weight of the edge
  double** m_conn; // Connectivity matrix: more general, is there a path between a start and a finish and what's the cost (all parts summed)
  unsigned int m_size; // number of nodes in WGraph (fixed) 
  bool recalcFW;

};

#endif