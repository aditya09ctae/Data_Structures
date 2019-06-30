---
tags: ["leetcode","dynamic programming","heap","breadth-first search"]
created: "30/06/2019, 15:50:52"
difficulty: "medium"
---

# [0787-cheapest-flights-within-k-stops](https://leetcode.com/problems/cheapest-flights-within-k-stops/)

## Problem
<div><p>There are <code>n</code> cities connected by&nbsp;<code>m</code> flights. Each fight starts from city&nbsp;<code>u </code>and arrives at&nbsp;<code>v</code> with a price <code>w</code>.</p><br><br><p>Now given all the cities and flights, together with starting city <code>src</code> and the destination&nbsp;<code>dst</code>, your task is to find the cheapest price from <code>src</code> to <code>dst</code> with up to <code>k</code> stops. If there is no such route, output <code>-1</code>.</p><br><br><pre><strong>Example 1:</strong><br><strong>Input:</strong> <br>n = 3, edges = [[0,1,100],[1,2,100],[0,2,500]]<br>src = 0, dst = 2, k = 1<br><strong>Output:</strong> 200<br><strong>Explanation:</strong> <br>The graph looks like this:<br><img alt="" src="https://s3-lc-upload.s3.amazonaws.com/uploads/2018/02/16/995.png" style="height:180px; width:246px"><br><br>The cheapest price from city <code>0</code> to city <code>2</code> with at most 1 stop costs 200, as marked red in the picture.</pre><br><br><pre><strong>Example 2:</strong><br><strong>Input:</strong> <br>n = 3, edges = [[0,1,100],[1,2,100],[0,2,500]]<br>src = 0, dst = 2, k = 0<br><strong>Output:</strong> 500<br><strong>Explanation:</strong> <br>The graph looks like this:<br><img alt="" src="https://s3-lc-upload.s3.amazonaws.com/uploads/2018/02/16/995.png" style="height:180px; width:246px"><br><br>The cheapest price from city <code>0</code> to city <code>2</code> with at most 0 stop costs 500, as marked blue in the picture.</pre><br><br><p><strong>Note:</strong></p><br><br><ul><br>	<li>The number of&nbsp;nodes&nbsp;<code>n</code> will be&nbsp;in range <code>[1, 100]</code>, with nodes labeled from <code>0</code> to <code>n</code><code> - 1</code>.</li><br>	<li>The&nbsp;size of <code>flights</code> will be&nbsp;in range <code>[0, n * (n - 1) / 2]</code>.</li><br>	<li>The format of each flight will be <code>(src, </code><code>dst</code><code>, price)</code>.</li><br>	<li>The price of each flight will be in the range <code>[1, 10000]</code>.</li><br>	<li><code>k</code> is in the range of <code>[0, n - 1]</code>.</li><br>	<li>There&nbsp;will&nbsp;not&nbsp;be&nbsp;any&nbsp;duplicated&nbsp;flights or&nbsp;self&nbsp;cycles.</li><br></ul><br></div>

## Solution

c++
```c++
class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {        
        vector<int> res(n,1e9);
        res[src] = 0;
        
        for(int i =0; i<= K; i++)
        {
            vector<int> temp_vec(res);
            for(auto e: flights)
            {
                if(temp_vec[e[1]] > res[e[0]] + e[2])
                temp_vec[e[1]] = res[e[0]] + e[2];
            }
           res = temp_vec;
        }
        
        if(res[dst] == 1e9)
            return -1;
        
        return res[dst];
    }
};
​
```
