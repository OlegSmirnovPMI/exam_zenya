#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <string>

using namespace std;

/*
 Алгоритм обхода графа в глубину.
 Граф представлен списком смежности в файле list_adjacency.txt
 Пример файла
0 4
1 4 2
2 1 5
3
4 0 1 5 6
5 2 4 7
6 4 7
7 6 5
где первая цифра в каждой строке - вершина, а все что правее список вершин с которыми данная вершина смежная.
 */

ifstream getFileWithListOfAdjacency() {
    ifstream fileWithListOfAdjacency("../list_adjacency.txt");
    return fileWithListOfAdjacency;
}

vector<vector<int>> getListOfAdjacency(ifstream &fileWithListOfAdjacency) {
    vector<vector<int>> listOfAdjacency;
    string line;
    while (getline(fileWithListOfAdjacency, line)) {
        stringstream ss(line);
        int vertex;
        ss >> vertex;
        listOfAdjacency.emplace_back();
        int neighbor;
        while (ss >> neighbor) {
            listOfAdjacency[vertex].push_back(neighbor);
        }
    }
    return listOfAdjacency;
}

void dfs(vector<vector<int>> &listOfAdjacency, int v, vector<int> &visited, vector<int> &order) {
    visited[v] = 1;
    order.push_back(v);
    for (int to: listOfAdjacency[v]) {
        if (!visited[to]) {
            dfs(listOfAdjacency, to, visited, order);
        }
    }
}

void showGraphTrack(vector<int> &order) {
    cout << "Track: " << endl;
    for (int vertex: order) {
        cout << vertex << " ";
    }
    cout << endl;
}

int main() {
    vector<vector<int>> listOfAdjacency;
    ifstream fileWithListOfAdjacency = getFileWithListOfAdjacency();
    if (!fileWithListOfAdjacency.is_open()) {
        cerr << "Error with file. Can not open" << endl;
        return 1;
    }
    listOfAdjacency = getListOfAdjacency(fileWithListOfAdjacency);
    int numVertices = listOfAdjacency.size();
    vector<int> visited(numVertices, 0);
    vector<int> order;
    int v = 1; //вершина от которой начинаем обход
    dfs(listOfAdjacency, v, visited, order);
    // цикл для поиска изолированных вершин.
    for (int v = 0; v < numVertices; v++) {
        if (!visited[v]) {
            dfs(listOfAdjacency, v, visited, order);
        }
    }
    showGraphTrack(order);
    fileWithListOfAdjacency.close();
    return 0;
}
