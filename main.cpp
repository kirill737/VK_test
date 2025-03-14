#include <iostream>
#include <vector>
#include <queue>
#include <fstream>

using namespace std;

vector<int> bfs(const vector<vector<int>>& graph, int start) {
    queue<int> q;
    int n = graph.size();
    vector<int> distances(n, -1);
    q.push(start);
    distances[start] = 0;
    
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        
        for (int neighbor : graph[v]) {
            if (distances[neighbor] == -1) {
                distances[neighbor] = distances[v] + 1;
                q.push(neighbor);
            }
        }
    }

    return distances;
}

int main() {
    // Считывание графа из файла
    ifstream input_file("graph.txt");
    if (!input_file) {
        cerr << "Ошибка открытия файла!" << endl;
        return 1;
    }
    
    int n;
    int m;
    input_file >> n >> m;
    vector<vector<int>> graph(n);
    
    for (int i = 0; i < m; i++) {
        int u;
        int v;
        input_file >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    
    int start;
    input_file >> start;
    input_file.close();
    
    // Расчёт расстояний до всех вершин
    vector<int> distances = bfs(graph, start);
    
    // Вывод полученного результата
    for (int i = 0; i < n; i++) {
        cout << distances[i];
        if (i != n - 1) // Чтобы избежать последний перенос строки
            cout << endl; 
    }
    
    return 0;
}
