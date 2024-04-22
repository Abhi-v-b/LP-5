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















2nd method 
#include <iostream>
#include <queue>
#include <vector>
#include <ctime> // Include the ctime library for time measurement
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

    // Start measuring time
    clock_t start = clock();

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

    // Stop measuring time
    clock_t end = clock();
    double duration = double(end - start) / CLOCKS_PER_SEC;
    cout << "\nExecution time: " << duration << " seconds" << endl;

    return 0;
}



INPUT:

7 8
0
0 1
0 4
1 2
1 4
2 3
2 5
3 6
5 6
OUTPUT:
0 1 4 2 3 5 6 
Execution time: 2.7e-05 seconds



3rd Method:

#include <iostream>
#include <queue>
#include <vector>
#include <ctime>
#include <omp.h>
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

    double start = omp_get_wtime();

    while (!q.empty()) {
        int q_size = q.size();

        #pragma omp parallel
        {
            #pragma omp for
            for (int i = 0; i < q_size; i++) {
                int curr_vertex;
                #pragma omp critical
                {
                    curr_vertex = q.front();
                    q.pop();
                }
                cout << curr_vertex << " ";

                for (int j = 0; j < adj_list[curr_vertex].size(); j++) {
                    int neighbour = adj_list[curr_vertex][j];
                    #pragma omp critical
                    {
                        if (!visited[neighbour]) {
                            visited[neighbour] = true;
                            q.push(neighbour);
                        }
                    }
                }
            }
        }
    }

    double end = omp_get_wtime();
    double duration = end - start;
    cout << "\nExecution time: " << duration << " seconds" << endl;

    return 0;
}

OutPut:
4 4
0
0 1
1 3
0 2
2 3
0 2 1 3 
Execution time: 0.000255912 seconds
