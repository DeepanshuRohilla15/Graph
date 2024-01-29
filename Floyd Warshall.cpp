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

void shortest_distance(vector<vector<int>>&matrix)
{
    int n = matrix.size();
    int m = matrix[0].size();
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j <m; j++)
        {
            if(matrix[i][j] == -1)
            {
                matrix[i][j] = 1e9;
            }
            if(i == j)
            {
                matrix[i][j] = 0;
            }
        }
    }

    for(int k = 0; k < n; k++)
    {
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                matrix[i][j] = min(matrix[i][j], matrix[i][k] + matrix[k][j]);
            }
        }
    }

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            if(matrix[i][j] == 1e9)
            {
                matrix[i][j] = -1;
            }
        }
    }
}