#include <iostream>
#include <fstream>
#include "algo_Johnson.h"

using namespace std;

int main(int argc, char* argv[]) {

    (void) argc;
    ifstream f;
    f.open(argv[1]);
    int N, M;
    f >> N >> M;

    std::vector<std::vector<int> > adjacency_matrix(N, std::vector<int>(N));
    std::vector<std::vector<int> > modified_matrix(N, std::vector<int>(N));
    std::vector<std::vector<int> > edges(M, std::vector<int>(3)); // matrix that represents edges set;

    init_matrix(adjacency_matrix, N);
    init_matrix(modified_matrix, N);

    for (int i = 0; i < M; i++){
        int source, dest, weight;
        f >> source >> dest >> weight;
        add_edge(source - 1, dest - 1, weight, adjacency_matrix);
        edges[i][0] = source - 1;
        edges[i][1] = dest - 1;
        edges[i][2] = weight;
    } 

    Johnson(adjacency_matrix, modified_matrix, edges, N, M);   
    

    f.close();   


}