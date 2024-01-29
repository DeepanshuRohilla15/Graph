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

int countPaths(int n, vector<vector<int>>& roads)
{
    vector<pair<int, int>> adj[n];
    for(auto it : roads)
    {
        adj[it[0]].push_back({it[1], it[2]});
        adj[it[1]].push_back({it[0], it[2]});
    }

    int mod = (int)(1e9 + 7);
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int, int>>> pq;
    vector<long> dist(n, 1e18);
    vector<int> ways(n, 0);
    dist[0] = 0;
    ways[0] = 1;
    pq.push({0, 0}); // dis, node

    while(!pq.empty())
    {
        long dis = pq.top().first;
        int node = pq.top().second;
        pq.pop();

        for(auto it : adj[node])
        {
            int adjNode = it.first;
            long edW = it.second;
            // first time
            if(dis + edW < dist[adjNode])
            {
                dist[adjNode] = dis + edW;
                ways[adjNode] = ways[node];
                pq.push({dist[adjNode], adjNode});
            }
            else if(dis + edW == dist[adjNode])
            {
                ways[adjNode] = (ways[adjNode] + ways[node])%mod;
            }
        }
    }
    return ways[n-1] % mod;
}