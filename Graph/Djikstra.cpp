#include <bits/stdc++.h>
using namespace std;
void rec(vector<vector<int>> mat, int vertex, vector<int> &distance, vector<bool> &visited)
{
    int indexVal, index;
    bool g = false;
    int size = mat[vertex].size();
    // Relaxation
    for (int i = 0; i < size; i++)
    {
        if (i != vertex)
            if (mat[vertex][i] != INT_MAX && distance[vertex] != INT_MAX)
                if (distance[i] > distance[vertex] + mat[vertex][i])
                    distance[i] = distance[vertex] + mat[vertex][i];
    }
    visited[vertex] = true;
    indexVal = INT_MAX;
    index = 0;
    for (int i = 0; i < size; i++)
    {
        if (!visited[i] && indexVal > distance[i])
        {
            indexVal = distance[i];
            index = i;
            g = true;
        }
    }
    if (g)
        rec(mat, index, distance, visited);
    else
        return;
}
void djikstra(vector<vector<int>> mat, int size)
{
    // distance vector
    vector<int> distance(size, INT_MAX);
    // visited vector
    vector<bool> visited(size, false);
    cout << "Starting Vertex: ";
    int start;
    cin >> start;
    distance[start] = 0;
    rec(mat, start, distance, visited);
    for (int i = 0; i < size; i++)
    {
        if (!visited[i])
            rec(mat, i, distance, visited);
    }
    // printing distance vector
    cout << "Distance Vector:\n";
    cout << "{ ";
    for (int i = 0; i < size; i++)
    {
        if (i != size - 1)
            if (distance[i] == INT_MAX)
                cout << "INF, ";
            else
                cout << distance[i] << ", ";

        else if (distance[i] == INT_MAX)
            cout << "INF ";
        else
            cout << distance[i] << " ";
    }
    cout << "}" << endl;
}
int main()
{
    int ver;
    // just for testing purposes

    ver = 5;
    vector<vector<int>> mat = {{0, 1, INT_MAX, 2, INT_MAX},
                               {INT_MAX, 0, INT_MAX, 7, 8},
                               {INT_MAX, 9, 0, INT_MAX, 11},
                               {INT_MAX, INT_MAX, 4, 0, 3},
                               {INT_MAX, INT_MAX, INT_MAX, INT_MAX, 0}};

    // we will use this when we will take input

    // cout << "Ver: ";
    // cin >> ver;
    // vector<vector<int>> mat(ver, vector<int>(ver, INT_MAX));
    // int a, b, weight;
    // // input adjacency matrix
    // for (int i = 0; i < ver; i++)
    // {
    //     for (int j = 0; j < ver; j++)
    //     {
    //         cin >> mat[i][j];
    //     }
    // }
    djikstra(mat, ver);
}