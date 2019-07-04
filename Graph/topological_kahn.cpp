#include<bits/stdc++.h>

using namespace std;

vector<int> topological_sort(vector<vector<int>> &g,vector<int> &inorder)
{
    vector<int> res;
    
    if(g.size() == 0)
    return res;
    
    //int v = g.size();
    priority_queue<int,vector<int>,greater<int>> pq;
    
    for(int i =0; i< inorder.size(); i++)
    {
        if(inorder[i] == 0)
        pq.push(i);
    }
    
    while(pq.empty() == false)
    {
        int temp = pq.top();
        pq.pop();
        
       // cout << "\n" << temp << "->" ;
        
        res.push_back(temp);
        for(int i =0; i< g[temp].size(); i++)
        {
            //cout << g[temp][i] << " ";
            inorder[g[temp][i]] = inorder[g[temp][i]] -1;
            if(inorder[g[temp][i]] == 0)
            pq.push(g[temp][i]);
        }
    }
    
    if(res.size() != g.size())
    {
        vector<int> res1;
       // cout << "inside res1";
        return res1;
    }
    
    return res;
}

int main()
{
    int v,e;
    cin >> v >> e;
    
    vector<int> inorder(v,0);
    vector<vector<int>> g(v,vector<int>(0));
    
    // build graph
    for(int i =0; i< e; i++)
    {
        int a,b;
        cin >> a >> b;
        
        g[a-1].push_back(b-1);
        inorder[b-1] = inorder[b-1] + 1;
    }
    
    /*for(int i =0; i< v; i++)
    {
        cout << i << "->";
        for(int j =0; j < g[i].size(); j++)
        {
            cout << g[i][j] << " ";
        }
        cout << "\n";
    }*/
    
    vector<int> res;
    res = topological_sort(g,inorder);
    
    //cout << res.size();
    
    for(int i=0; i< res.size();i++)
    {
        cout << res[i]+1 << " ";
    }
    cout << "\n";
    return 0;
}
