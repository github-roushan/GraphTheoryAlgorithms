#include <iostream>
#include <vector>

using namespace std;

void dfs(int at, vector<vector<int>> &G, vector<bool> &visited)
{
    if (visited[at])
        return;
    visited[at] = true;
    for (auto next : G[at])
        dfs(next, G, visited);
}

int main()
{
    int N = 12;               // Number of Nodes
    vector<vector<int>> g(N); // adjacency list representation of graph
    g[0].push_back(1);
    g[0].push_back(9);

    g[1].push_back(8);
    g[1].push_back(0);

    g[2].push_back(3);
    g[3].push_back(5);

    g[3].push_back(7);
    g[3].push_back(2);
    g[3].push_back(4);

    g[4].push_back(3);

    g[5].push_back(6);
    g[5].push_back(3);

    g[6].push_back(7);
    g[6].push_back(5);

    g[7].push_back(8);
    g[7].push_back(10);
    g[7].push_back(11);
    g[7].push_back(6);
    g[7].push_back(3);

    g[8].push_back(1);
    g[8].push_back(9);
    g[8].push_back(7);

    g[9].push_back(0);
    g[9].push_back(8);

    g[10].push_back(7);
    g[10].push_back(11);

    g[11].push_back(10);
    g[11].push_back(7);

    vector<bool> visited(N, false);

    // start dfs from node 0 (root)
    dfs(0, g, visited);
    return 0;
}