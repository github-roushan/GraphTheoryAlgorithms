#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// Explore all neighbor nodes in a layer
void bfs(int root, vector<vector<int>> &G, vector<bool>& visited)
{
    queue<int> q;
    q.push(root);
    visited[root] = true;
    while(q.size()){
        int cur_element = q.front(); q.pop(); // take the front element and deque the first element;
        for(auto next: G[cur_element]) {
            if(visited[next]) continue;
            q.push(next); // enque all the neighbors of the current element
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

    // run the bfs algorithm
    vector<bool> visited(N, false);
    bfs(0, graph, visited);

    return 0;
}