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

int CheapestFLight(int n, vector<vector<int>>& flights, int src, int dst, int K)
{
    vector<pair<int, int>> adj[n];
    for(auto it : flights)
    {
        adj[it[0]].push_back({it[1], it[2]});
    }

    vector<int> dist(n, 1e9);
    queue<pair<int, pair<int,int>>> q; // stops, {node, dist}
    dist[src] = 0;
    q.push({0, {src, 0}});

    while(!q.empty())
    {
        auto it = q.front();
        q.pop();
        int stops = it.first;
        int node = it.second.first;
        int dis = it.second.second;

        if(stops > K) continue;
        for(auto it : adj[node])
        {
            int adjNode = it.first;
            int edW = it.second;
            
            if(dis + edW < dist[adjNode])
            {
                dist[adjNode] = dis + edW;
                q.push({stops + 1, {adjNode, dist[adjNode]}});
            }
        }
    }
    if(dist[dst] == 1e9) return -1;
    return dist[dst];
}