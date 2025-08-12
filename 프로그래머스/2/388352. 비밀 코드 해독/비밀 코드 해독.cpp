#include <bits/stdc++.h>

using namespace std;
int n;
vector<vector<int>> q;
vector<int> ans;
int answer;


void check(vector<int> comb)
{
    for(int i = 0; i < q.size(); i++)
    {
        int checkcount = 0;
        vector<bool> used(n + 1,false);
        for(int j = 0; j < 5; j++)
        {
            used[q[i][j]] = true;
        }
        for(int j = 0; j < 5; j++)
        {
            if(used[comb[j]])
            {
                checkcount++;
            }
        }
        if(checkcount != ans[i])
        {
            return;
        }
    }
    answer++;
    return;
}

void comb(vector<int> combination,int start)
{
    if(combination.size() == 5)
    {
        check(combination);
        return;
    }
    for(int i = start; i <= n; i++)
    {
        combination.push_back(i);
        comb(combination,i + 1);
        combination.pop_back();
    }
}

int solution(int n_in, vector<vector<int>> q_in, vector<int> ans_in) {
    n = n_in;
    q = q_in;
    ans = ans_in;
    vector<int> combination;
    comb(combination,1);
    return answer;
}