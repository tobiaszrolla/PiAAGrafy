#include "graphs/adjacency_list_graph.hpp"
#include <iostream>
using namespace std;

AdjacencyListGraph::AdjacencyListGraph(istream& is)
{
   int num_vertex, num_edge;
    is >> num_vertex >> num_edge;
    for(int i = 0; i < num_vertex; i++)
    {
        insertVertex(i);
    }
    int ver1, ver2, cost;
    for(int i = 0; i < num_edge; i++)
    {
      is >> ver1 >> ver2 >> cost;
      auto it = vertexlist.begin();
      while(it != vertexlist.end())
      {
        if(**it == ver1)
        {
            break;
        }
        it++;
      }
      auto it2 = vertexlist.begin();    
      while(it2 != vertexlist.end())
      {
        if(**it2 == ver2)
        {
            break;
        }
        it2++;
      }
      if(it != vertexlist.end(), it2 != vertexlist.end())
      {
        insertEdge(*it,*it2,cost);
      }
    }
}
AdjacencyListGraph::~AdjacencyListGraph()
{

}
list<Vertex> AdjacencyListGraph::vertices()
{
    return vertexlist;
}
list<Edge> AdjacencyListGraph::edges()
{
    return edgelist;
}
void AdjacencyListGraph::insertVertex(int x)
{
    vertexlist.push_back(Vertex(x));
};
void AdjacencyListGraph::insertEdge(Vertex v, Vertex w, int x)
{
    auto it = vertexlist.begin();
    Vertex* v1;
    Vertex* v2;
    bool wyjs1{false}, wyjs2{false};
    while(it != vertexlist.end())
    {
        if(*it  == v)
        {
            v1 = &*it;
            wyjs1 = true;
        }
        else if(*it == w)
        {
            v2 = &*it;
            wyjs2 = true;
        }
        if(wyjs1 == true && wyjs2 == true)
        {
            break;
        }

        it++;
    }
    edgelist.push_back(Edge(v1,v2,x));
    v1->adjacencylist.push_back(&edgelist.back());
    v2->adjacencylist.push_back(&edgelist.back());
    edgelist.back().position1 = --(v1->adjacencylist.end());
    edgelist.back().position2 = --(v2->adjacencylist.end());

};
void AdjacencyListGraph::eraseVertex(Vertex v)
{

}
void AdjacencyListGraph::eraseEdge(Edge e)
{
    auto it = edgelist.begin();
    while(it != edgelist.end())
    {
        if(*it == e)
        {
            break;
        }
        it++;
    }
    Vertex* v1 = &*(it->vertex1);
    Vertex* v2 = &*(it->vertex2);
    v1->adjacencylist.erase(it->position1);
    v2->adjacencylist.erase(it->position2);
    edgelist.erase(it);
}
Vertex* AdjacencyListGraph::endVertices(Edge e)
{
    auto it = edgelist.begin();
    while(it != edgelist.end())
    {
        if(*it == e)
        {
            Vertex* end_v_tab = it->endVertices();
            return(end_v_tab);
        }
        it++;
    }
}
Vertex AdjacencyListGraph::opposit(Vertex v, Edge e)
{
    auto it = edgelist.begin();
    while(it != edgelist.end())
    {
        if(*it == e)
        {
            break;
        }
        it++;
    }
    if(*(it->vertex1) == v)
    {
        return(*(it->vertex2));
    }
}
bool AdjacencyListGraph::areAdjacent(Vertex v, Vertex w)
{
    auto it = vertexlist.begin();
    while(it != vertexlist.end())
    {
        if(*it == v)
        {
            break;
        }
        it++;
    }
    auto edg_it = it->adjacencylist.begin();
    while(edg_it != it->adjacencylist.end())
    {
        if((**edg_it).opposite(*it) == w)
        {
            return(true);
        }
        edg_it++;
    }
    return false;
}
void AdjacencyListGraph::replace(Vertex v, int x)
{
   auto it = vertexlist.begin();
    while(it != vertexlist.end())
    {
        if(*it == v)
        {
            break;
        }
        it++;
    }
    it->element = x; 
}
void AdjacencyListGraph::replace(Edge e, int x)
{
   auto it = edgelist.begin();
    while(it != edgelist.end())
    {
        if(*it == e)
        {
            break;
        }
        it++;
    }
    it->cost = x; 
}
bool AdjacencyListGraph::isIncident(Vertex v, Edge e)
{
    auto it = vertexlist.begin();
    while(it != vertexlist.end())
    {
        if(*it == v)
        {
            break;
        }
        it++;
    }
    if(it != vertexlist.end())
    {
    auto edge_it = it->adjacencylist.begin();
    while(edge_it != it->adjacencylist.end())
    {
        Edge t = **edge_it;
        if(t == e)
        {
            return true;
        }
        edge_it++;
    }
    }
    return false;
}
list<Edge> AdjacencyListGraph::adjacencyEdge(Vertex v)
{
    auto it = vertexlist.begin();
    while(it != vertexlist.end())
    {
        if(*it == v)
        {
            break;
        }
        it++;
    }
    list<Edge> new_list;
    if(it != vertexlist.end())
    {
    auto edge_it = it->adjacencylist.begin();
    while(edge_it != it->adjacencylist.end())
    {
        Edge* add_edge = *edge_it;
        new_list.push_back(*add_edge);
        edge_it++;
    } 
    }
    return new_list;
}
void AdjacencyListGraph::gettab()
{

}
void AdjacencyListGraph::getvertices()
{

}
std::unique_ptr<Graph> AdjacencyListGraph::createGraph(std::istream& is)
{
    // TODO: implement

    return std::make_unique<AdjacencyListGraph>(is);
}
