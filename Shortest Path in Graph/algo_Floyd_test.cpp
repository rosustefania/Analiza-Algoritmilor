#include <iostream>
#include <fstream>
#include "algo_Floyd.h"

using namespace std;

int main(int argc, char* argv[]) {

    (void) argc;
    ifstream f;
    f.open(argv[1]);
    int N, M;
    f >> N >> M;

    std::vector<std::vector<int> > adjacency_matrix(N, std::vector<int>(N));
    init_matrix(adjacency_matrix, N);


    // creates graph's weighted adjacency matrix;
    for (int i = 0; i < M; i++){

        int source, dest, weight;
        f >> source >> dest >> weight;
        add_edge(source - 1, dest - 1, weight, adjacency_matrix);
    }
    
    // applies Floyd-Warshall algorithm;
    FloydWarshall(adjacency_matrix, N);
        
    f.close();   
}