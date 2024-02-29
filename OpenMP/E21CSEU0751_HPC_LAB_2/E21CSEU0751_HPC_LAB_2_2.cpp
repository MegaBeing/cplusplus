#include<bits/stdc++.h>
#include<omp.h>
using namespace std;
int parallel_linear_search(vector<int>arr,int n,int a)
{ 
  int found_index = -1;
  //only two elements per thread
#pragma omp parallel for 
  for(int i=0;i<n;i+=2)
  {
#pragma omp critical
    if(arr[i]==a)
      {
        if(found_index==-1)
          found_index = i;
      }
  }
  return found_index;
}
int main()
{
  int n;
  cout<<"Size:> ";
  cin>>n;
  vector<int>arr;
  cout<<"Enter Array:>\n";
  int a;
  for(int i=0;i<n;i++)
  {
    cin>>a;
    arr.push_back(a);
  }
  cout<<"Enter Target:> ";
  cin>>a;
  int dec = parallel_linear_search(arr,n,a);
  if(dec!=-1)
    cout<<"Found"<<endl;
  else 
    cout<<"Not Found"<<endl;
}
