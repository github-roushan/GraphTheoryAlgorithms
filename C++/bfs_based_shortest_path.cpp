#include <iostream>
#include <vector>
#include <queue>
#include<algorithm>

using namespace std;

void bfs(int root, vector<vector<int>> &G, vector<bool>& visited, vector<int>&P);

vector<int> reconstruct_path(int source, int destination, vector<int>&prev_node){
    // find the previous node from destination until we reach source
    vector<int> path;
    int cur_node = destination;
    while(cur_node != -1){
        path.push_back(cur_node);
        cur_node = prev_node[cur_node];
    }
    reverse(path.begin(), path.end());
    return path;
}

vector<int> find_shortest_path(int source, int destination, vector<vector<int>>&G){
    int nodes = G.size();
    vector<bool> visited(nodes, false);
    vector<int> prev_node(nodes, -1);
    bfs(source, G, visited, prev_node);
    return reconstruct_path(source, destination, prev_node);
}

// Explore all neighbor nodes in a layer
void bfs(int root, vector<vector<int>> &G, vector<bool>& visited, vector<int>&P)
{
    queue<int> q;
    q.push(root);
    visited[root] = true;
    while(q.size()){
        int cur_element = q.front(); q.pop(); // take the front element and deque the first element;
        for(auto next: G[cur_element]) {
            if(visited[next]) continue;
            q.push(next); // enque all the neighbors of the current element
            P[next] = cur_element;
            visited[next] = true; // all elements that are enqueued even once are marked visited
        }
    }
}

int main()
{
    // Create an adjacency list to represent the graph
    int N = 13;
    vector<vector<int>> graph(N);

    // Add edges to the graph based on the image
    graph[0] = {11, 7, 9};
    graph[1] = {10, 8};
    graph[2] = {3, 12};
    graph[3] = {2, 4, 7};
    graph[4] = {3};
    graph[5] = {6};
    graph[6] = {5, 7, 11};
    graph[7] = {0, 3, 6, 11};
    graph[8] = {1, 9, 12};
    graph[9] = {0, 8, 10};
    graph[10] = {1, 9};
    graph[11] = {0, 6, 7};
    graph[12] = {2, 8};

    // find the shortest path from A to B
    vector<int> shortest_path = find_shortest_path(0, 12, graph);
    // Print the results
    for(auto node: shortest_path) cout << node << "->"; cout << endl;
    return 0;
}