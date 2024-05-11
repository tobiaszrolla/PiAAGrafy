#include "graphs/edge.hpp"
#ifndef GRAPH_HPP_
#define GRAPH_HPP_
#include <list>
class Graph
{
  public:
    Graph()=default;
    ~Graph()=default;
    virtual std::list<Vertex> vertices()=0;
    virtual std::list<Edge> edges()=0;
    virtual void insertVertex(int x)=0;
    virtual void insertEdge(Vertex v, Vertex w, int x)=0;
    virtual void eraseVertex(Vertex v)=0;
    virtual void eraseEdge(Edge e)=0;
    virtual Vertex* endVertices(Edge e)=0;
    virtual Vertex opposit(Vertex v, Edge e)=0;
    virtual bool areAdjacent(Vertex v, Vertex w)=0;
    virtual bool isIncident(Vertex v, Edge e)=0;
    virtual void replace(Vertex v, int x)=0;
    virtual void replace(Edge e, int x)=0;
    virtual std::list<Edge> adjacencyEdge(Vertex v)=0;
    virtual void gettab()=0;
    virtual void getvertices()=0;
};

#endif  /* GRAPH_HPP_ */ 
