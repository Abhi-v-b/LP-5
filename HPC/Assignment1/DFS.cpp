#include <iostream>
#include <vector>
#include <stack>
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
    vector<int> visited_nodes = dfs(start_node);

    // Print visited nodes
    cout << "Visited nodes: ";
    for (int node : visited_nodes) {
        cout << node << " ";
    }
    cout << endl;

    return 0;
}
