#include <bits/stdc++.h>
using namespace std;
void fun(vector<vector<int>> arr, int mx, int buffer)
{  
    int timer = 0;
    int j = 0, st = 0;
    int count = 0, g = 0;
    sort(arr.begin(),arr.end());
    while (st >= 0)
    {
        timer++;
        if (j < arr.size())
            if (timer == arr[j][0])
            {
                st += arr[j][1];
                j++;
            }
        if (st > mx){
        
            g = st - mx;
            count += g;
            st -= g;
        }
        if (st >= 0)
        {
            st -= buffer;
        }
    }
    cout<<count<<endl;
}
int main()
{
    vector<vector<int>> arr = {{3,5},{1,5}};
    cout << "rate: ";
    int buffer;
    cin >> buffer;
    cout << "Max: ";
    int mx;
    cin >> mx;
    fun(arr, mx, buffer);
    return 0;
}