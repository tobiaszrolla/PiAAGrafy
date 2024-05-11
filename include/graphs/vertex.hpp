#include <list>
#ifndef VERTEX_HPP_
#define VERTEX_HPP_

class Edge;
class Vertex
{
  friend class AdjacencyMatrixGraph;
  friend class AdjacencyListGraph;
  private:
    int element;
    int index;
    std::list<Edge*> adjacencylist;
  public:
    Vertex():element{0}, index{-1}{};;
    Vertex(int x):element(x){};
    Vertex(int element, int index): element{element}, index{index}{};
    ~Vertex(){};
    int operator*()
    {
    return(this->element);
    };
    bool operator==(const Vertex& other)
    {
    if(this->element == other.element && this->index == other.index)
    {
        return(true);
    }
    return(false);
    };

};
#endif /* VERTEX_HPP_ */