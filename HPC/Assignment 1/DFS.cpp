#include <iostream>
#include <vector>
#include <stack>
#include <ctime> // For time measurement
using namespace std;

const int MAXN = 1e5;
vector<int> adj[MAXN + 5]; // adjacency list
bool visited[MAXN + 5];     // mark visited nodes

vector<int> dfs(int start_node) {
    vector<int> visited_nodes;
    stack<int> stk;
    stk.push(start_node);
    while (!stk.empty()) {
        int node = stk.top();
        stk.pop();
        if (!visited[node]) {
            visited[node] = true;
            visited_nodes.push_back(node);
            for (int i = adj[node].size() - 1; i >= 0; i--) {
                int next_node = adj[node][i];
                if (!visited[next_node]) {
                    stk.push(next_node);
                }
            }
        }
    }
    return visited_nodes;
}

int main() {
    cout << "Please enter nodes and edges: ";
    int n, m; // number of nodes and edges
    cin >> n >> m;

    for (int i = 1; i <= m; i++) {
        int u, v; // edge between u and v
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int start_node; // start node of DFS
    cin >> start_node;

    // Measure execution time
    clock_t begin = clock();
    vector<int> visited_nodes = dfs(start_node);
    clock_t end = clock();
    double elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;

    // Print visited nodes
    cout << "Visited nodes: ";
    for (int node : visited_nodes) {
        cout << node << " ";
    }
    cout << endl;

    // Print execution time
    cout << "Execution time: " << elapsed_secs << " seconds" << endl;

    return 0;
}














INPUT:
Please enter nodes and edges: 6 6
0 1
0 2
1 3
2 4
3 5
4 5
0

OUTPUT:
Visited nodes: 0 1 3 5 4 2 
Execution time: 6e-06 seconds




2nd Method:
#include <iostream>
#include <vector>
#include <stack>
#include <algorithm> // For sorting
#include <ctime> // For time measurement
#include <omp.h> // OpenMP header
using namespace std;

const int MAXN = 1e5;
vector<int> adj[MAXN + 5]; // adjacency list
bool visited[MAXN + 5];     // mark visited nodes

vector<int> dfs(int start_node) {
    vector<int> visited_nodes;
    stack<int> stk;
    stk.push(start_node);
    while (!stk.empty()) {
        int node = stk.top();
        stk.pop();
        if (!visited[node]) {
            visited[node] = true;
            visited_nodes.push_back(node);
            #pragma omp parallel for // Parallelize the loop
            for (int i = 0; i < adj[node].size(); i++) {
                int next_node = adj[node][i];
                if (!visited[next_node]) {
                    stk.push(next_node);
                }
            }
        }
    }
    return visited_nodes;
}

int main() {
    cout << "Please enter nodes and edges: ";
    int n, m; // number of nodes and edges
    cin >> n >> m;

    for (int i = 1; i <= m; i++) {
        int u, v; // edge between u and v
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // Sort adjacent nodes to ensure ascending order
    for (int i = 0; i < n; i++) {
        sort(adj[i].begin(), adj[i].end());
    }

    int start_node; // start node of DFS
    cin >> start_node;

    // Measure execution time
    clock_t begin = clock();
    vector<int> visited_nodes = dfs(start_node);
    clock_t end = clock();
    double elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;

    // Print visited nodes
    cout << "Visited nodes: ";
    for (int node : visited_nodes) {
        cout << node << " ";
    }
    cout << endl;

    // Print execution time
    cout << "Execution time: " << elapsed_secs << " seconds" << endl;

    return 0;
}




OutPut:
Please enter nodes and edges: 6 5
0 1
0 2
1 3
1 4
2 5
0
Visited nodes: 0 2 5 1 4 3 
Execution time: 0.000161 seconds
