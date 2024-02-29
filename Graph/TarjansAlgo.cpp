#include<bits/stdc++.h>
using namespace std;
void dfs(vector<vector<int>>mat,vector<int>&low, vector<int> &disc, int node, vector<bool> inStack,stack<int> &vis,int &time){
  
}
void wrapTar(vector<vector<int>> mat,int size){
    vector<int> low(size,-1);
    vector<int> disc(size,-1);
    vector<bool> inStack(size,false);
    stack<int> vis;
    int time=0;
    dfs(mat,low,disc,node,inStack,vis,time);
    
}
int main(){
        int ver;
    // just for testing purposes

    ver = 5;
    vector<vector<int>> mat = {{0,1,INT_MAX,INT_MAX,INT_MAX,INT_MAX,INT_MAX},
                               {INT_MAX,0,1,1,INT_MAX,INT_MAX,INT_MAX},
                               {INT_MAX,INT_MAX,0,INT_MAX,INT_MAX,INT_MAX,INT_MAX},
                               {INT_MAX,INT_MAX,INT_MAX,0,1,INT_MAX,INT_MAX},
                               {1,INT_MAX,INT_MAX,INT_MAX,0,1,1},
                               {INT_MAX,INT_MAX,INT_MAX,INT_MAX,INT_MAX,0,1},
                               {INT_MAX,INT_MAX,INT_MAX,INT_MAX,INT_MAX,1,0}};

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
    //         if(i==j){
    //             mat[i][j]=0;
    //             continue;
    //         }
    //         cin >> mat[i][j];
    //     }
    // }
    wrapTar(mat,ver);
    return 0;
}