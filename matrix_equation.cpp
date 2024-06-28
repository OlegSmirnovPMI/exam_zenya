#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;
/*
матрица задется в файле как
 1 2
 3 4
 5 6
 7 8
 */
/*
 соотвественно 1 2
               3 4 это матрица A, а 5 6
                                    7 8 матрица B
 */
/*
 название файла для работы matrices.txt
 */

FILE *getFileWithMatrices() {
    return fopen("../matrices.txt", "r");
}

vector<vector<float>> getFirstMatrixFromFile(FILE *fp) {
    vector<vector<float>> firstMatrix(2, vector<float>(2));
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            fscanf(fp, "%f", &firstMatrix[i][j]);
        }
    }
    return firstMatrix;
}

vector<vector<float>> getSecondMatrixFromFile(FILE *fp) {
    vector<vector<float>> secondMatrix(2, vector<float>(2));
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            fscanf(fp, "%f", &secondMatrix[i][j]);
        }
    }
    return secondMatrix;
}

float getDeterminant(vector<vector<float>> firstMatrix) {
    return firstMatrix[0][0] * firstMatrix[1][1] - firstMatrix[0][1] * firstMatrix[1][0];
}

vector<vector<float>> getInverseMatrix(vector<vector<float>> firstMatrix) {
    float determinant = getDeterminant(firstMatrix);
    if (determinant != 0) {
        vector<vector<float>> inverseMatrix(2, vector<float>(2));
        inverseMatrix[0][0] = firstMatrix[1][1];
        inverseMatrix[0][1] = -firstMatrix[0][1];
        inverseMatrix[1][0] = -firstMatrix[1][0];
        inverseMatrix[1][1] = firstMatrix[0][0];
        for (int i = 0; i < 2; ++i) {
            for (int j = 0; j < 2; ++j) {
                inverseMatrix[i][j] /= determinant;
            }
        }
        return inverseMatrix;
    } else {
        printf("No solutions");
        return {};
    }
}

vector<vector<float>> getMultipliedMatrix(vector<vector<float>> firstMatrix, vector<vector<float>> secondMatrix) {
    vector<vector<float>> resultMatrix(2, vector<float>(2, 0));
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 2; ++j) {
            for (int k = 0; k < 2; ++k) {
                resultMatrix[i][j] += firstMatrix[i][k] * secondMatrix[k][j];
            }
        }
    }
    return resultMatrix;
}

void showSolutionOfEquation(vector<vector<float>> resultMatrix) {
    for (int i = 0; i < 2; i++) {
        printf("\n");
        for (int j = 0; j < 2; j++) {
            printf("%f ", resultMatrix[i][j]);
        }
    }
}


int main() {
    FILE *fp = getFileWithMatrices();
    if (fp == nullptr) {
        printf("Error.Can not open the file with matrices");
        return 1;
    } else {
        vector<vector<float>> firstMatrix(2, vector<float>(2));
        vector<vector<float>> secondMatrix(2, vector<float>(2));
        vector<vector<float>> inverseMatrix(2, vector<float>(2));
        vector<vector<float>> resultMatrix(2, vector<float>(2));
        firstMatrix = getFirstMatrixFromFile(fp);
        secondMatrix = getSecondMatrixFromFile(fp);
        inverseMatrix = getInverseMatrix(firstMatrix);
        resultMatrix = getMultipliedMatrix(inverseMatrix, secondMatrix);
        showSolutionOfEquation(resultMatrix);
    }
    return 0;
}
