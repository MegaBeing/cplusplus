#include <bits/stdc++.h>
using namespace std;
int main()
{
    vector<int> arr1 = {4, 1, 2, 1, 1, 2};
    vector<int> arr2 = {3, 6, 3, 3};
    int size1 = arr1.size();
    int size2 = arr2.size();
    int sum1 = 0, sum2 = 0;
    for (int i = 0; i < size1; i++)
    {
        sum1 += arr1[i];
    }
    for (int i = 0; i < size2; i++)
    {
        sum2 += arr2[i];
    }
    vector<int> sol;
    for (int i = 0; i < size1; i++)
    {
        for (int j = 0; j < size2; j++)
        {
            if (sum1 - arr1[i] + arr2[j] == sum2 - arr2[j] + arr1[i])
            {
                sol.push_back(arr1[i]);
                sol.push_back(arr2[j]);
            }
        }
    }
    for (int i = 0; i < sol.size(); i++)
    {
        cout << sol[i] << " ";
    }
    return 0;
}