#include <bits/stdc++.h>
using namespace std;
void Sort(vector<int> &arr, int f)
{
    vector<pair<int, vector<int>>> sc(10, make_pair(0, vector<int>(1, 0)));
    /*
    creating a vector which stores a pair of:
        integer: used for storing values for count sort
        vector<int>: stores the corresponding value from the array
    */

    // just popping the first element declared
    for (int i = 0; i < 10; i++)
    {
        sc[i].second.pop_back();
    }
    /*
    we have to perform this following operation
    if f=0
        this means that we have to extract the 'unit' place number
        so, 1 MODULES is enough to extract it
        remainder = array_element % 10
    */
    if (f == 0)
    {
        int rem;
        for (int i = 0; i < arr.size(); i++)
        {
            rem = arr[i] % 10;
            sc[rem].first++;
            sc[rem].second.push_back(arr[i]);
        }
        arr.clear();
        for (int i = 0; i < sc.size(); i++)
        {
            if (sc[i].first > 0)
            {
                for (int j = 0; j < sc[i].second.size(); j++)
                {
                    arr.push_back(sc[i].second.at(j));
                }
            }
        }
    }
    /*
    else
        this means that we have to extract the digit other than 'unit' place
        so, we have to DIVIDE 'f' number of times before
        taking the MODULUS
    */
    else
    {
        int rem, n, s;
        for (int i = 0; i < arr.size(); i++)
        {
            n = arr[i];
            for (int j = 0; j < f; j++)
            {
                n /= 10;
            }
            rem = n % 10;
            sc[rem].first++;
            sc[rem].second.push_back(arr[i]);
        }
        arr.clear();
        for (int i = 0; i < sc.size(); i++)
        {
            if (sc[i].first > 0)
            {
                for (int j = 0; j < sc[i].second.size(); j++)
                {
                    arr.push_back(sc[i].second.at(j));
                }
            }
        }
    }
}
void radix(vector<int> &arr, int size)
{
    int mx = *max_element(arr.begin(), arr.end());
    int count = 0;
    // finding the number of digits of the maximum number
    while (mx != 0)
    {
        mx /= 10;
        count++;
    }
    // we will do the operation of Sort 'count'(digits) number of times
    for (int i = 0; i < count; i++)
    {
        Sort(arr, i);
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
    radix(arr, size);
    cout << "Sorted:\n";
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}