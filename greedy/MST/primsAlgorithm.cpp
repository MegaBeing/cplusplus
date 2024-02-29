#include <bits/stdc++.h>
using namespace std;
int s = INT_MAX;
bool check = false;
void Create(vector<vector<int>> mat, int startingVertex, vector<bool> &visited, vector<pair<int, int>> &Distance, vector<pair<int, int>> &MST, int ver)
{
    // update the distance vector
    for (int i = 0; i < ver; i++)
    {
        if (i != startingVertex)
            if (mat[startingVertex][i] < Distance[i].second)
            {
                Distance[i].second = mat[startingVertex][i];
                Distance[i].first = startingVertex;
            }
    }
    /*
    1. Finding the minimum element in Distance array
    2. Also vertex shouldn't be visited
    3. no inner loops in the vertex
    */
    int index;
    for (int i = 0; i < ver; i++)
    {
        if (s > Distance[i].second && !visited[i] && i != startingVertex)
        {
            s = Distance[i].second;
            index = i;
        }
    }
    MST.push_back(make_pair(Distance[index].first, index));
    visited[index] = true;
    startingVertex = index;
    s = INT_MAX;
    for (int i = 0; i < ver; i++)
    {
        if (visited[i] == false)
            break;
        if (visited[ver - 1] == true && i == ver - 1)
            check = true;
    }
    if (!check)
        Create(mat, startingVertex, visited, Distance, MST, ver);
    else
        return;
}
void primMst(vector<vector<int>> mat, int ver)
{
    vector<bool> visited(ver, false); // visited array: Bool
    vector<pair<int, int>> MST;       // MST: (vertex1,vertex2)
    cout << "Starting Vertex: ";
    int stVr;
    cin >> stVr;
    vector<pair<int, int>> Dist(ver, make_pair(stVr, INT_MAX)); // Distance array: (startingVertex,distance)
    if (ver >= stVr)
    {
        visited[stVr] = true;
        Dist[stVr].second = 0;
        Dist[stVr].first = stVr;
    }
    Create(mat, stVr, visited, Dist, MST, ver);
    // printing the MST
    for (int i = 0; i < MST.size(); i++)
    {
        cout << MST[i].first << " -> " << MST[i].second << endl;
    }
}
int main()
{
    int ver;
    // just for testing purposes
    // ver = 5;
    // vector<vector<int>> mat = {{0, 2, INT_MAX, 6, INT_MAX},
    //                            {2, 0, 3, 8, 5},
    //                            {INT_MAX, 3, 0, INT_MAX, 7},
    //                            {6, 8, INT_MAX, 0, 9},
    //                            {INT_MAX, 5, 7, 9, 0}};

    // we will use this when we will take input
    cout << "Ver: ";
    cin >> ver;
    vector<vector<int>> mat(ver, vector<int>(ver, INT_MAX));
    int a, b, weight;
    // input adjacency matrix
    for (int i = 0; i < ver; i++)
    {
        for (int j = 0; j < ver; j++)
        {
            cin >> mat[i][j];
        }
    }
    primMst(mat, ver);
    return 0;
}