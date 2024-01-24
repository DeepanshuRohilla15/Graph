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

vector<int> findOrder(int V, int m, vector<vector<int>> prerequisites)
{
    vector<int> adj[V];
    // create a adjacency list
    for(auto it : prerequisites)
    {
        adj[it[1]].push_back(it[0]);
    }

    // create a indegree array
    vector<int> indegree(V, 0);
    for(int i = 0; i < V; i++)
    {
        for(auto it : adj[i])
        {
            indegree[it]++;
        }
    }

    queue<int> q;
    for(int i = 0; i < V; i++)
    {
        if(indegree[i] == 0)
        {
            q.push(i);
        }
    }

    vector<int> topo;
    while(!q.empty())
    {
        int node = q.front();
        q.pop();
        topo.push_back(node);
        for(auto it : adj[node])
        {
            indegree[it]--;
            if(indegree[it] == 0)
            {
                q.push(it);
            }
        }
    }

    if(topo.size() == V)
    {
        return topo;
    }
    return {};
}