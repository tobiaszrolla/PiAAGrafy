#ifndef ADJACENCY_LIST_GRAPH_HPP_
#define ADJACENCY_LIST_GRAPH_HPP_

#include <memory>

#include "graphs/graph.hpp"
using namespace std;


class AdjacencyListGraph : public Graph
{
  list<Vertex> vertexlist;
  list<Edge> edgelist;
  public:
    // TODO: implement all required methods
    AdjacencyListGraph(istream& is);
    ~AdjacencyListGraph();
    list<Vertex> vertices();
    list<Edge> edges();
    void insertVertex(int x);
    void insertEdge(Vertex v, Vertex w, int x);
    void eraseVertex(Vertex v);
    void eraseEdge(Edge e);
    Vertex* endVertices(Edge e);
    Vertex opposit(Vertex v, Edge e);
    bool areAdjacent(Vertex v, Vertex w);
    bool isIncident(Vertex v, Edge e);
    static std::unique_ptr<Graph> createGraph(std::istream& is);
    std::list<Edge> adjacencyEdge(Vertex v);
    void replace(Vertex v, int x);
    void replace(Edge e, int x);
    void gettab();
    void getvertices();
};

#endif /* ADJACENCY_LIST_GRAPH_HPP_ */
