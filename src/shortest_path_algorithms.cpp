#include "graphs/shortest_path_algorithms.hpp"
#include "/home/tobiasz/PiAAGrafy/include/graphs/adjacency_list_graph.hpp"
#include <iostream>
namespace 
{
    struct vertex_n_distance
    {
        Vertex v;
        int distance;
    };

//aby znaleźć rodzica należy przesunnąć bity w prawo
int parent(int i){
    return(((i+1)>>1)-1);
};
//aby znaleźć lewe dziecko naleźy index rodzica przesunąć w lewo + 1
int left(int i){
    return((i<<1) + 1);
};
//aby znaleźć lewe dziecko naleźy index rodzica przesunąć w lewo + 2
int right(int i){
    return((i<<1) + 2);
};
void swap(vertex_n_distance& ele1, vertex_n_distance& ele2)
{
    vertex_n_distance temp;
    temp = ele1;
    ele1 = ele2;
    ele2 = temp;
} 

//porównuje elementy element o najmniejszym priorytecie idzie na przybliża się do przodu
void hepify(int start_element,vector<vertex_n_distance>& array){
    int l_child = left(start_element);
    int r_child = right(start_element);
    int p_place = start_element;
    //gdy prawy poza tablicom rodzic porównaj z lewym
    if(l_child < array.size() && array[l_child].distance < array[p_place].distance){
        p_place = l_child;
    }
    if(r_child < array.size() && array[r_child].distance < array[p_place].distance){
        p_place = r_child;
    }
    if(p_place != start_element){
        swap(array[p_place], array[start_element]);
        //jak już zamienimy rodzica z dzieckiem trzeba sprawdzić jak wpłynie to na kolejność poniżej
        hepify(p_place,array);
        
    }
};
} 


void dijkstra(Graph& graph, int sourceIndex, ShortestPathResult& result)
{
    
    std::list<Vertex> vertexlist = graph.vertices();
    std::vector<vertex_n_distance> heap_table(vertexlist.size());
    auto ver_it = vertexlist.begin();
    int v = **ver_it;
    for(int i = 0; i < vertexlist.size(); i++)
    {
        heap_table[i].v = *ver_it;
        heap_table[i].distance = __INT_MAX__;
        ver_it++;
    }
    heap_table[sourceIndex].distance = 0;
    swap(heap_table[sourceIndex],heap_table[0]);
    int way_distance = 0;
    std::vector<int> result_vector;
    
    while(!heap_table.empty())
    {
        std::list<Edge> adjent = graph.adjacencyEdge(heap_table[0].v);
        auto adje_it = adjent.begin();
        while(adje_it != adjent.end())
        {
            for(int i = 1; i<heap_table.size(); i++)
            {
                if(graph.opposit(heap_table[0].v, *adje_it) == heap_table[i].v && heap_table[i].distance > **adje_it)
                {
                    heap_table[i].distance = **adje_it;
                    int j = parent(i);
                    while(j != 0)
                    {
                        hepify(j, heap_table);
                        j = parent(j);
                    }
                    break;
                }
            }
            adje_it++;
        }
            way_distance = way_distance + heap_table[0].distance;
            result_vector.push_back(*heap_table[0].v);
            swap(heap_table[0], heap_table[heap_table.size()-1]);
            heap_table.pop_back();
            hepify(0,heap_table);
    }

result[sourceIndex] = pair(way_distance,result_vector);

}

bool bellmanFord(Graph& graph, int sourceIndex, ShortestPathResult& result)
{
    // TODO: implement
    return true;
}
