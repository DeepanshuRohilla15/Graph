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

int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int mini = 0;
        int vis[n][m]; // add on
        queue<pair <pair<int, int>, int>> q;
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                if(grid[i][j] == 2)
                {
                    q.push({{i, j}, 0});
                    vis[i][j] = 2;  // add on
                }
                else
                {
                    vis[i][j] = 1;   // add on
                }
            }
        }
        
        while(!q.empty())
        {
            int row = q.front().first.first;
            int col = q.front().first.second;
            int ti = q.front().second;
           //  vis[row][col] = 2;   remove
            q.pop();
            // mini = ti; remove
            mini = max(mini, ti);

            for(int delrow = -1; delrow <=1; delrow++)
            {
                for(int delcol = -1; delcol <= 1; delcol++)
                {
                    if(abs(delrow) == abs(delcol)){continue;}
                    int nrow = row + delrow;
                    int ncol = col + delcol;

                    if(nrow >=0 && nrow < n && ncol >=0 && ncol < m
                       && grid[nrow][ncol] == 1 && vis[nrow][ncol] != 2)
                       {
                            q.push({{nrow, ncol}, ti+1});
                            vis[nrow][ncol] = 2; // add on
                       }
                }
            }
        }  
        // check 
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                if(vis[i][j] != 2 && grid[i][j] == 1)
                {
                    return -1;
                }
            }
        }
        return mini; 
    }