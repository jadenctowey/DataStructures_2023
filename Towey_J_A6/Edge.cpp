#include "Edge.h"

// constructor
Edge::Edge() {
    startNode = 0;
    endNode = 0;
    weight = 0.0;
}

// Parameterized Constructor
Edge::Edge(unsigned int start, unsigned int end, double w) {
    startNode = start;
    endNode = end;
    weight = w;
}

// Overloaded operators for comparisons only. all edges does 
bool Edge::operator<(const Edge& other) const {                 //**Asked chat gpt the best way to set up
    return weight < other.weight;
}
bool Edge::operator>(const Edge& other) const {
    return weight > other.weight;
}
bool Edge::operator==(const Edge& other) const {
    return weight == other.weight;
}