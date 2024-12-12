#include <iostream>
#include <vector>

using namespace std;

void dfs(int at, vector<vector<int>> &G, vector<bool> &visited, int &componentCount, vector<int>&components);

void findComponents(int nodes, vector<vector<int>>&G, vector<bool>&visited, int &componentCount, vector<int>&components) {
    for(int i=0; i<nodes; i++){
        if(!visited[i]){
            componentCount++; 
            dfs(i, G, visited, componentCount, components);
        }
    }
}

void dfs(int at, vector<vector<int>> &G, vector<bool> &visited, int &componentCount, vector<int>&components)
{
    if (visited[at])
        return;
    visited[at] = true;
    components[at] = componentCount;
    for (auto next : G[at])
        dfs(next, G, visited, componentCount, components);
}

int main()
{
    int N = 7;                 // Number of Nodes
    vector<vector<int>> g(N);  // adjacency list representation of graph
    g[0].push_back(1);
    g[0].push_back(2);

    g[1].push_back(0);
    g[1].push_back(2);

    g[2].push_back(0);
    g[2].push_back(1);

    g[3].push_back(5);

    g[4].push_back(5);

    g[5].push_back(6);
    g[5].push_back(3);
    g[5].push_back(4);

    g[6].push_back(5);

    vector<bool> visited(N, false);

    int count = 0;
    vector<int> componentId(N, 0);

    // run the function to find connected components
    findComponents(N, g, visited, count, componentId);
    cout << count << endl;
    return 0;
}