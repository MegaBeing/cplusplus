#include <bits/stdc++.h>
using namespace std;
void Sort(vector<vector<int>> &mat, int power)
{
    vector<int> arr(pow(10, power), 0); // defining an vector for count sort
    // trying to sort every vector inside the 2D vector
    int g;
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < mat[i].size(); j++)
        {
            /*
            saving the element on the array:
            for eg:
            element = 399;
            so we will be storing the element on i=3;
            we will be iterating over the remainder of the element with bucket size(power)
            rem = 399 / pow(10,power)
            => rem = 399 / 100 ;
            rem = 99;
            so we will add one on '99' index in the sorting array(arr) here;
            */
            g = mat[i][j] % (int)pow(10, power);
            arr[g]++;
        }
        // clearing the vector element of the 2D vector to store the sorted list
        mat[i].clear();
        // adding the elements in the sorted manner
        for (int j = 0; j < arr.size(); j++)
        {
            ;
            for (int k = 0; k < arr[j]; k++)
            {
                mat[i].push_back(i * (int)pow(10, power) + j);
            }
        }
        for (int i = 0; i < arr.size(); i++)
        {
            arr[i] = 0;
        }
    }
}
void bucket(vector<int> &arr, int size)
{
    int m = *max_element(arr.begin(), arr.end());
    int count = 0;
    // finding the size of the bucket
    while (m != 0)
    {
        m /= 10;
        count++;
    }
    count--;
    vector<vector<int>> mat(10, vector<int>(1, 0)); // 2-D vector to store elements inside the buckets
    // removing first value
    for (int i = 0; i < mat.size(); i++)
        mat[i].pop_back();
    // adding elements to the bucket
    for (int i = 0; i < size; i++)
    {
        if (arr[i] > 0 * pow(10, count) && arr[i] < 1 * pow(10, count))
            mat[0].push_back(arr[i]);
        else if (arr[i] > 1 * pow(10, count) && arr[i] < 2 * pow(10, count))
            mat[1].push_back(arr[i]);
        else if (arr[i] > 2 * pow(10, count) && arr[i] < 3 * pow(10, count))
            mat[2].push_back(arr[i]);
        else if (arr[i] > 3 * pow(10, count) && arr[i] < 4 * pow(10, count))
            mat[3].push_back(arr[i]);
        else if (arr[i] > 4 * pow(10, count) && arr[i] < 5 * pow(10, count))
            mat[4].push_back(arr[i]);
        else if (arr[i] > 5 * pow(10, count) && arr[i] < 6 * pow(10, count))
            mat[5].push_back(arr[i]);
        else if (arr[i] > 6 * pow(10, count) && arr[i] < 7 * pow(10, count))
            mat[6].push_back(arr[i]);
        else if (arr[i] > 7 * pow(10, count) && arr[i] < 8 * pow(10, count))
            mat[7].push_back(arr[i]);
        else if (arr[i] > 8 * pow(10, count) && arr[i] < 9 * pow(10, count))
            mat[8].push_back(arr[i]);
        else if (arr[i] > 9 * pow(10, count) && arr[i] < 10 * pow(10, count))
            mat[9].push_back(arr[i]);
    }
    // we will get a sorted matrix after that
    Sort(mat, count);
    arr.clear();
    for (int i = 0; i < mat.size(); i++)
    {
        for (int j = 0; j < mat[i].size(); j++)
        {
            arr.push_back(mat[i][j]);
        }
    }
}
int main()
{
    // taking array as an input
    cout << "Size: ";
    int size;
    cin >> size;
    vector<int> arr;
    int a;
    for (int i = 0; i < size; i++)
    {
        cin >> a;
        arr.push_back(a);
    }
    // just for the sack of simplicity
    // int size = 5;
    // vector<int> arr = {399, 265, 512, 112, 63};

    // no matter what it runs
    bucket(arr, size);
    cout << "Sorted:\n";
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}