//
// Created by Олег on 01.07.2024.
#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <string>
#include <queue>
/*
 Алгоритм обхода графа в ширину.Выводит кратчайшие пути до каждой вершины. Или 1e9 если пути нет.
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
const int INF = 1e9;
using namespace std;

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

vector<int> bfs(vector<vector<int>> &graph, int start) {
    vector<int> visited(graph.size());
    vector<int> dist(graph.size(), INF);
    queue<int> q;
    visited[start] = 1;
    dist[start] = 0;
    q.push(start);
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        for (int to: graph[v]) {
            if (!visited[to]) {
                visited[to] = 1;
                dist[to] = dist[v] + 1;
                q.push(to);
            }
        }
    }
    return dist;
}

void showMinimalDistances(vector<int> &graph) {
    for (int dist : graph) {
            cout << dist << " ";
    }
    cout << endl;
}

int main() {
    vector<vector<int>> graph;
    ifstream fileWithListOfAdjacency = getFileWithListOfAdjacency();
    if (!fileWithListOfAdjacency.is_open()) {
        cerr << "Error with file. Can not open" << endl;
        return 1;
    }
    graph = getListOfAdjacency(fileWithListOfAdjacency);
    vector<int> dist = bfs(graph, 0);
    showMinimalDistances(dist);
}
