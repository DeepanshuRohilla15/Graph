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

// DFS
void dfs(int row, int col, vector<vector<int>>&vis, vector<vector<int>> &grid)
{
    int n = grid.size();
    int m = grid[0].size();
    vis[row][col] = 1;

    int delrow[] = {-1, 0, 1 ,0};
    int delcol[] = {0, 1, 0, -1};
    for(int i = 0; i < 4; i++)
    {
        int nrow = row + delrow[i];
        int ncol = col + delcol[i];
        if(nrow >=0 && nrow < n && ncol >=0 && ncol < m
          && !vis[nrow][ncol] && grid[nrow][ncol] == 1)
          {
            dfs(nrow, ncol, vis, grid);
          }
    }
}

int numberOfEnclaves(vector<vector<int>> &grid)
{
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<int>> vis(n, vector<int>(m, 0));

    // first row & last row
    for(int j = 0; j < m; j++)
    {
        //first row
        if(!vis[0][j] && grid[0][j] == 1)
        {
            dfs(0, j, vis, grid);
        }
        // last row
        if(!vis[n-1][j] && grid[n-1][j] == 1)
        {
            dfs(n-1, j, vis, grid);
        }
    }
    // first col & last col
    for(int i = 0; i < n; i++)
    {
        //first col
        if(!vis[i][0] && grid[i][0] == 1)
        {
            dfs(i, 0, vis, grid);
        }
        //last col
        if(!vis[i][m-1] && grid[i][m-1] == 1)
        {
            dfs(i, m-1, vis, grid);
        }
    }

    int ans = 0;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            if(!vis[i][j] && grid[i][j] == 1)
            {
                ans++;
            }
        }
    }
    return ans;
}

 // BFS

class Solution {
  public:
    int numberOfEnclaves(vector<vector<int>> &grid) {
        // Code here
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));
        queue<pair<int, int>> q;
        
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                if(i == 0 || i == n-1 || j == 0 || j == m-1)
                {
                    if(grid[i][j] == 1)
                    {
                        q.push({i, j});
                        vis[i][j] = 1;
                    }
                }
            }
        }
        
        int delrow[] = {-1, 0, 1, 0};
        int delcol[] = {0, 1, 0, -1};
        
        while(!q.empty())
        {
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
            vis[row][col] = 1;
            for(int i = 0; i < 4; i++)
            {
                int nrow = row + delrow[i];
                int ncol = col + delcol[i];
                if(nrow >=0 && nrow < n && ncol >=0 && ncol < m
                  && !vis[nrow][ncol] && grid[nrow][ncol] == 1)
                  {
                      q.push({nrow, ncol});
                      vis[nrow][ncol] = 1;
                  }
            }
        }
        
        int ans = 0;
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                if(!vis[i][j] && grid[i][j] == 1)
                {
                    ans++;
                }
            }
        }
        return ans;
    }
};