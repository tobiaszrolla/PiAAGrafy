#include "graphs/adjacency_matrix_graph.hpp"
//Edge////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//Można pomyśleć nad zmianą metody end vertices w AdjanceGraf
//Vertex//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


//Graf

void AdjacencyMatrixGraph::getvertices()
{
  for(Vertex v : vertexlist)
    {
        cout<<*v<<" "<<v.index<<endl;
    }
}
void AdjacencyMatrixGraph::gettab()
{
    for(int i = 0; i<size; i++){
        for(int j = 0; j<size; j++)
        {
            if(tab[i][j] == nullptr){
                cout<<0<<endl;
            }
            else{
                cout<<1<<endl;
            }
        }
    }
}
AdjacencyMatrixGraph::AdjacencyMatrixGraph(): size{0}, capacity{2}
{
    tab = new Edge**[capacity];
    for(int i = 0; i<capacity; i++)
    {
        tab[i] = new Edge*[capacity]{nullptr};
    }

}
AdjacencyMatrixGraph::~AdjacencyMatrixGraph()
{
    for(int i = 0; i<size; i++){
        delete[] tab[i];
    }
    delete[] tab;
}
void AdjacencyMatrixGraph::insertVertex(int x)
{
    Vertex newVertex = Vertex(x,size);
    vertexlist.push_back(newVertex);
    if(size >= capacity)
    {
        capacity = capacity*2;
        Edge*** tab_pom = new Edge**[capacity];
        for(int i = 0; i<capacity; i++)
        {
            tab_pom[i] = new Edge*[capacity]{nullptr};
        }
        for(int i = 0; i<size; i++)
        {
            for(int j = 0; j<size; j++)
            {
                tab_pom[i][j] = tab[i][j];
            }
        }
        for(int i = 0; i<size; i++)
        {
            delete[] tab[i];
        }
        delete[] tab;
        tab = tab_pom;
    }
    size ++;
}
void AdjacencyMatrixGraph::insertEdge(Vertex v, Vertex w, int x)
{
    Vertex* v1;
    Vertex* v2;
    auto it = vertexlist.begin();
    while (it != vertexlist.end())
    {
        if(*it == v)
        {
            v1 = &*it;
        }
        else if(*it == w)
        {
            v2 = &*it;
        }
        it++;
    }
    Edge newEdge = Edge(v1,v2,x);
    edgelist.push_back(newEdge);
    tab[v.index][w.index] = &edgelist.back();
    tab[w.index][v.index] = &edgelist.back();

}
void AdjacencyMatrixGraph::eraseVertex(Vertex v)
{
    for(int i = 0; i <= size; i++)
    {
        if(tab[v.index][i] != nullptr)
        {
          eraseEdge(*tab[v.index][i]);  
        }
        if(tab[i][v.index] != nullptr)
        {
          eraseEdge(*tab[i][v.index]);  
        }
    }
    for(int i = v.index; i<size; i++)
    {
        tab[i] = tab[i + 1];
    }
    for(int i = 0; i <= size; i++)
    {
        for(int j = v.index; j < size; j++)
        {
            tab[i][j] = tab[i][j+1];
        }
    }
    auto it = vertexlist.begin();
    while (it != vertexlist.end())
    {
        if(*it == v)
        {
            break;
        }
        it++;
    }
    auto it_copy = it;
    it++;
    vertexlist.remove(*it_copy);
    while (it != vertexlist.end())
    {
        it->index = it->index - 1;
        it++;
    }
    size--;    

}
void AdjacencyMatrixGraph::eraseEdge(Edge e)
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
    int ix1 = it->vertex1->index;
    int ix2 = it->vertex2->index;
    tab[ix1][ix2] = nullptr;
    tab[ix2][ix1] = nullptr;
    edgelist.remove(*it);
}
list<Vertex> AdjacencyMatrixGraph::vertices()
{
    return(vertexlist);
}
list<Edge> AdjacencyMatrixGraph::edges()
{
    return(edgelist);
}
Vertex* AdjacencyMatrixGraph::endVertices(Edge e)
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
};
Vertex AdjacencyMatrixGraph::opposit(Vertex v, Edge e)
{
    int it_tab = v.index;
    for(int i = 0; i < size; i++)
    {
        Edge* edge = tab[it_tab][i];
        if(edge != nullptr && *edge == e)
        {
            return(edge->opposite(v));
        }
    }
}
bool AdjacencyMatrixGraph::areAdjacent(Vertex v, Vertex w)
{
    int tab_it = v.index;
    for(int i = 0; i < size; i++)
    {
        Edge* e = tab[tab_it][i];
        if(e != nullptr && e->opposite(v) == w)
        {
            return true;
        }
    }
    return false;
    
}
AdjacencyMatrixGraph::AdjacencyMatrixGraph(istream& is): AdjacencyMatrixGraph()
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
void AdjacencyMatrixGraph::replace(Vertex v, int x)
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
void AdjacencyMatrixGraph::replace(Edge e, int x)
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
    if(it != edgelist.end())
    {
        it->cost = x;
    }
 
}
bool AdjacencyMatrixGraph::isIncident(Vertex v, Edge e)
{
    int tab_it = v.index;
    for(int i = 0; i < size; i++)
    {
        Edge* t = tab[tab_it][i];
        if(t != nullptr && *t == e)
        {
            return true;
        }
    }
    return false;    
}
list<Edge> AdjacencyMatrixGraph::adjacencyEdge(Vertex v)
{
    int tab_it = v.index;
    list<Edge> new_list;
    for(int i = 0; i < size; i++)
    {
        if(tab[tab_it][i] != nullptr)
        {
        new_list.push_back(*tab[tab_it][i]);
        }
    }
    return new_list;  
}
std::unique_ptr<Graph>  AdjacencyMatrixGraph::createGraph(std::istream& is)
{
    return std::make_unique<AdjacencyMatrixGraph>(is);
}
