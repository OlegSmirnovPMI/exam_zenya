//
// Created by Олег on 29.06.2024.
//
/*
 матрица задается в файле adjacency_matrix.txt в виде
 a b
 1 2 3 4 5
 6 7 8 9 10
 12 13 14 15 ...и т.д, где a - количество вершин, b - количество ребер
 */
#include <cstdio>
#include <vector>
using namespace std;
FILE *getFileWithAdjacencyMatrix() {
    return fopen("../adjacency_matrix.txt", "r");
}
int getCountVertexFromFile(FILE *fileWithAdjacencyMatrix) {
    int countOfVertex;
    fscanf(fileWithAdjacencyMatrix,"%d",&countOfVertex);
    return countOfVertex;
}
int getCountRibsFromFile(FILE *fileWithAdjacencyMatrix) {
    int countOfRibs;
    fscanf(fileWithAdjacencyMatrix,"%d",&countOfRibs);
    return countOfRibs;
}
vector<vector<int>> getAdjacencyMatrixFromFile(FILE *fileWithAdjacencyMatrix, int countOfVertex) {
    vector<vector<int>> adjacencyMatrix(countOfVertex, vector<int>(countOfVertex));
    for (int i = 0; i < countOfVertex; i++) {
        for (int j = 0; j < countOfVertex;j++) {
            fscanf(fileWithAdjacencyMatrix,"%d",&adjacencyMatrix[i][j]);
        }
    }
    return adjacencyMatrix;
}
vector<vector<int>> getIncidenceMatrix(FILE *fileWithAdjacencyMatrix, int countOfVertex,int countOfRibs,vector<vector<int>> adjacencyMatrix) {
    vector<vector<int>> incidenceMatrix(countOfVertex, vector<int>(countOfRibs));
    int currentRib = 0;
    for (int i = 0; i < countOfVertex; i++) {
       for (int k = i+1; k < countOfVertex; k++) {
           if (adjacencyMatrix[i][k] == 1) {
               incidenceMatrix[i][currentRib] = 1;
               incidenceMatrix[k][currentRib] = 1;
               currentRib++;
           }
       }
   }
    return incidenceMatrix;
}

void showIncidentMatrix(int countVertex,int countRibs,vector<vector<int>> incidentMatrix) {
    printf("Incident Matrix:");
    for (int i = 0; i < countVertex; i++) {
        printf("\n");
        for (int k = 0; k < countRibs;k++) {
            printf("%d ",incidentMatrix[i][k]);
        }
    }
}


int main() {
FILE *fileWithAdjacencyMatrix = getFileWithAdjacencyMatrix();
int countOfVertex = getCountVertexFromFile(fileWithAdjacencyMatrix);
int countOfRibs = getCountRibsFromFile(fileWithAdjacencyMatrix);
vector<vector<int>> adjacencyMatrix(countOfVertex, vector<int>(countOfVertex));
adjacencyMatrix = getAdjacencyMatrixFromFile(fileWithAdjacencyMatrix,countOfVertex);
vector<vector<int>> incidenceMatrix(countOfVertex, vector<int>(countOfRibs));
incidenceMatrix = getIncidenceMatrix(fileWithAdjacencyMatrix,countOfVertex,countOfRibs,adjacencyMatrix);
showIncidentMatrix(countOfVertex,countOfRibs,incidenceMatrix);


}
