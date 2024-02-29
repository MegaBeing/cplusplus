#include<bits/stdc++.h>
using namespace std;
int Catlan(int target){
    vector<int> catlan;
    catlan.push_back(1);
    catlan.push_back(1);
    long long val;
    for(int i=2;i<=target;i++){
        val = 0;
        for(int j=0;j<i;j++){
            val += catlan[j] * catlan[i-j-1];
        }
        catlan.push_back(val);
    } 
    return catlan[target-1];
}
int main(){
    int n;
    cin>>n;
    if(n>=2){
        cout<<Catlan(n-1)<<endl;
    }
}