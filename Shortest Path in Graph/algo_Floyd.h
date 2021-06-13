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
 * calculates the shortest path between every pair of node using Floyd-Warshall algorithm
 * If there is no way reach node j from i, stores inf in the matrix. (
 * prints it as "inf" in the tests)
 */
void FloydWarshall(std::vector<std::vector<int> > &adjacency_matrix, int N);

/*
 * prints the shortest paths matrix
 */
void print_matrix(std::vector<std::vector<int> > &adjacency_matrix, int N);

#endif
