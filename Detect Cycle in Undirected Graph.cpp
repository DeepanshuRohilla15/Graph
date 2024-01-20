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

bool detect(int src, vector<int> adj[], vector<int> &vis)
{
    vis[src] = 1;
    queue<pair<int, int>> q;
    q.push({src, -1});
    while(!q.empty())
    {
        int node = q.front().first;
        int parent = q.front().second;
        q.pop();

        for(auto adjacentNode : adj[node])
        {
            if(!vis[adjacentNode])
            {
                vis[adjacentNode] = 1;
                q.push({adjacentNode, node});
            }
            else if(parent != adjacentNode)
            {
                return true;
            }
        }
    }
    return false;
}

bool isCycle(int V, vector<int> adj[]) {
    vector<int> vis(V, 0);
    // Components
    for(int i = 0; i < V; i++)
    {
        if(!vis[i])
        {
            if(detect(i, adj, vis)) return true;
        }
    }
    return false;

}