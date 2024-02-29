#include <bits/stdc++.h>
using namespace std;
int deleted_item;
int del(vector<int> &heap, int &size)
{
    // int size = heap.size();
    deleted_item = heap[0];
    heap[0] = heap[size - 1];
    size--;
    for (int i = 0; i < size; i++)
    {
        cout << heap[i] << " ";
    }
    cout<<endl;
    int pos = 1;
    int c1 = pos * 2, c2 = pos * 2 + 1;
    while (c1 - 1 < size || c2 - 1 < size)
    {
        if (heap[c1 - 1] < heap[pos - 1])
        {
            if (c2 - 1 < size && heap[c2 - 1] < heap[c1 - 1])
            {
                swap(heap[pos - 1], heap[c2 - 1]);
                pos = c2 + 1;
            }
            else
            {
                swap(heap[pos - 1], heap[c1 - 1]);
                pos = c1;
            }
            for (int i = 0; i < size; i++)
            {
                cout << heap[i] << " ";
            }
            cout << endl;
        }
        else if (c2 - 1 < size && heap[c2 - 1] < heap[pos - 1])
        {
            swap(heap[pos - 1], heap[c2 - 1]);
            pos = c2;
            for (int i = 0; i < size; i++)
            {
                cout << heap[i] << " ";
            }
            cout << endl;
        }
        else
        {
            for (int i = 0; i < size; i++)
            {
                cout << heap[i] << " ";
            }
            cout << endl;
            break;
        }
        c1 = c1 * 2;
        c2 = (c2) * 2 + 1;
    }
    return deleted_item;
}
int main()
{
    vector<int> heap = {1, 2, 3, 4, 5};
    int size = 5;
    cout << "Deleted Element : " << del(heap, size) << endl;
    for (int i = 0; i < size; i++)
    {
        cout << heap[i] << " ";
    }
    return 0;
}