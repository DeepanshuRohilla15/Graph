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

int minimumMultiplications(vector<int>& arr, int start, int end)
{
    if(start == end) return 0;
    queue<pair<int, int>> q;
    q.push({0, start});
    vector<int> dist(100000, 1e9);
    dist[start] = 0;
    int mod = 100000;

    while(!q.empty())
    {
        int steps = q.front().first;
        int node = q.front().second;
        q.pop();

        for(auto it : arr)
        {
            int num = (it * node)%mod;
            if(steps + 1 < dist[num])
            {
                dist[num] = steps + 1;
                if(num == end) return steps + 1;
                q.push({steps + 1, num});
            }
        }
    }
    return -1;
}