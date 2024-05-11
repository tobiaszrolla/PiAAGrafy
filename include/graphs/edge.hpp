#include "vertex.hpp"
#include <list>
#ifndef EDGE_HPP_
#define EDGE_HPP_


class Edge
{
  friend class AdjacencyMatrixGraph;
  friend class AdjacencyListGraph;
  private:
    int cost;
    Vertex* vertex1;
    Vertex* vertex2;
    std::list<Edge*>::iterator position1;
    std::list<Edge*>::iterator position2;
  public:
    Edge(){};
    Edge(Vertex* v, Vertex* w, int cost): vertex1{v}, vertex2{w}, cost{cost}
    {};
    ~Edge()
    {};
    Vertex* endVertices()
    {
      Vertex* tab = new Vertex[2];
      tab[0] = *vertex1;
      tab[1] = *vertex2;
      return tab;
    };
    Vertex opposite(Vertex v)
    {
      if(v == *vertex1)
      {
          return(*vertex2);
      }
      else
      {
          return(*vertex1);
      }
    }
    bool isAdjacentTo(Edge f);
    bool isIncidentOn(Vertex v);
    bool operator==(const Edge& other)
    {
    return(this->cost == other.cost && this->vertex1 == other.vertex1 && this->vertex2 == other.vertex2);
    };
    int operator*()
    {
    return(this->cost);
    };
};




#endif /* EDGE_HPP_ */