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

void dfs(int row, int col, vector<vector<int>> &vis, vector<vector<char>>& mat)
{
    int n = mat.size();
    int m = mat[0].size();
    vis[row][col] = 1;

    int delrow[] = {-1, 0, 1, 0};
    int delcol[] = {0, 1, 0, -1};

    for(int i = 0; i < 4; i++)
    {
        int nrow = row + delrow[i];
        int ncol = col + delcol[i];
        if(nrow >=0 && nrow < n && ncol >=0 && ncol < m
           && !vis[nrow][ncol] && mat[nrow][ncol] == 'O')
           {
            dfs(nrow, ncol, vis, mat);
           }
    }
}

vector<vector<char>> fill(int n, int m, vector<vector<char>> mat)
{
    vector<vector<int>> vis(n, vector<int>(m, 0));

    // first row & last row
    for(int j = 0; j < m; j++)
    {
        // first row
        if(!vis[0][j] && mat[0][j] == 'O')
        {
            dfs(0, j, vis, mat);
        }
        // last row
        if(!vis[n-1][j] && mat[n-1][j] == 'O')
        {
            dfs(n-1, j, vis, mat);
        }
    }

    // first col & last col
    for(int i = 0; i < n; i++)
    {
        // first col
        if(!vis[i][0] && mat[i][0] == 'O')
        {
            dfs(i, 0, vis, mat);
        }
        // last col
        if(!vis[i][m-1] && mat[i][m-1] == 'O')
        {
            dfs(i, m-1, vis, mat);
        }
    }

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            if(!vis[i][j] && mat[i][j] == 'O')
            {
                mat[i][j] = 'X';
            }
        }
    }
    return mat;
}