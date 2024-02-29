#include <bits/stdc++.h>
using namespace std;
void insert(vector<int> &arr, int val, int pos)
{
    arr.push_back(val);
    int j = pos - 1;
    int i = pos / 2 - 1;
    while (i >= 0)
    {
        if (arr[i] > arr[j])
            swap(arr[i], arr[j]);
        else
            break;
        j = i;
        i = (i + 1) / 2 - 1;
    }
}
int main()
{
    vector<int> arr = {5, 4, 3, 2, 1};
    int size = arr.size();
    vector<int> heap;
    for (int i = 0; i < size; i++)
    {
        insert(heap, arr[i], i + 1);
    }
    for (int i = 0; i < size; i++)
    {
        cout << heap[i] << " ";
    }
    return 0;
}