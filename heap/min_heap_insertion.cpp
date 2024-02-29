#include<bits/stdc++.h>
using namespace std;
void insert(vector<int>&heap,int val,int &size){
    heap.push_back(val);
    size++;
    int pos = size;
    int parent = size/2;
    while(parent>0){
        if(heap[pos-1]<heap[parent-1]){
            swap(heap[pos-1],heap[parent-1]);
            pos = parent;
            parent /=2;
        }
        else{
            break;
        }
    }
}
int main(){
    vector<int> heap = {1, 3, 4, 5, 6};
    int size = 5;
    cout<<"Enter value to be inserted: ";
    int val;
    cin>>val;
    insert(heap,val,size);
    cout<<"New heap is as follows:\n";
    for (int i = 0; i < size; i++)
    {
        cout << heap[i] << " ";
    }
    return 0;
}