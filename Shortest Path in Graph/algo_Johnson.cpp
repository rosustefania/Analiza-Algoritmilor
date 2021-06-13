#include "algo_Johnson.h"
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
    
    for (int i = 0; i < N; i++){

        visited[i] = 0;
        if (i == source){

            distance[i] = 0;
        }    
        else{

            distance[i] = INF;
        }  
    }

    for (int i = 0; i < N; i++){

        int min_dist = minDistance(distance,visited,N);
        visited[min_dist] = 1;

        for (int j = 0; j < N; j++){

            if (visited[j] == 0){

                if (distance[j] > distance[min_dist] + adjacency_matrix[min_dist][j] && adjacency_matrix[min_dist][j] != INF && 
                distance[min_dist] != INF){

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

}  

int BellmanFord(std::vector<std::vector<int> > &edges, int source, int N, int M,
                    std::vector<int> &distance) {
    
    // initializes distances' array;
    for (int i = 0; i < N; i++){

        if (i == source){

            distance[i] = 0;
        }    
        else{

            distance[i] = INF;
        }  
    }

    // iterates thorugh nodes;
    for (int i = 0; i < N - 1; i++){
        
        // iterates through edges;
        // calculates minimum distances from the current node to the others;
        for (int j = 0; j < M; j++){

            int source = edges[j][0];
            int dest = edges[j][1];
            int weight = edges[j][2];

            if (distance[source] + weight < distance[dest] && distance[source] != INF){
                
                distance[dest] = distance[source] + weight;
            }
        }
    } 

    // verifies if the given graph has negative cycles;
    for (int j = 0; j < M; j++){

            int source = edges[j][0];
            int dest = edges[j][1];
            int weight = edges[j][2];

            if (distance[source] + weight < distance[dest]  && distance[source] != INF){
                
                return 0;
            }
        }

    return 1; 
}


void Johnson(std::vector<std::vector<int> > &adjacency_matrix, std::vector<std::vector<int> > &modified_matrix,
                std::vector<std::vector<int> > &edges, int N, int M){
        
        std::vector<std::vector<int>> h(N, std::vector<int>(N));

        for (int i = 0; i < N; i++){

            std::vector<int> distance(N);            

            // applies Bellman Ford algorithm to modify the graph in case it has
            // negative weighted edges;
            if (BellmanFord(edges, i, N, M, distance) == 0){
                cout << "Graph has negative cycles." << endl;
                return;
            }

            for (int j = 0; j < N; j++){
                h[i][j] = distance[j];
            }

            for (int j = 0; j < N; j++){
                if (adjacency_matrix[i][j] != 0){
                    modified_matrix[i][j] = adjacency_matrix[i][j] + 
                                distance[i] - distance[j];
                }
            }

        } 

        // applies Dijkstra's algorithm on all nodes;
        shortest_path_all(modified_matrix, N);

        for (int i = 0; i < N; i++){
    
            for (int j = 0; j < N; j++){

                    modified_matrix[i][j] = modified_matrix[i][j] + 
                                h[i][j] - h[i][i];
                
            }
        }
        print_matrix(modified_matrix, N);
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



