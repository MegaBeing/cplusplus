#include <bits/stdc++.h>
using namespace std;
int *parent = new int[100];
void makeset(int a)
{
    parent[a] = a;
}
int find(int i)
{
    if (parent[i] == i)
    {
        return i;
    }
    return parent[i];
}
void unions(int a, int b)
{
    int ap = find(a);
    int bp = find(b);
    parent[ap]=bp;
}
void krushkalMst(vector<vector<int>> mat, int ver)
{
    for (int i = 0; i < ver; i++)
    {
        makeset(i);
    }
    sort(mat.begin(), mat.end());
    int start, end, weight;
    int x, y;
    for (int i = 0; i < mat.size(); i++)
    {
        start = mat[i][1];
        end = mat[i][2];
        weight = mat[i][0];
        x = find(start);
        y = find(end);
        if (x != y)
        {
            cout << start << " -> " << end << " " << weight << endl;
            unions(x,y);
        }
    }
}
int main()
{
    int ver;

    // just for testing purposes
    // ver = 5;
    // vector<vector<int>> mat = {{10, 0, 1},
    //                            {6, 0, 2},
    //                            {5, 0, 3},
    //                            {15, 1, 3},
    //                            {4, 2, 3}};

    // we will use this when we will take input
    int edges;
    cout << "edges: ";
    cin >> edges;
    cout << "Ver: ";
    cin >> ver;
    vector<vector<int>> mat(ver, vector<int>(ver, INT_MAX));
    int a, b, weight;
    for (int i = 0; i < edges; i++)
    {
        cin >> a >> b >> weight;
        mat[a][b] = weight;
        mat[b][a] = weight;
    }
    krushkalMst(mat, ver);
    delete [] parent;
    return 0;
}