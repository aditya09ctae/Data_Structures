//implementation of Binary Indexed Tree - Fenwick Tree

#include <bits/stdc++.h>
using namespace std;

// finding next node
int getNext(int val)
{
    return val + (val & -val);
}

// finding parent node
int getParent(int val)
{
    return val - (val & -val);
}

// used for creating the tree and updating the tree
void updateFenwickTree(int fw[],int n, int val, int size)
{
    int loc = n+1;
    while(loc < size)
    {
        fw[loc] += val;
        loc = getNext(loc);
    }
}

void createFenwickTree(int arr[],int fw[],int n)
{
    for(int i=0; i<n; i++)
    {
        updateFenwickTree(fw,i,arr[i],n+1);
    }
}

// print fenwick tree
void displayFenwickTree(int fw[],int n)
{
    for(int i=0; i< n; i++)
        cout << fw[i] << " ";
    
    cout << "\n";
}

// find sum from 0 to n
int getPrefixSum(int fw[],int n)
{
    int loc = n+1;
    int res =0;
    while(loc > 0)
    {
        res += fw[loc];
        loc = getParent(loc);
    }
    return res;
}

// find sum in range from s to e
int sumInRange(int fw[],int s, int e)
{
    return (getPrefixSum(fw,e) - getPrefixSum(fw,s));
}

int main() {
    
    int arr[] = {3, 5, 6, -1, 2, 4, 9, -7};
    int n = sizeof(arr)/sizeof(arr[0]);
    
    int fw[n+1];
    memset(fw,0,sizeof(int)*(n+1));
    
    createFenwickTree(arr,fw,n);
    
    displayFenwickTree(fw,n+1);
    
    //get some value
    
    for(int i =0; i< n ; i++)
    {
        cout << "sum till " << i << " is :" << getPrefixSum(fw,i) << "\n";
    }
    
    // update a value -- add 8 to 4th place tree
    //new tree is: arr[] = {3, 5, 6, -1, 10, 4, 9, -7};
    
    updateFenwickTree(fw,4,8,n+1);
    cout << "after update" << "\n";
    
    //get some value
    
    for(int i =0; i< n ; i++)
    {
        cout << "sum till " << i << " is :" << getPrefixSum(fw,i) << "\n";
    }
    
    int s= 3;
    int e= 5;
    int res = sumInRange(fw,s,e);
    
    cout << res << "\n";
    
    return 0;
}
