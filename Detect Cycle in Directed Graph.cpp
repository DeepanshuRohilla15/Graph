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

bool dfsCheck(int node, vector<int> vis, vector<int> pathVis, vector<int> adj[])
{
    vis[node] = 1;
    pathVis[node] = 1;

    for(auto it : adj[node])
    {
        if(!vis[it])
        {
            if(dfsCheck(it, vis , pathVis, adj) == true)
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
    return false;
}

bool isCyclic(int V, vector<int> adj[])
{
    vector<int> vis(V, 0);
    vector<int> pathVis(V, 0);

    for(int i = 0; i < V; i++)
    {
        if(!vis[i])
        {
            if(dfsCheck(i, vis, pathVis, adj) == true)
            {
                return true;
            }
        }
    }
    return false;
}