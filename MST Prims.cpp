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

int spanningTree(int V, vector<vector<int>> adj[])
{
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vector<int> vis(V, 0);
    pq.push({0, 0}); // wt, node
    int sum = 0;

    while(!pq.empty())
    {
        auto it = pq.top();
        pq.pop();
        int wt = it.first;
        int node = it.second;

        if(vis[node] == 1) continue;
        vis[node] = 1;
        sum += wt;

        for(auto it : adj[node])
        {
            int adjNode = it[0];
            int edW = it[1];
            if(!vis[adjNode])
            {
                pq.push({edW, adjNode});
            }
        }
    }
    return sum;
}