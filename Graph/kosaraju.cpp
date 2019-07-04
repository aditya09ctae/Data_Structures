#include<bits/stdc++.h>
using namespace std;


void printGraph(vector<vector<int>> &g)
{
    for(int i =0; i< g.size(); i++)
    {
        cout << i+1 << "->";
        for(int j =0; j<g[i].size(); j++)
        {
            cout << g[i][j] + 1 << " ";
        }
        cout << "\n";
    }
}

void dfs(vector<vector<int>> &g, vector<int> &visited, stack<int> &st, int v)
{
    for(int i =0; i< g[v].size(); i++)
    {
        int temp = g[v][i];
        if(visited[temp] == 0)
        {
            visited[temp] = 1;
            dfs(g,visited,st,temp);
        }
    }
    st.push(v);
}


int kosaraju(vector<vector<int>> &g)
{
    // step 1 . push in stack all DFSed node
    
    stack<int> st;
    vector<int> visited(g.size(),0);
    
    for(int i =0;i <g.size(); i++)
    {
        if(visited[i] == 0)
        {
            visited[i] = 1;
            dfs(g,visited,st,i);
        }
    }
    
    // step 2. reverse the graph
    
    vector<vector<int>> g_dash(g.size(),vector<int>(0));
    
    for(int i =0; i< g.size(); i++)
    {
        for(int j=0; j< g[i].size(); j++)
        {
            g_dash[g[i][j]].push_back(i);
        }
    }
    
   // cout << "rev graph is";
  // printGraph(g_dash);
    
    // step 3. pop element from stack and DFS on reverse graph
    
    vector<int> visited_dash(g.size(),0);
    int odd_cnt =0;
    int even_cnt = 0;
    
    while(st.empty() == false)
    {
        stack<int> st1;
        int temp = st.top();
        st.pop();
        
        //cout << temp+1 << " -> ";
        
        if(visited_dash[temp] == 0)
        {
            visited_dash[temp] = 1;
            dfs(g_dash,visited_dash,st1,temp);
        }
        int cnt = st1.size();
        //cout << cnt << "\n";
        
        if(cnt % 2 == 0)
        even_cnt += cnt;
        else
        odd_cnt += cnt;
    }
    
    return odd_cnt - even_cnt;
}

int main()
{
    //build graph
    int v,e;
    cin >> v >> e;
    
    vector<vector<int>> g(v,vector<int>(0));
    
    for(int i =0; i< e; i++)
    {
        int a,b;
        cin >> a >> b;
        g[a-1].push_back(b-1);
    }
    
    //print graph
    //printGraph(g);
    
    //apply kosaraju algorithm
    
    cout << kosaraju(g);
    
    return 0;
}
