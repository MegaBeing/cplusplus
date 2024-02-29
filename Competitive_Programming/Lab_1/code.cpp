#include <bits/stdc++.h>
using namespace std;
vector<int> Give_me_answer(vector<vector<float>> mat)
{
    int size = mat.size();
    int start_pos = 0, sub_size = 1;
    int max_size = 0, real_start = 0;
    for (int i = 1; i < size; i++)
    {
        if (mat[i][0] > mat[i - 1][0] && mat[i][1] > mat[i-1][1])
        {
            if (start_pos == 0)
            {
                start_pos = i;
            }
            sub_size++;
        }
        else
        {
            if (sub_size > max_size)
            {
                max_size = sub_size;
                real_start = start_pos;
            }
            sub_size = 1;
            start_pos = 0;
        }
    }
return {max_size, real_start};
}
int main()
{
    // vector<vector<float>> mat = {{1.2, 4.5},
    //                              {1.0, 3.5},
    //                              {1.4, 3.8},
    //                              {1.1, 2.0},
    //                              {2.5, 2.5},
    //                              {3.5, 3.2},
    //                              {3, 7, 2.75}};
    vector<vector<float>> mat;
    int size;
    cout<<"Size: ";
    cin>>size;
    float a, b;
    for(int i=0;i<size;i++){
        cin>>a>>b;
        mat.push_back({a,b});
    }
    vector<int> ans = Give_me_answer(mat);
    cout << "Max Size: " << ans[0] << "\nStart Pos: " << ans[1] << endl;
    return 0;
}