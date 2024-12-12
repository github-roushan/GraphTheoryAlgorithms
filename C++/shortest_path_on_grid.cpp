#include <iostream>
#include <vector>
#include <queue>
#include <thread>
#include <chrono>

using namespace std;

bool check_with_bfs(pair<int, int> &source, pair<int, int> &dest, vector<vector<char>> &G);

bool is_within_bounds(pair<int, int> coord, vector<vector<char>> &G)
{
    return (0 <= coord.first && coord.first < G.size() &&
            0 <= coord.second && coord.second < G[0].size());
}

pair<int, int> find_symbol(const vector<vector<char>> &grid, char symbol)
{
    for (int i = 0; i < grid.size(); i++)
        for (int j = 0; j < grid[0].size(); j++)
            if (grid[i][j] == symbol)
                return make_pair(i, j);

    return make_pair(-1, -1); // Symbol not found
}

bool can_scape_dungeon(vector<vector<char>> &G)
{
    // find the source and exit nodes in the grid
    pair<int, int> source = find_symbol(G, 'S');
    pair<int, int> destination = find_symbol(G, 'E');
    if (source.first == -1)
        throw runtime_error("Source is not present");
    if (destination.first == -1)
        throw runtime_error("Destination is not present");

    return check_with_bfs(source, destination, G);
}

template <typename T>
void show(vector<vector<T>> &G)
{
    for (auto vec : G)
    {
        for (auto el : vec)
            cout << el << " ";
        cout << endl;
    }
    cout << endl;
}

bool check_with_bfs(pair<int, int> &source, pair<int, int> &dest, vector<vector<char>> &G)
{
    int N = G.size(), M = G[0].size();

    int dx[] = {-1, 1, 0, 0};
    int dy[] = {0, 0, 1, -1};

    vector<vector<bool>> visited(N, vector<bool>(M, false));

    queue<pair<int, int>> q;
    q.push(source);
    visited[source.first][source.second] = true;

    while (q.size())
    {
        pair<int, int> cur_coord = q.front();
        q.pop(); // deque queue to get current coordinate

        for (int i = 0; i < 4; i++)
        {
            int nx = cur_coord.first + dx[i];
            int ny = cur_coord.second + dy[i];

            pair<int, int> next_coord = make_pair(nx, ny);
            // check if nx and ny are out of Grid Bounds
            if (!is_within_bounds(next_coord, G)) continue;
            // check if next coord has an obstacle
            if (G[nx][ny] == '#') continue;
            // check if the cell has already been visited
            if (visited[nx][ny]) continue;

            if (next_coord == dest)
                return true;

            q.push(next_coord);
            visited[nx][ny] = true;
        }
    }
    return false;
}

// Dungeon Problem Solved using bfs
int main()
{
    // Create a vector of vectors to represent the grid
    vector<vector<char>> grid = {
        {'S', '.', '.', '#', '.', '.', '.', '.'},
        {'.', '#', '.', '.', '.', '#', '.', '.'},
        {'.', '#', '.', '.', '.', '.', '.', '.'},
        {'.', '.', '#', '#', '.', '.', '.', '.'},
        {'.', '#', '.', '#', '.', '.', '#', '.'},
        {'#', '.', '#', 'E', '.', '#', '.', '.'}};

    bool result = can_scape_dungeon(grid);
    if (result)
        cout << "Escaped\n";
    else
        cout << "Got Stuck\n";
    return 0;
}