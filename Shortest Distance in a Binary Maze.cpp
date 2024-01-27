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

int shortestPath(vector<vector<int>> &grid, pair<int, int> source, pair<int, int> destination)
{
    // Carefully  base case 
    if(source.first == destination.first && source.second == destination.second)
    {
        return 0;
    }

    queue<pair<int, pair<int, int>>> q; // dis, {row, col}
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<int>> dist(n, vector<int>(m, 1e9));
    dist[source.first][source.second] = 0;
    q.push({0, {source.first, source.second}});

    int delrow[] = {-1, 0, 1, 0};
    int delcol[] = {0, 1, 0, -1};

    while(!q.empty())
    {
        auto it = q.front();
        q.pop();
        int dis = it.first;
        int row = it.second.first;
        int col = it.second.second;
        
        for(int i = 0; i < 4; i++)
        {
            int nrow = row + delrow[i];
            int ncol = col + delcol[i];

            if(nrow >=0 && nrow < n && ncol >=0 && ncol < m
              && grid[nrow][ncol] == 1 && dis + 1 < dist[nrow][ncol])
              {
                    dist[nrow][ncol] = dis + 1;
                    if(nrow == destination.first && ncol == destination.second)
                    {
                        return dis + 1;
                    }
                    q.push({dis + 1, {nrow, ncol}});
              }
        }
    }
    return -1;

}