#ifndef ALGO_H
#define ALGO_H
#include <iostream>
#include <vector>

/*
 * initializes the adjacency matrix with 0 on the main diagonal and the rest with
 * infinity;
 */
void init_matrix(std::vector<std::vector<int> > &adjacency_matrix, int N);

/*
 * adds the egde into the weighted graph's adjacency matrix
 */
void add_edge(int source, int dest, int weight, std::vector<std::vector<int> > &adjacency_matrix);


/*
 * finds the unvisited node with minimum distance value
 */
int minDistance(std::vector<int> &distance, std::vector<int> &visited, int N);

/*
 * calculates the shortest path from a given node to all the others nodes
 * using Dijkstra's algortim
 */
void Dijkstra(std::vector<std::vector<int> > &adjacency_matrix,  int N, 
                                int source, std::vector<int> &distance);

/**
 * applies Dijkstra's algorithm for every node
 * If there is no way reach node j from i, stores inf in the matrix. (
 * prints it as "inf" in the tests)
 */
void shortest_path_all(std::vector<std::vector<int> > &adjacency_matrix, int N);

/**
 * applies Bellman Ford's algorithm on the edges set
 * @return 0 if the graph has negative cycles
 */
int BellmanFord(std::vector<std::vector<int> > &edges, int source, int N, int M,
                    std::vector<int> &distance);

/**
 * calculates the shortest path between every pair of nodes using
 * Johnson's algorithm
 */
void Johnson(std::vector<std::vector<int> > &adjacency_matrix, 
                std::vector<std::vector<int> > &modified_matrix,
                std::vector<std::vector<int> > &edges, int N, int M);


/*
 * prints the shortest paths matrix
 */
void print_matrix(std::vector<std::vector<int> > &adjacency_matrix, int N);

#endif