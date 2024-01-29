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

int findCity(int n, int m, vector<vector<int>>& edges,int distanceThreshold)
{
    vector<vector<int>> dist(n, vector<int>(n, 1e9));
    for(auto it: edges)
    {
        dist[it[0]][it[1]] = it[2];
        dist[it[1]][it[0]] = it[2];
    }
    for(int i = 0; i < n; i++) dist[i][i] = 0;

    for(int k = 0; k < n; k++)
    {
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(dist[i][k] == 1e9 || dist[k][j] == 1e9) continue;
                dist[i][j] =  min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }
    int cntCity = n;
    int cityNo = -1;
    for(int city = 0; city < n; city++)
    {
        int cnt= 0;
        for(int adjCity = 0; adjCity < n; adjCity++)
        {
            if(dist[city][adjCity] <= distanceThreshold)
            {
                cnt++;
            }
        }
        if(cnt <= cntCity)
        {
            cntCity = cnt;
            cityNo = city;
        }
    }
    return cityNo;

}