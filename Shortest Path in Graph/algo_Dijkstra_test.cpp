#include <iostream>
#include <fstream>
#include "algo_Dijkstra.h"

using namespace std;

int main(int argc, char* argv[]) {

    (void) argc;
    ifstream f;
    f.open(argv[1]);
    int N, M;
    f >> N >> M;

    std::vector<std::vector<int> > adjacency_matrix(N, std::vector<int>(N));
    init_matrix(adjacency_matrix, N);

    for (int i = 0; i < M; i++){
        int source, dest, weight;
        f >> source >> dest >> weight;
        // verifies if the weight is positive;
        if (weight < 0){

            cout << "The graph has negative weighted edges." << endl;
            return 0;
        }
        add_edge(source - 1, dest - 1, weight, adjacency_matrix);
    }
    
    shortest_path_all(adjacency_matrix, N);
    
    f.close();   


}