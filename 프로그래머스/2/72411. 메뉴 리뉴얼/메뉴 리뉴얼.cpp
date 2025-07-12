#include <bits/stdc++.h>

using namespace std;

unordered_map<string,int> menulist;

void func(string curorder, int len, string comborder, int curidx)
{
    if(len == comborder.length())
    {
        menulist[comborder]++;
        return;
    }
    for(int i = curidx; i < curorder.length(); i++)
    {
        func(curorder, len, comborder + curorder[i], i + 1);
    }
}

vector<string> solution(vector<string> orders, vector<int> course) {
    vector<string> answer;
    for(int j = 0; j < course.size(); j++)
    {
        for(int i = 0; i < orders.size(); i++)
        {
            sort(orders[i].begin(), orders[i].end());
            func(orders[i],course[j],"",0);
        }
        int count = 0;
        for(auto iter = menulist.begin(); iter != menulist.end(); iter++)
        {
            count = max(iter->second,count);
        }
        for(auto iter = menulist.begin(); iter != menulist.end(); iter++)
        {
            if(count < 2)
            {
                break;
            }
            if(iter->second == count)
            {
                answer.push_back(iter->first);
            }
        }
        menulist = {};
    }
    sort(answer.begin(), answer.end());
    return answer;
}