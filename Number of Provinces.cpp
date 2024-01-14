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

void dfs(int node, vector<int> adj[], vector<int> &vis)
{
    vis[node] = 1;
    for(auto it: adj[node])
    {
        if(!vis[it])
        {
            dfs(it, adj, vis);
        }
    }
}

int findProvinces(vector<vector<int>> &adjMatrix, int V)
{
    // to change the adjacency matrix to list
    vector<int> adj[V];
    for(int i = 0; i < V; i++)
    {
        for(int j = 0; j <V; j++)
        {
            if(adjMatrix[i][j] == 1 && i != j)
            {
                adj[i].push_back(j);
                adj[j].push_back(i);
            }
        }
    }

    vector<int> vis(V, 0);
    int cnt  = 0;
    for(int i = 0; i < V; i++)
    {
        if(!vis[i])
        {
            dfs(i, adj, vis);
        }
    }
    return cnt;
}