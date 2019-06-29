#include<bits/stdc++.h>

using namespace std;

int prim(vector<vector<pair<int,int>>> &g, int s)
{
    int res = 0;
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    vector<int> visited(g.size(),0);
    
    pq.push({0,s});
    
    while(pq.empty() == false)
    {
        int node = pq.top().second;
        int wt = pq.top().first;
        pq.pop();
        
        if(visited[node] == 0)
        {
            res += wt;
            visited[node] = 1;
            
            for(int i =0; i< g[node].size(); i++)
            {
                int end_node = g[node][i].second;
                int wt1 = g[node][i].first;
                
                if(visited[end_node] == 0)
                {
                    pq.push({wt1,end_node});
                }
            }
        }
    }
    return res;
}

int main()
{
    int v,e;
    cin >> v >> e;
    
    vector<vector<pair<int,int>>> g(v,vector<pair<int,int>> (0));
    
    for(int i =0; i< e; i++)
    {
        int a,b,w;
        cin >> a >> b >> w;
        g[a-1].push_back({w,b-1});
        g[b-1].push_back({w,a-1});
    }
    
    cout << prim(g,0);
    
    return 0;
}
