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

void dfs(int row, int col, vector<vector<int>> &vis,vector<vector<int>>& grid,
         vector<pair<int, int>> &vec, int row0, int col0)
         {
            int n = grid.size();
            int m = grid[0].size();
            vis[row][col] = 1;
            vec.push_back({row - row0, col - col0});

            int delrow[] = {-1,0, 1, 0};
            int delcol[] = {0, 1, 0, -1};
            for(int i = 0; i < 4; i++)
            {
                int nrow = row + delrow[i];
                int ncol = col + delcol[i];
                if(nrow >=0 && nrow < n && ncol >= 0 && ncol < m
                   && !vis[nrow][ncol] && grid[nrow][ncol] == 1)
                   {
                        dfs(nrow, ncol, vis, grid, vec, row0, col0);
                   }
            }
         }

int countDistinctIslands(vector<vector<int>>& grid)
{
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<int>> vis(n, vector<int>(m, 0));
    set<vector<pair<int, int>>> st;

    for(int i = 0 ; i <n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            if(!vis[i][j] && grid[i][j] == 1)
            {
                vector<pair<int , int>> vec;
                dfs(i, j, vis, grid, vec, i, j);
                st.insert(vec);
            }
        }
    }
    return st.size();
}