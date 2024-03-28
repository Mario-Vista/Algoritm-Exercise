#include <iostream>
#include <fstream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

struct Edge {
    int source, destination, weight;
};

class Graph {
private:
    int V; // Numero di nodi
    vector<vector<Edge>> adjList; // Lista di adiacenza

public:
    Graph(int nodes) : V(nodes), adjList(nodes) {}

    void addEdge(int source, int destination, int weight) {
        Edge edge = {source, destination, weight};
        adjList[source].push_back(edge);
    }

    // Utilizzato nell'ordinamento topologico
    void topologicalSortUtil(int v, vector<bool>& visited, stack<int>& stack) {
        visited[v] = true;

        for (const Edge& edge : adjList[v]) {
            if (!visited[edge.destination]) {
                topologicalSortUtil(edge.destination, visited, stack);
            }
        }

        stack.push(v);
    }

    // Ordinamento topologico
    vector<int> topologicalSort() {
        vector<bool> visited(V, false);
        stack<int> stack;

        for (int i = 0; i < V; ++i) {
            if (!visited[i]) {
                topologicalSortUtil(i, visited, stack);
            }
        }

        vector<int> result;
        while (!stack.empty()) {        
            result.push_back(stack.top());
            stack.pop();
        }

        return result;
    }

    void writeTopologicalOrderToFile(const string& filename) {
        ofstream outFile(filename);

        if (!outFile.is_open()) {
            cerr << "Unable to open file: " << filename << endl;
            return;
        }

        vector<int> order = topologicalSort();
        for (int node : order) {
            outFile << node << " ";
        }

        outFile.close();
    }
};

int main() {
    ifstream inFile("GRP.txt");

    if (!inFile.is_open()) {
        cerr << "Unable to open file." << endl;
        return 1;
    }

    int nodes, edges;
    inFile >> nodes >> edges;

    Graph graph(nodes);

    for (int i = 0; i < edges; ++i) {
        int source, destination, weight;
        inFile >> source >> destination >> weight;
        graph.addEdge(source, destination, weight);
    }

    inFile.close();

    graph.writeTopologicalOrderToFile("out.txt");

    return 0;
}
