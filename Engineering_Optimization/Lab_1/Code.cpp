#include <bits/stdc++.h>
using namespace std;
void merge(vector<int> a, int beg, int mid, int end)
{
    int i, j, k;
    int n1 = mid - beg + 1;
    int n2 = end - mid;

    int LeftArray[n1], RightArray[n2];

    for (int i = 0; i < n1; i++)
        LeftArray[i] = a[beg + i];
    for (int j = 0; j < n2; j++)
        RightArray[j] = a[mid + 1 + j];

    i = 0;
    j = 0;
    k = beg;
    int res = 1;
    while (i < n1 && j < n2)
    {
        if (LeftArray[i] <= RightArray[j])
        {
            a[k] = LeftArray[i];
            i++;
        }
        else
        {
            a[k] = RightArray[j];
            j++;
        }
        k++;
    }
    while (i < n1)
    {
        a[k] = LeftArray[i];
        i++;
        k++;
    }

    while (j < n2)
    {
        a[k] = RightArray[j];
        j++;
        k++;
    }
}
int give_product(vector<int> arr, int beg, int mid, int end)
{
    int a = 1, b = 1;
    for (int i = beg; i <= mid; i++)
    {
        a *= arr[i];
    }
    for (int i = beg; i <= mid; i++)
    {
        b *= arr[i];
    }
    return max(a, b);
}

void mergeSort(vector<int> a, int beg, int end, int &product)
{
    if (beg < end)
    {
        int mid = (beg + end) / 2;
        mergeSort(a, beg, mid, product);
        mergeSort(a, mid + 1, end, product);
        product = max(give_product(a, beg, mid, end), product);
        merge(a, beg, mid, end);
    }
}

int main()
{
    vector<int> arr;
    cout << "Size: ";
    int size;
    cin >> size;
    int a;
    for (int i = 0; i < size; i++)
    {
        cin >> a;
        arr.push_back(a);
    }
    // int curr_product, max_product = INT_MIN;
    // for (int i = 0; i < size; i++)
    // {
    //     curr_product = arr[i];
    //     max_product = max(curr_product, max_product);
    //     for (int j = i + 1; j < size; j++)
    //     {
    //         curr_product *= arr[j];
    //         max_product = max(curr_product, max_product);
    //     }
    // }
    // cout << "Max_product: " << max_product << endl;
    int product = INT_MIN;
    mergeSort(arr, 0, size - 1, product);
    cout << "Max_product: " << product << endl;
    return 0;
}