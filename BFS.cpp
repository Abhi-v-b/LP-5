#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main() {
    int num_vertices, num_edges, source;
    cin >> num_vertices >> num_edges >> source;

    vector<vector<int>> adj_list(num_vertices + 1);
    for (int i = 0; i < num_edges; i++) {
        int u, v;
        cin >> u >> v;
        adj_list[u].push_back(v);
        adj_list[v].push_back(u);
    }

    queue<int> q;
    vector<bool> visited(num_vertices + 1, false);
    q.push(source);
    visited[source] = true;

    while (!q.empty()) {
        int curr_vertex = q.front();
        q.pop();
        cout << curr_vertex << " ";

        for (int i = 0; i < adj_list[curr_vertex].size(); i++) {
            int neighbour = adj_list[curr_vertex][i];
            if (!visited[neighbour]) {
                visited[neighbour] = true;
                q.push(neighbour);
            }
        }
    }

    return 0;
}

























#INPUT:   
  # 1 --- 2
 # / \   / \
# 0   \ /   3
#      4     \
#       \     \
 #       5 --- 6
        
        
#7 8
#0   
#0 1
#0 4
#1 2
#1 4
#2 3
#2 5
#3 6
#5 6
#OUTPUT :
#0 1 4 2 3 5 6 
