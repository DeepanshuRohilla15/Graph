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

int wordLadderLength(string startWord, string targetWord, vector<string>& wordList)
{
    queue<pair<string, int>> q;
    set<string> st(wordList.begin(), wordList.end());
    q.push({startWord, 1});
    st.erase(startWord);

    while(!q.empty())
    {
        string word = q.front().first;
        int steps = q.front().second;
        q.pop();
        if(word == targetWord) return steps;

        for(int i = 0; i < word.size(); i++)
        {
            char original = word[i];
            for(char ch = 'a'; ch <= 'z'; ch++)
            {
                word[i] = ch;
                if(st.find(word) != st.end())
                {
                    st.erase(word);
                    q.push({word, steps+1});
                }
            }
            word[i] = original;
        }
    }
    return 0;
}