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

void bfs(int row, int col, int color, int iniCol, vector<vector<int>> &mat)
{
    mat[row][col] = color;
    int n = mat.size();
    int m = mat[0].size();
    queue<pair<int, int>> q;
    q.push({row, col});
    while(!q.empty())
    {
        int row = q.front().first;
        int col = q.front().second;
        q.pop(); // add on

        for(int delrow = -1; delrow <= 1; delrow++)
        {
            for(int delcol = -1; delcol <= 1; delcol++)
            {
                if(abs(delrow) == abs(delcol)){continue;}
                int nrow = row + delrow;
                int ncol = col + delcol;
                if(nrow >= 0 && nrow < n && ncol >=0 && ncol < m
                  && mat[nrow][ncol] == iniCol)
                  {
                    mat[nrow][ncol] = color;
                    q.push({nrow, ncol});
                  }
            }
        }
    }

}

vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n = image.size();
        int m = image[0].size();
        int iniCol = image[sr][sc];
        if(iniCol == color) return image; // add on
        vector<vector<int>> mat(n, vector<int> (m, 0));
        for(int i = 0; i < n; i++)  // add on
        {
            for(int j = 0; j < m; j++)
            {
                mat[i][j] = image[i][j];
            }
        }
        bfs(sr, sc, color, iniCol, mat);
        return mat;
    }