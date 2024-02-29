#include<bits/stdc++.h>
#include<omp.h>
using namespace std;
int Parallel_Sum(vector<int>a,int n)
{ 
  // Performing Parallel operations to just update b_array with the sum of th both the arrays
  int sum = 0;
  #pragma omp parallel for 
  for(int i=0;i<n;i++)
  {
#pragma omp atomic
    sum += a[i];
    printf("Performing Operation from thread %i \n", omp_get_thread_num());
  }
  return sum;
}
int main()
{
  int n;
  cout<<"Size :> ";
  cin>>n;
  vector<int>a(n);
  cout<<"First Array:>\n";
  for(int i=0;i<n;i++)
  {
    cin>>a[i];
  }
  int sum = Parallel_Sum(a,n);
  cout<<"Sum:> "<<sum<<endl;
  return 0;
}
