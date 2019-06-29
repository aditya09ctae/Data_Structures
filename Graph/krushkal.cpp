#include<bits/stdc++.h>

using namespace std;

int root(vector<int> &ds, int x)
{
    while(ds[x] != x)
    {
        ds[x] = ds[ds[x]];
        x = ds[x];
    }
    return x;
}

void un(vector<int> &ds,int u ,int v)
{
    int p = root(ds,u);
    int q = root(ds,v);
    
    ds[p] = ds[q];
}

int krushkal(vector<pair<int,pair<int,int>>> &g, vector<int> &ds)
{
    int res = 0;
    
    for(int i =0; i< g.size(); i++)
    {
        int w = g[i].first;
        int u = g[i].second.first;
        int v = g[i].second.second;
        
        if(root(ds,u) != root(ds,v))
        {
            res += w;
            un(ds,u,v);
        }
    }
    return res;
}

int main()
{
    int v,e;
    cin >> v >> e;
    
    vector<int> ds;
    
    //initilaize disjoint set
    
    for(int i =0; i< v; i++)
    {
        ds.push_back(i);
    }
    
    vector<pair<int,pair<int,int>>> g;
    
    for(int i =0; i< e; i++)
    {
        int a,b,w;
        cin >> a >> b >> w;
        g.push_back({w,{a-1,b-1}});
    }
    
    sort(g.begin(),g.end());
    
    cout << krushkal(g,ds);
    
    return 0;
}
