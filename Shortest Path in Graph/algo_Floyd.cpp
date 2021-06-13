#include "algo_Floyd.h"
#include <iostream>
#define INF 999999

using namespace std;

void init_matrix(std::vector<std::vector<int> > &adjacency_matrix, int N) { 
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++){
            if (i == j){
                adjacency_matrix[i][j] = 0;
            }
            else{
                adjacency_matrix[i][j] = INF;            
            }
        }
    }
}

void add_edge(int source, int dest, int weight, std::vector<std::vector<int> > &adjacency_matrix) {
    adjacency_matrix[source][dest] = weight;

}


void FloydWarshall(std::vector<std::vector<int> > &adjacency_matrix, int N) {
    
    for (int k = 0; k < N; k++) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                
                // verifies if the given graph has negative cycles;
                if ((adjacency_matrix[k][j] < INF) && (adjacency_matrix[j][j] < 0)
                        && (adjacency_matrix[j][i] < INF)){

                    cout << "Graph has negative cycles" << endl;                    
                    return;
                }

                if (adjacency_matrix[k][j] != INF && adjacency_matrix[i][k] != INF &&
                        adjacency_matrix[i][j] > adjacency_matrix[i][k] + adjacency_matrix[k][j]) { 
                    adjacency_matrix[i][j] = adjacency_matrix[i][k] + adjacency_matrix[k][j];
                }
            }
        }
    }
    
    print_matrix(adjacency_matrix, N);
}

void print_matrix(std::vector<std::vector<int> > &adjacency_matrix, int N){
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (adjacency_matrix[i][j] == INF){
                cout << "inf";
            }
            else{
                cout << adjacency_matrix[i][j];
            }
        cout << " ";
        }
        cout << "\n";
    }
}


