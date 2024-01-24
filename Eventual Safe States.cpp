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

// Modified cycle detection in direted graph
bool dfsCheck(int node, vector<int> &vis, vector<int> &pathVis, vector<int> adj[], vector<int> &check)
{
    vis[node] = 1;
    pathVis[node] = 1;
    check[node] = 0;

    for(auto it: adj[node])
    {
        if(!vis[it])
        {
            if(dfsCheck(it, vis, pathVis, adj, check) == true)
            {
                return true;
            }
        }
        else if(pathVis[it])
        {
            return true;
        }
    }

    pathVis[node] = 0;
    check[node] = 1;
    return false;
}

vector<int> eventualSafeNodes(int V, vector<int> adj[])
{
    vector<int> vis(V, 0);
    vector<int> pathVis(V, 0);
    vector<int> check(V, 0);
    vector<int> safeNodes;

    for(int i = 0; i < V; i++)
    {
        if(!vis[i])
        {
            dfsCheck(i, vis, pathVis, adj, check);
        }
    }

    for(int i = 0; i < V; i++)
    {
        if(check[i] == 1)
        {
            safeNodes.push_back(i);
        }
    }
    return safeNodes;
}