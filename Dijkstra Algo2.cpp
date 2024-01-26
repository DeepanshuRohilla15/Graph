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

vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
{
    set<pair<int, int>> st;
    vector<int> dist(V, 1e9);
    st.insert({0, S});
    dist[S] = 0;

    while(!st.empty())
    {
        auto it = *(st.begin());
        int dis = it.first;
        int node = it.second;
        st.erase(it);

        for(auto it : adj[node])
        {
            int adjNode = it[0];
            int edgW = it[1];
            if(dis + edgW < dist[adjNode])
            {
                if(dist[adjNode] != 1e9)
                {
                    st.erase({dist[adjNode], adjNode});
                }
                dist[adjNode] = dis + edgW;
                st.insert({dist[adjNode], adjNode});
            }  
        }
    }
    return dist;
}