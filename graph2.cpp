//
// Created by Олег on 30.06.2024.
//
/*
  матрица задается в файле incidence_matrix.txt в виде
 a b
 1 0 1 0 1
 1 1 0 1 1
 0 0 0 1 1 ...и т.д, где a - количество вершин, b - количество ребер
 */
#include <cstdio>
#include <vector>

using namespace std;

FILE *getFileWithIncidenceMatrix() {
    return fopen("../incidence_matrix.txt", "r");
}

int getCountVertexFromFile(FILE *fileWithIncidenceMatrix) {
    int countOfVertex;
    fscanf(fileWithIncidenceMatrix, "%d", &countOfVertex);
    return countOfVertex;
}

int getCountRibsFromFile(FILE *fileWithIncidenceMatrix) {
    int countOfRibs;
    fscanf(fileWithIncidenceMatrix, "%d", &countOfRibs);
    return countOfRibs;
}

vector<vector<int>> getIncidenceMatrixFromFile(FILE *fileWithIncidenceMatrix, int countOfVertex, int countOfRibs) {
    vector<vector<int>> incidenceMatrix(countOfVertex, vector<int>(countOfRibs));
    for (int i = 0; i < countOfVertex; i++) {
        for (int j = 0; j < countOfRibs; j++) {
            fscanf(fileWithIncidenceMatrix, "%d", &incidenceMatrix[i][j]);
        }
    }
    return incidenceMatrix;
}

vector<vector<int>> getAdjacencyMatrix(FILE *fileWithAdjacencyMatrix, int countOfVertex, int countOfRibs,
                                       vector<vector<int>> incidenceMatrix) {
    vector<vector<int>> adjacencyMatrix(countOfVertex, vector<int>(countOfVertex));
    int connectedVertices[2] = {-1, -1};
    int countV = 0;
    for (int i = 0; i < countOfRibs; i++) {
        for (int k = 0; k < countOfVertex; k++) {
            if (incidenceMatrix[k][i] == 1) {
               connectedVertices[countV] = k;
                countV++;
                if (countV > 2) {
                    break;
                }
            }
        }

        if (connectedVertices[0] != -1 && connectedVertices[1] != -1) {
            adjacencyMatrix[connectedVertices[0]][connectedVertices[1]] = 1;
            adjacencyMatrix[connectedVertices[1]][connectedVertices[0]] = 1;
        }
        countV = 0;
        connectedVertices[0] = -1;
        connectedVertices[1] = -1;
    }
    return adjacencyMatrix;
}

void showAdjacencyMatrix(int countVertex, vector<vector<int>> adjacencyMatrix) {
    printf("Adjacency Matrix:");
    for (int i = 0; i < countVertex; i++) {
        printf("\n");
        for (int k = 0; k < countVertex; k++) {
            printf("%d ", adjacencyMatrix[i][k]);
        }
    }
}

int main() {
    FILE *fileWithAdjacencyMatrix = getFileWithIncidenceMatrix();
    int countOfVertex = getCountVertexFromFile(fileWithAdjacencyMatrix);
    int countOfRibs = getCountRibsFromFile(fileWithAdjacencyMatrix);
    vector<vector<int>> incidentMatrix(countOfVertex, vector<int>(countOfRibs));
    incidentMatrix = getIncidenceMatrixFromFile(fileWithAdjacencyMatrix, countOfVertex, countOfRibs);
    vector<vector<int>> adjacencyMatrix(countOfVertex, vector<int>(countOfVertex));
    adjacencyMatrix = getAdjacencyMatrix(fileWithAdjacencyMatrix, countOfVertex, countOfRibs, incidentMatrix);
    showAdjacencyMatrix(countOfVertex, adjacencyMatrix);


}
