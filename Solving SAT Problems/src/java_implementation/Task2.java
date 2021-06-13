// Copyright 2020
// Author: Matei Simtinică

import java.io.*;
import java.util.ArrayList;
import java.util.List;

/**
 * Task2
 * You have to implement 4 methods:
 * readProblemData         - read the problem input and store it however you see fit
 * formulateOracleQuestion - transform the current problem instance into a SAT instance and write the oracle input
 * decipherOracleAnswer    - transform the SAT answer back to the current problem's answer
 * writeAnswer             - write the current problem's answer
 */
public class Task2 extends Task {
    // TODO: define necessary variables and/or data structures
    /** the number of families/nodes **/
    private int N;
    /** the number of relationships/edges **/
    private int M;
    /** the dimension of the wanted family **/
    private int K;
    /** represents graph' adjacency matrix **/
    private int[][] adjacencyMatrix;
    /** represents the solution **/
    private List<Integer> families;

    @Override
    public void solve() throws IOException, InterruptedException {
        readProblemData();
        formulateOracleQuestion();
        askOracle();
        decipherOracleAnswer();
        writeAnswer();
    }

    @Override
    public void readProblemData() throws IOException {
        BufferedReader reader = new BufferedReader(new FileReader(inFilename));

        /* reads the first line */
        String line = reader.readLine();
        String[] data = line.trim().split("\\s+");

        N = Integer.parseInt(data[0]);
        M = Integer.parseInt(data[1]);
        K = Integer.parseInt(data[2]);

        /* initializes the adjacency list */
        adjacencyMatrix = new int[N][N];

        /* reads the next M lines representing the edges and adds them to the adjacency matrix */
        for (int i = 0; i < M; i++) {
            line = reader.readLine();
            data = line.trim().split("\\s+");

            int u = Integer.parseInt(data[0]);
            int v = Integer.parseInt(data[1]);

            adjacencyMatrix[u - 1][v - 1] = 1;
            adjacencyMatrix[v - 1][u - 1] = 1;
        }
    }

    @Override
    public void formulateOracleQuestion() throws IOException {
        /* calculates the number of variables and the number of clauses */
        int V = N * K;
        int F = K + (N * (N - 1) * K) + (N * N - 2 * M - N) * K * (K - 1) + N * K * (K - 1);

        /* initializes the variables */
        int variableNumber = 1;
        int[][] variables = new int[N][K];
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < K; j++) {
                variables[i][j] = variableNumber;
                variableNumber ++;
            }
        }

        PrintWriter writer = new PrintWriter(new FileWriter(oracleInFilename));

        /* prints the first line of the output file */
        String firstLine = "p cnf " + V + " " + F;
        writer.println(firstLine);

        for (int k = 0; k < K; k++) {
            for ( int i = 0; i < N; i++) {
                writer.print(variables[i][k] + " ");
            }
            writer.println(0);
        }


        /* two nodes can't be on the same position in the clique */
        for(int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (i != j) {
                    for (int k = 0; k < K; k++) {
                        writer.print((variables[i][k] - 2 * variables[i][k]) + " ");
                        writer.print((variables[j][k] - 2 * variables[j][k]) + " ");
                        writer.println(0);
                    }
                }
            }
        }

        /* two nodes that aren't connected by an edge can't be in the same clique */
        for(int i = 0; i < N; i++) {
            for(int j = 0; j < N; j++) {
                if (adjacencyMatrix[i][j] == 0 && i != j) {
                    for (int k = 0; k < K; k++) {
                        for (int t = 0; t < K; t++) {
                            if (t != k) {
                                writer.print((variables[i][k] - 2 * variables[i][k]) + " ");
                                writer.print((variables[j][t] - 2 * variables[j][t]) + " ");
                                writer.println(0);
                            }
                        }
                    }
                }
            }
        }

        /* a node can't be twice in a clique */
        for (int i = 0; i < N; i++) {
            for (int k = 0; k < K; k++) {
                for (int j = 0; j < K; j++) {
                    if (j != k) {
                        writer.print((variables[i][k] - 2 * variables[i][k]) + " ");
                        writer.print((variables[i][j] - 2 * variables[i][j]) + " ");
                        writer.println(0);
                    }
                }
            }
        }

        writer.close();
    }

    @Override
    public void decipherOracleAnswer() throws IOException {
       BufferedReader reader = new BufferedReader(new FileReader(oracleOutFilename));
       String line = reader.readLine();

        // if the formula has a solution, gets the spies
        if (line.equalsIgnoreCase("True")) {
            // reads the number of used variables
            line = reader.readLine();
            int V = Integer.parseInt(line);

            families = new ArrayList<>();
            line = reader.readLine();
            String[] data = line.trim().split("\\s+"); //stores the solution

            // stores the families that are extended
            int family = 0;
            for (int i = 0; i < V; i++) {
                if ( i % K == 0) {
                    family ++;
                }
                if (Integer.parseInt(data[i]) > 0) {
                    families.add(family);
                }
            }
        }
    }

    @Override
    public void writeAnswer() throws IOException {
        PrintWriter  writer = new PrintWriter(new FileWriter(outFilename));
        if (families == null) {
            writer.println("False");
        } else {
            writer.println("True");
            for (Integer family : families) {
                writer.print(family + " ");
            }
        }
        writer.close();
    }

}
