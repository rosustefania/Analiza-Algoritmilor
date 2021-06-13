#include "algo_Dijkstra.h"
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

int minDistance(std::vector<int> &distance, std::vector<int> &visited, int N) {

    int min_index = 0;
    int min_distance = INF;

    int i = 0;
    while (i < N) {

        if ((distance[i] < min_distance) && (visited[i] == 0)){

            min_distance = distance[i];
            min_index = i;
        }
        i++;
    }
    return min_index;
}


void Dijkstra(std::vector<std::vector<int> > &adjacency_matrix,  int N, 
                                int source, std::vector<int> &distance) {
    
    std::vector<int> visited(N);
    
    // marks the nodes as unvisited and initialize distances' array;
    for (int i = 0; i < N; i++){

        visited[i] = 0;
        if (i == source){

            distance[i] = 0;
        }    
        else{

            distance[i] = INF;
        }  
    }

    // calculates minimum distances from the source node to the other nodes;
    for (int i = 0; i < N; i++){

        int min_dist = minDistance(distance,visited,N);
        visited[min_dist] = 1;

        for (int j = 0; j < N; j++){

            if (visited[j] == 0){

                if (distance[j] > distance[min_dist] + adjacency_matrix[min_dist][j]){

                    distance[j] = distance[min_dist] + adjacency_matrix[min_dist][j];
                }

            }
        }
    }
}

void shortest_path_all(std::vector<std::vector<int> > &adjacency_matrix,  int N) {

    std::vector<std::vector<int> > adjacency_matrix_copy(N, std::vector<int>(N));
    adjacency_matrix_copy = adjacency_matrix;

    for (int i = 0; i < N; i++){

        std::vector<int> distance(N);
        Dijkstra(adjacency_matrix_copy, N, i, distance);

        for (int j = 0; j < N; j++){
            adjacency_matrix[i][j] = distance[j];
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


