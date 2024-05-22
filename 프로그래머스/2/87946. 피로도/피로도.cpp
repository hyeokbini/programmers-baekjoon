#include <bits/stdc++.h>

using namespace std;

int ans = INT_MIN;

void func(int k, vector<vector<int>> list, vector<bool> visit, int count)
{
    bool check = false;
    for (int i = 0; i < list.size(); i++)
    {
        if (list[i][0] <= k && visit[i] == false)
        {
            check = false;
            visit[i] = true;
            func(k - list[i][1], list, visit, count + 1);
            visit[i] = false;
        }
    }
    if (!check)
    {
        if (count > ans)
        {
            ans = count;
        }
        return;
    }
}

int solution(int k, vector<vector<int>> dungeons)
{
    vector<bool> visited(dungeons.size(), false);
    func(k, dungeons, visited, 0);
    return ans;
}