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

vector<int> shortestPath(int n, int m, vector<vector<int>> &edges)
{
    vector<pair<int, int>> adj[n+1];
    for(auto it : edges)
    {
        adj[it[0]].push_back({it[1], it[2]});
        adj[it[1]].push_back({it[0], it[2]});
    }
    vector<int> dist(n+1, 1e9), parent(n+1);
    for(int i = 1; i <= n; i++) parent[i] = i;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    dist[1] = 0;
    pq.push({0, 1});
    while(!pq.empty())
    {
        auto it = pq.top();
        int node = it.second;
        int dis = it.first;
        pq.pop();

        for(auto it: adj[node])
        {
            int adjNode = it.first;
            int edgW = it.second;
            if(dis + edgW < dist[adjNode])
            {
                dist[adjNode] = dis + edgW;
                pq.push({dist[adjNode], adjNode});
                parent[adjNode] = node;
            }
        }
    }
    if(dist[n] == 1e9) return {-1};
    vector<int> path;
    int node = n;
    while(parent[node] != node)
    {
        path.push_back(node);
        node = parent[node];
    }
    path.push_back(1);
    reverse(path.begin(), path.end());
    return  path;

}