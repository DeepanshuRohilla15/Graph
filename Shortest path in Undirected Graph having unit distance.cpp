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

vector<int> shortestPath(vector<vector<int>>& edges, int N,int M, int src)
{
    // create graph
    vector<int> adj[N];
    for(auto it : edges)
    {
        adj[it[0]].push_back(it[1]);
        adj[it[1]].push_back(it[0]);
    }

    vector<int> dist(N);
    for(int i = 0; i < N; i++) dist[i] = 1e9;
    dist[src] = 0;

    queue<int> q;
    q.push(src);
    while(!q.empty())
    {
        int node = q.front();
        q.pop();
        for(auto it : adj[node])
        {
            if(dist[node] + 1 < dist[it])
            {
                dist[it] = dist[node] + 1;
                q.push(it);
            }
        }
    }

    for(int i = 0; i < N; i++)
    {
        if(dist[i] == 1e9) dist[i] = -1;
    }
    return dist;
}