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

void dfs(int node, vector<int> adj[], vector<int> &vis, vector<int> &ls)
{
    vis[node] = 1;
    ls.push_back(node);

    for(auto it: adj[node])
    {
        if(!vis[it])
        {
            dfs(it, adj, vis, ls);
        }
    }
}

vector<int> dfsOfGraph(int V, vector<int> adj[])
{

    vector<int> vis(V, 0);
    int start = 0;
    vector<int> ls;
    dfs(start, adj, vis, ls);
    return ls;
}