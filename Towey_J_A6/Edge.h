#ifndef EDGE_H
#define EDGE_H

#include <iostream>

class Edge {
public:
    unsigned int startNode;
    unsigned int endNode;
    double weight;
    Edge();
    Edge(unsigned int start, unsigned int end, double w);
    bool operator<(const Edge& other) const;
    bool operator>(const Edge& other) const;
    bool operator==(const Edge& other) const;
};

#endif