#include<bits/stdc++.h>
#include<omp.h>
using namespace std;
int main()
{
#pragma omp parallel for
  for(int i=0;i<10;i++)
  {
    printf("%i from thread %i \n",i, omp_get_thread_num());
  }
  return 0;
}
