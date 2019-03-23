#include<bits/stdc++.h>
using namespace std;

void constructTree(int arr[],int segTree[],int start,int end, int pos)
{
    if(start == end)
    {
        segTree[pos] = arr[start];
        return;
    }
    
    int mid = start + (end-start)/2;
    
    constructTree(arr,segTree,start,mid,pos*2+1);
    constructTree(arr,segTree,mid+1,end,pos*2+2);
    
    segTree[pos] = min(segTree[2*pos+1],segTree[2*pos+2]);
}

void updateLazyPropHelper(int segTree[],int lazy[],int start,int end,int s, int e, int new_val, int pos)
{
    if(start > end)
    return;
    
    //if lazy[pos] != 0
    
    if(lazy[pos] != 0)
    {
        segTree += lazy[pos];
        if(start != end) // check non leaf node
        {
            lazy[pos*2+1] += lazy[pos];
            lazy[pos*2+2] += lazy[pos];
        }
        
        lazy[pos] = 0;
    }
    
    //no overlap condition
    if(e<start || s > end)
    return;
    
    //total overlap condition
    if(s <= start && e >= end)
    {
        segTree[pos] += new_val;
        if(s != e)
        {
            lazy[2*pos+1] += new_val;
            lazy[2*pos+2] += new_val;
        }
        return;
    }
    
    //partial overlap --- both direction
    int mid = start + (end-start)/2;
    updateLazyPropHelper(segTree,lazy,start,mid,s,e,new_val,2*pos+1);
    updateLazyPropHelper(segTree,lazy,mid+1,end,s,e,new_val,2*pos+1);
    
    segTree[pos] = min(segTree[2*pos+1],segTree[2*pos+2]);
    
}
void updateLazyPropagation(int segTree[], int lazy[],int n,int s,int e,int new_val)
{
    updateLazyPropHelper(segTree,lazy,0,n,s,e,new_val,0);
}

int rangeLazyHelper(int segTree[],int lazy[], int start,int end, int s, int e, int pos)
{
    if(start > end)
    return INT_MAX;
    
    if(lazy[pos] != 0)
    {
        segTree[pos] += lazy[pos];
        if(start != end)
        {
            lazy[pos*2+1] = lazy[pos];
            lazy[pos*2+2] = lazy[pos];
        }
        lazy[pos] = 0;
    }
    
    //no ovetrlap
    if(s > end || e < start)
    return INT_MAX;
    
    //total ovaerlap
    if(s <= start && e>= end)
    {
        return segTree[pos];
    }
    
    //partial overlap
    int mid = start + (end-start)/2;
    
    return min(rangeLazyHelper(segTree,lazy,start,mid,s,e,2*pos+1),rangeLazyHelper(segTree,lazy,mid+1,end,s,e,2*pos+2));
}

int rangeLazyPropagation(int segTree[],int lazy[],int n, int s, int e)
{
    return rangeLazyHelper(segTree,lazy,0,n,s,e,0);
}

int main()
{
    ios_base::sync_with_stdio(false);
    
    int n;
        cin >> n;
        
        int arr[n];
        for(int i =0; i< n; i++)
        {
            cin >> arr[i];
        }
        
        int x = (int) ceil(log2(n));
        int size_of_tree = 2* (int) pow(2,x) - 1;
        
        int seg_tree[size_of_tree];
        int lazy[size_of_tree];
        
        for(int i=0; i< size_of_tree; i++)
        {
            seg_tree[i] = INT_MAX;
            lazy[i] = 0;
        }
        
        constructTree(arr,seg_tree,0,n-1,0);
        
        cout << "tree before updation: \n";
        
        for(int i =0; i< size_of_tree; i++)
        cout << seg_tree[i] << " ";
        
        cout << "\n";
        //update using lazy propagation
        
        updateLazyPropagation(seg_tree,lazy,n-1,2,3,-5);
        
        cout << "tree after updation: \n";
        
        for(int i =0; i< size_of_tree; i++)
        cout << seg_tree[i] << " ";
        
        cout << "\n";
        
        cout << rangeLazyPropagation(seg_tree,lazy,n-1, 4,5);
        
    return 0;
}
