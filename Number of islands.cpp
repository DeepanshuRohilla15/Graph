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

void bfs(int row, int col, vector<vector<int>> &vis, vector<vector<char>> grid)
{
    vis[row][col] = 1;
    queue<pair<int, int>> q;
    int n = grid.size();
    int m = grid[0].size();
    q.push({row, col});

    while(!q.empty())
    {
        int row = q.front().first;
        int col = q.front().second;

        for(int delrow = -1; delrow <= 1; delrow++)
        {
            for(int delcol = -1; delcol <= 1; delcol++)
            {
                if(abs(delrow) == abs(delcol)){continue;}
                int nrow = row + delrow;
                int ncol = col + delcol;
                if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m 
                   && grid[nrow][ncol] == '1' && !vis[nrow][ncol])
                   {
                        vis[nrow][ncol] = 1;
                        q.push({nrow, ncol});
                   }
            }
        }
    }
}

int numIslands(vector<vector<char>> &grid)
{
    int n = grid.size();
    int m = grid[0].size();
    int cnt = 0;
    vector<vector<int>> vis(n, vector<int>(m, 0));
    for(int row = 0; row < n; row++)
    {
        for(int col = 0; col < m; col++)
        {
            if(grid[row][col] == '1' && !vis[row][col])
            {
                cnt++;
                bfs(row, col, vis, grid);
            }
        }
    }
    return cnt;

}