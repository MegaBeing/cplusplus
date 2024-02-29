#include<bits/stdc++.h> 
using namespace std;
void place(vector<vector<int>> board, int row, int col, int size){
    for(int i=row;i<size;i++){
        board[i][col]=0;
    }
    for(int i=0;i<)
}
int NQ(int size){
    vector<vector<int>> board(size,vector<int>(size,-1));
    int count=0;
    int i=0,prev=0;
    while(i<size){
        for(int j=0;j<size;j++){
            if(board[i][j]==-1){
                place(board,i,j,size);
                prev=i;
                i++;
            }
        }

        if(i==prev){
            i--;
            unplace(board,i,size);
        }
        if(i==size){
            count++;
            i--;
        }
    }
}
int main(){
    int size;
    cout<<"No of Queens: ";
    cin>>size;
    cout<<"No of permutations"<<NQ(size)<<endl;
    return 0;
}