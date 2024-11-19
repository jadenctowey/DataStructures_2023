//TOOK FROM ASSIGNMENT 

#include "WGraph.h"

WGraph::WGraph(){
  m_size = 0;
  m_adj = NULL;
  m_conn = NULL;
}

WGraph::WGraph(unsigned int sz){
  m_size = sz;
  //allocate sz * sz adj matrix
  m_adj = new double*[sz];
  m_conn = new double*[sz];
  for(int i = 0; i < m_size; ++i){
    m_adj[i] = new double[sz];
    m_conn[i] = new double[sz];
  }
  //start with edges
  for(int i = 0; i < m_size; ++i){
    for(int j = 0; j < m_size; ++j){
      m_adj[i][j] = std::numeric_limits<double>::max();
      m_conn[i][j] = std::numeric_limits<double>::max();  
    }
  }

  recalcFW = false;
}

WGraph::~WGraph(){
  // release memory - let's actually do it in class for once
  for (int i = 0; i < m_size; ++ i){
    delete m_adj[i];
    delete m_conn[i]; 
  }
  delete[] m_adj;
  delete[] m_conn;
}

void WGraph::addEdge(VertexID i, VertexID j, double w){
  if(i < m_size && j < m_size){
    m_adj[i][j] = w;  
    m_adj[j][i] = w;
  }
  // calcFW(); // not very efficient since we'd have to re-calculate it every time we add or remove an edge
  recalcFW = true;
}

void WGraph::removeEdge(VertexID i, VertexID j){
  if(i < m_size && j < m_size){
    m_adj[i][j] = std::numeric_limits<double>::max();
    m_adj[j][i] = std::numeric_limits<double>::max();
  }
  // calcFW(); // not very efficient since we'd have to re-calculate it every time we add or remove an edge
  recalcFW = true;
}

bool WGraph::areAdjacent(VertexID i, VertexID j){
  return (m_adj[i][j] < std::numeric_limits<double>::max());
}

void WGraph::calcFW(){
  // set the conn matrix equal to adj matrix 
  for (int i = 0; i < m_size; ++i){
    for (int j = 0; j < m_size; ++j){
      m_conn[i][j] = m_adj[i][j];
    }
  }

  // start FW
  for (int im = 0; im < m_size; ++im){ // intermediate points 
    for (int source = 0; source < m_size; ++source){ // source -> starting point
      for (int sink = 0; sink < m_size; ++sink){ // sink -> ending point 
        if (source == sink){
          continue;
        } else if ( m_conn[source][im] != std::numeric_limits<double>::max() &&
                    m_conn[im][sink] != std::numeric_limits<double>::max() &&
                    m_conn[source][sink] > m_conn[source][im] + m_conn[im][sink]){
                  
                   m_conn[source][sink] = m_conn[source][im] + m_conn[im][sink];

        }
      }
    }
  }
	recalcFW = false;
}

double WGraph::cheapestCost(VertexID i, VertexID j){
  if (recalcFW){
    calcFW();
  }
  return m_conn[i][j]; 
}

// computes minimum spanning tree from adjacency matrix and outputs the result and MST cost to the terminal
void WGraph::computeMST() {
    // Initialize a priority queue for edges
    PQueue<Edge*> pq(true);

    // Populate the priority queue with all edges from the graph
    for (unsigned int i = 0; i < m_size; ++i) {
        for (unsigned int j = i + 1; j < m_size; ++j) {
            if (m_adj[i][j] < std::numeric_limits<double>::max()) {
                Edge* edge = new Edge(i, j, m_adj[i][j]);
                pq.add(edge);
            }
        }
    }



    // Initialize sets to keep track of connected components
    std::vector<std::set<unsigned int> > sets(m_size);
    for (unsigned int i = 0; i < m_size; ++i) {
        sets[i].insert(i); // Each node starts in its own set
    }

    double totalMSTCost = 0.0; // Total cost of the MST
    WGraph mstGraph(m_size); // Initialize a new graph for MST

    // Process edges from the priority queue
    while (!pq.isEmpty()) {
        Edge* currentEdge = pq.peek();
        pq.remove();

        // Check if adding this edge forms a cycle
        unsigned int set1 = findSet(currentEdge->startNode, sets);
        unsigned int set2 = findSet(currentEdge->endNode, sets);

        if (set1 != set2) {
            // Add the edge to the MST
            mstGraph.addEdge(currentEdge->startNode, currentEdge->endNode, currentEdge->weight);
            totalMSTCost += currentEdge->weight;

            // Merge the sets of the two nodes
            mergeSets(set1, set2, sets);
        }
    }

    // Display the cost of the MST
    std::cout << "The MST Cost is: " << totalMSTCost << std::endl;

    // Display the adjacency matrix representation of the MST
    for (unsigned int i = 0; i < m_size; ++i) {
        for (unsigned int j = 0; j < m_size; ++j) {
            if (mstGraph.areAdjacent(i, j)) {
                std::cout << m_adj[i][j] << " ";
            } else {
                std::cout << "0.0 ";
            }
        }
        std::cout << std::endl;
    }
}

// Function to find the set that a node belongs to
unsigned int WGraph::findSet(unsigned int node, std::vector<std::set<unsigned int> >& sets) {
    for (unsigned int i = 0; i < sets.size(); ++i) {
        if (sets[i].count(node) > 0) {
            return i;
        }
    }
    return std::numeric_limits<unsigned int>::max(); // Node not found in any set
}

// Function to merge two sets
void WGraph::mergeSets(unsigned int set1, unsigned int set2, std::vector<std::set<unsigned int> >& sets) {
    // Merge set2 into set1
    sets[set1].insert(sets[set2].begin(), sets[set2].end());
    sets.erase(sets.begin() + set2);
}