#include <iostream>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#include <string>
#include <bitset>
#include <vector>
#include <set>
#include <map>
#include <unordered_map>
#include <queue>
#include <algorithm>
#include <sstream>
#include <stack>
#include <iomanip>
#include <climits>
#include <assert.h>
#include <chrono>

using namespace std;

//BFS
bool check(int start, int V, vector<int>adj[], vector<int> &color)
{
    queue<int> q;
    q.push(start);
    color[start] = 0;
    while(!q.empty())
    {
        int node = q.front();
        q.pop();

        for(auto it : adj[node])
        {
            if(color[it] == -1)
            {
                color[it] = !color[start];
                q.push(it);
            }
            else if(color[it] == color[node])
            {
                return false;
            }
        }
    }
    return true;
}

bool isBipartite(int V, vector<int>adj[])
{
    vector<int> color(V, -1);
    for(int i =0; i < V; i++)
    {
        if(color[i] == -1)
        {
            if(check(i, V, adj, color) == false)
            {
                return false;
            }
        }
    }
    return true;
}

bool dfs(int node, int col, vector<int> &color, vector<int> adj[])
{
    color[node] = col;
    for(auto it : adj[node])
    {
        if(color[it] == -1)
        {
            if(dfs(it, !col, color, adj) == false)
            {
                return false;
            }
        }
        else if(color[it] == col)
        {
            return false;
        }
    }
    return true;
}

bool isBipartite(int V, vector<int>adj[])
{
    vector<int> color(V, -1);
    for(int i = 0; i <V; i++)
    {
        if(color[i] == -1)
        {
            if(dfs(i, 0, color, adj) == false)
            {
                return false;
            }
        }
    }
    return true;
}