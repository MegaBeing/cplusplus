#include<bits/stdc++.h>
using namespace std;
int main(){
   vector<long long> catlan;
   catlan.push_back(1);
   catlan.push_back(1);
   int target;
   cin>>target;
   long long val;
   for(int i=2;i<=target;i++){
    val = 0;
    for(int j=0;j<i;j++){
        val += catlan[j] * catlan[i-j-1];
    }
    catlan.push_back(val);
   } 
   cout<<catlan[target-1]<<endl;
}