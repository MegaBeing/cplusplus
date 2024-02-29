#include<bits/stdc++.h>
using namespace std; 
void printMat(vector<vector<int>> mat, int ver){
    cout<<"{";
    for(int i=0;i<ver;i++){
        cout<<"{ ";
        for(int j=0;j<ver;j++){
            if(j!=ver-1)
                cout<<mat[i][j]<<", ";
            else
                cout<<mat[i][j]<<" }";
        }
        cout<<",\n";
    }
    cout<<" }";
}
void floydWarshall(vector<vector<int>> mat, int ver){
    for(int k=0;k<ver;k++){
        for(int i=0;i<ver;i++){
            for(int j=0;j<ver;j++){
                if (mat[i][j] > (mat[i][k] + mat[k][j])
                    && (mat[k][j] != INT_MAX
                        && mat[i][k] != INT_MAX))
                    mat[i][j] = mat[i][k] + mat[k][j];
            }
        }
    }
    printMat(mat,ver);
}
int main(){
    int ver;
    // just for testing purposes
    ver = 5;
    vector<vector<int>> mat = {{0, 2, INT_MAX, 6, INT_MAX},
                               {2, 0, 3, 8, 5},
                               {INT_MAX, 3, 0, INT_MAX, 7},
                               {6, 8, INT_MAX, 0, 9},
                               {INT_MAX, 5, 7, 9, 0}};

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
    floydWarshall(mat, ver);
    return 0;
}