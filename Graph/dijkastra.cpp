#include<bits/stdc++.h>

using namespace std;

/*
     void dijkastra( vector<vector<pair<int,int>>> &g, vector<int> &res, int src)
     {
     priority_queue<pair<int,int>,vector<pair<int,int>>, greater<pair<int,int>>> pq;
     vector<int> visited(g.size(),0);
     pq.push({0,src});
     res[src] = 0;
 
     while(pq.empty() == false)
     {
     int node = pq.top().second;
     int wt= pq.top().first;
     //cout << node << "\n";
     pq.pop();
 
     if(visited[node] == 1)
     continue;
 
     visited[node] = 1;
 
     for(pair<int,int> e : g[node])
     {
     int temp_node = e.second;
     int temp_wt = e.first + wt;
 
     if(visited[temp_node] == 0 && res[temp_node] > temp_wt)
     {
     pq.push({temp_wt,temp_node});
     res[temp_node] = temp_wt;
     }
     }
     }
     }
 */
void dijkastra(vector<vector<pair<int,int>>> &g, vector<int> &res, int s)
{
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    pq.push({0,s});
    
    while(pq.empty() == false)
    {
        int node = pq.top().second;
        int wt = pq.top().first;
        pq.pop();
        
        if(res[node] > wt)
        {
            res[node] = wt;
            for(int i =0; i< g[node].size(); i++)
            {
                int end_node = g[node][i].second;
                int wt1 = g[node][i].first + wt;
                if(res[end_node] > wt1)
                {
                    pq.push({wt1,end_node});
                }
            }
        }
    }
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
    }
    
    vector<int> res(v,1000000000);
    dijkastra(g,res,0);
    
    for(int i =1; i< res.size(); i++)
    {
        cout << res[i] << " ";
    }
    
    return 0;
}

