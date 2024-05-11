#ifndef ADJACENCY_MATRIX_GRAPH_HPP_
#define ADJACENCY_MATRIX_GRAPH_HPP_
#include "graphs/graph.hpp"
#include <iostream>
#include <memory>
#include <list>
using namespace std;


class AdjacencyMatrixGraph : public Graph
{
  private:
  Edge*** tab;
  list<Vertex> vertexlist;
  list<Edge> edgelist;
  int capacity;
  int size;
  public:
    AdjacencyMatrixGraph();
    ~AdjacencyMatrixGraph();
    AdjacencyMatrixGraph(istream& is);
    list<Vertex> vertices();
    list<Edge> edges();
    void insertVertex(int x);
    void insertEdge(Vertex v, Vertex w, int x);
    void eraseVertex(Vertex v);
    void eraseEdge(Edge e);
    Vertex* endVertices(Edge e);
    Vertex opposit(Vertex v, Edge e);
    bool areAdjacent(Vertex v, Vertex w);
    void replace(Vertex v, int x);
    void replace(Edge e, int x);
    bool isIncident(Vertex v, Edge e);
    std::list<Edge> adjacencyEdge(Vertex v);
    static std::unique_ptr<Graph> createGraph(std::istream& is);
    void gettab();
    void getvertices();
};


#endif /* ADJACENCY_MATRIX_GRAPH_HPP_ */
