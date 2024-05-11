#include <iostream>
#include <list>
#include <iterator>
#include <fstream>
#include "graphs/adjacency_list_graph.hpp"
#include "graphs/adjacency_matrix_graph.hpp"
#include "graphs/graph.hpp"
#include "graphs/shortest_path_algorithms.hpp"
using namespace std;

int main(int argc, char* argv[])
{
    std::ifstream inputFile("/home/tobiasz/PiAAGrafy/sp_data/graph/graphV10D0.5.txt");
    if (!inputFile) {
        std::cerr << "Nie można otworzyć pliku." << std::endl;
        return 1;
    }
    unique_ptr<Graph> graf = AdjacencyListGraph::createGraph(inputFile);
    ShortestPathResult result;
    dijkstra(*graf,7,result);
    graf->insertVertex(243);
    
    std::cout<< "Tu wykonujemy testy efektywności algorytmów"<<std::endl;
    return 0;
}

