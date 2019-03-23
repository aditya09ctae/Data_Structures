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

int rangeMinQuery(int segTree[],int low,int high,int qlow, int qhigh,int pos)
{
    //no overlap
    if(qlow >high || qhigh < low)
    return INT_MAX;
    
    if(qlow <= low && qhigh >= high)
    return segTree[pos];
    
    int mid = low+(high-low)/2;
    
    return min(rangeMinQuery(segTree,low,mid,qlow,qhigh,pos*2+1),rangeMinQuery(segTree,mid+1,high,qlow,qhigh,pos*2+2));
}



void updateSegTreeHelper(int segTree[],int index,int delta,int start, int end, int pos)
{
    if(index < start || index >end)
    return;
    
    if(start == end)
    {
        segTree[pos] += delta;
        return;
    }
    
    int mid = start + (end-start)/2;
    
    updateSegTreeHelper(segTree,index,delta,start,mid,2*pos+1);
    updateSegTreeHelper(segTree,index,delta,mid+1,end,2*pos+2);
    
    segTree[pos] = min(segTree[2*pos+1],segTree[pos*2+2]);
}

void updateSegTree(int arr[],int segTree[],int index, int new_val,int s, int e)
{
    arr[index] += new_val;
    updateSegTreeHelper(segTree,index,new_val,s,e,0);
}

void updateRangeHelper(int segTree[],int us, int ue, int new_val, int s,int e, int pos)
{
    if(ue < s || us > e || s > e)
    return;
    
    if(s == e)
    {
        segTree[pos] += new_val;
        return;
    }
    
    int mid = s + (e-s)/2;
    
    updateRangeHelper(segTree,us,ue,new_val,s,mid,pos*2+1);
    updateRangeHelper(segTree,us,ue,new_val,mid+1,e,pos*2+2);
    
    segTree[pos] = min(segTree[2*pos+1],segTree[2*pos+2]);
    
}

void updateSegTreeRange(int arr[],int segTree[],int us,int ue,int new_val,int s, int e)
{
    for(int i = us; i<= ue; i++)
    arr[i] += new_val;
    
    updateRangeHelper(segTree,us,ue,new_val,s,e,0);
}


int main()
{
    ios_base::sync_with_stdio(false);
    
    int t;
    cin >> t;
    
    while(t--)
    {
        int n;
        cin >> n;
        
        int arr[n];
        for(int i =0; i< n; i++)
        {
            cin >> arr[i];
        }
        
        /*for(int i =0; i< n; i++)
        {
            cout <<  arr[i] << "\n";
        }*/
        
        //make a new array for segment tree
        
        //find size
        
        int x = (int) ceil(log2(n));
        int size_of_tree = 2* (int) pow(2,x) - 1;
        
        int seg_tree[size_of_tree];
        
        for(int i=0; i< size_of_tree; i++)
        seg_tree[i] = INT_MAX;
        
        constructTree(arr,seg_tree,0,n-1,0);
        
        //for(int i=0; i<size_of_tree; i++)
        //cout << seg_tree[i] << " ";
        
        // find minimum range query
        int a,b;
        cin >> a >> b;
        
        cout << rangeMinQuery(seg_tree,0,n-1,2,3,0) << "\n";
        
        //update segTree
        updateSegTree(arr,seg_tree,2, -4,0,n-1);
        
        cout << rangeMinQuery(seg_tree,0,n-1,2,3,0) << "\n";
        
        updateSegTreeRange(arr,seg_tree,2,3,-10,0, n-1);
        
        cout << rangeMinQuery(seg_tree,0,n-1,0,5,0) << "\n";
        
    }
    return 0;
}
