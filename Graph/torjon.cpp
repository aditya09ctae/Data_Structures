#include<bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;

void dfs(vvi &g, vi &ap, vector<pair<int,int>> &bridges, vi &visited, vi &parent,vi &desc, vi &low,int x,int &t)
{
    int child =0;
    
    visited[x] = 1;
    
    desc[x]= low[x] = t++;
    
    for(int i =0; i< g[x].size(); i++)
    {
        int temp = g[x][i];
        
        if(parent[x] == temp)
        continue;
        
        if(visited[temp] == 0)
        {
            child++;
            parent[temp] = x;
            
            //visited[temp] = 1;
            dfs(g,ap,bridges,visited,parent,desc,low,temp,t);
            
            low[x] = min(low[x],low[temp]);
            
            if(parent[x] == -1 && child > 1)
            ap.push_back(x);
            
            if(parent[x] != -1 && low[temp] >= desc[x])
            {
                ap.push_back(x);
                
            }
            
            if(low[temp] > desc[x])
            {
                bridges.push_back({x,temp});
            }
            
        }
        else if(temp != parent[x])
        {
            low[x] = min(low[x],desc[temp]);
        }
    }
}
void APandBridges(vector<vector<int>> &g,vector<int> &ap, vector<pair<int,int>> &bridges)
{
    int v = g.size();
    vector<int> visited(v,0);
    vector<int> parent(v,-1);
    vector<int> desc(v,0);
    vector<int> low(v,0);
    
    int t = 0;
    
    for(int i =0; i< v; i++)
    {
        if(visited[i] == 0)
        {
            //visited[i] = 1;
            dfs(g,ap,bridges,visited,parent,desc,low,i,t);
        }
    }
}

int main()
{
    int v,e;
    cin >> v >> e;
    
    vector<vector<int>> g(v,vector<int> (0));
    
    for(int i=0; i< e; i++)
    {
        int a,b;
        cin >> a >> b;
        
        g[a].push_back(b);
        g[b].push_back(a);
    }
    
    vector<int> ap;
    vector<pair<int,int>> bridges;
    
    APandBridges(g,ap,bridges);
    sort(ap.begin(),ap.end());
    
    cout << ap.size() << "\n";
    
    for(int i =0; i< ap.size(); i++)
    {
        cout << ap[i] << " ";
    }
    
    cout << "\n";
    
    sort(bridges.begin(),bridges.end());
    
    cout << bridges.size() << "\n";
    
    for(int i =0; i< bridges.size(); i++)
    {
        cout << bridges[i].first << " " << bridges[i].second << "\n";
    }
    return 0;
}
