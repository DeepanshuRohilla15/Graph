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

vector<vector<string>> findSequences(string beginWord, string endWord, vector<string>& wordList)
{
    set<string> st(wordList.begin(), wordList.end());
    queue<vector<string>> q;
    q.push({beginWord});
    vector<string> usedOnLevel;
    usedOnLevel.push_back(beginWord);
    int level = 0;
    vector<vector<string>> ans;

    while(!q.empty())
    {
        vector<string> vec = q.front();
        q.pop();

        // erase all the words that have been previously used
        if(vec.size() > level)
        {
            level++;
            for(auto it : usedOnLevel)
            {
                st.erase(it);
            }
            usedOnLevel.clear();
        }

        string word = vec.back();
        // store answer
        if(word == endWord)
        {
            // first sequnce
            if(ans.size() == 0)
            {
                ans.push_back(vec);
            }
            else if(ans[0].size() == vec.size())
            {
                ans.push_back(vec);
            }
        }

        for(int i = 0; i < word.size(); i++)
        {
            char original = word[i];
            for(char c = 'a'; c <= 'z'; c++)
            {
                word[i] = c;
                if(st.count(word) > 0)
                {
                    vec.push_back(word);
                    q.push(vec);
                    usedOnLevel.push_back(word);
                    vec.pop_back();
                }
            }
            word[i] = original;
        }
    }
    return ans;

}