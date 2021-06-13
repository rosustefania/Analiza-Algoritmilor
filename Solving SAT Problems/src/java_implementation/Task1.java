// Copyright 2020
// Author: Matei Simtinică

import java.io.*;
import java.util.ArrayList;
import java.util.List;

/**
 * Task1
 * You have to implement 4 methods:
 * readProblemData         - read the problem input and store it however you see fit
 * formulateOracleQuestion - transform the current problem instance into a SAT instance and write the oracle input
 * decipherOracleAnswer    - transform the SAT answer back to the current problem's answer
 * writeAnswer             - write the current problem's answer
 */
public class Task1 extends Task{
    /** the number of families/nodes **/
    private int N;
    /** the number of relationships/edges **/
    private int M;
    /** the number of spies **/
    private int K;
    /** represents graph' adjacency matrix **/
    private int[][] adjacencyMatrix;
    /** represents the solution **/
    private List<Integer> spies;

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
        int F = N + (N * K * (K - 1)) / 2 + K * M;

        /* initializes the variables */
        int variableNumber = 1;
        int[][] variables = new int[N][K];
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < K; j++) {
                variables[i][j] = variableNumber;
                variableNumber ++;
            }
        }

        PrintWriter  writer = new PrintWriter(new FileWriter(oracleInFilename));

        /* prints the first line of the output file */
        String firstLine = "p cnf " + V + " " + F;
        writer.println(firstLine);

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < K; j++) {
                writer.print(variables[i][j] + " ");
            }
            writer.println(0);

            for (int k = 0; k < K; k++) {
                for (int j = 0; j < K; j++) {
                    if (j != k) {
                        writer.print((variables[i][j] - 2 * variables[i][j]) + " ");
                    } else {
                        writer.print(variables[i][j] + " ");
                    }
                }
                writer.println(0);
            }
        }

        /* iterate through adjacency matrix, above the main diagonal, so every edge is
        taken only once */
        for(int i = 0; i < N; i++) {
            for(int j = i + 1; j < N; j++) {
                if (adjacencyMatrix[i][j] == 1) {
                    for (int k = 0; k < K; k++) {
                        writer.print((variables[i][k] - 2 * variables[i][k]) + " ");
                        writer.print((variables[j][k] - 2 * variables[j][k]) + " ");
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

        /* if the formula has a solution, gets the spies */
        if (line.equalsIgnoreCase("True")) {
            /* reads the number of used variables */
            line = reader.readLine();
            N = Integer.parseInt(line);

            spies = new ArrayList<>();
            line = reader.readLine();
            String[] data = line.trim().split("\\s+"); //stores the solution

            /* stores the spies by the variables' numbers */
            for (int i = 0; i < N; i++) {
                if (Integer.parseInt(data[i]) > 0) {
                    spies.add(Integer.parseInt(data[i]));
                }
            }

            /* obtains the correct spy's number for every family */
            for (int i = 0; i < spies.size(); i++) {
                spies.set(i, (spies.get(i) - i * K));
            }
        }

    }

    @Override
    public void writeAnswer() throws IOException {
        PrintWriter  writer = new PrintWriter(new FileWriter(outFilename));
        if (spies == null) {
            writer.println("False");
        } else {
            writer.println("True");
            for (Integer spy : spies) {
                writer.print(spy + " ");
            }
        }
        writer.close();
    }
}
