#include <bits/stdc++.h>
using namespace std;

vector<int> ans;
double maxWinRate = 0.0;

void check(vector<vector<int>> &dice, vector<int> adice, vector<int> bdice) {
    vector<int> arolls = {0};
    vector<int> brolls = {0};

    //  조합의 모든 합
    for (int i = 0; i < (int)adice.size(); ++i)
    {
        int idx = adice[i];
        vector<int> temp;
        for (int j = 0; j < (int)dice[idx].size(); ++j)
        {
            int roll = dice[idx][j];
            for (int k = 0; k < (int)arolls.size(); ++k)
            {
                temp.push_back(arolls[k] + roll);
            }
        }
        arolls = move(temp);
    }

    for (int i = 0; i < (int)bdice.size(); ++i)
    {
        int idx = bdice[i];
        vector<int> temp;
        for (int j = 0; j < (int)dice[idx].size(); ++j)
        {
            int roll = dice[idx][j];
            for (int k = 0; k < (int)brolls.size(); ++k)
            {
                temp.push_back(brolls[k] + roll);
            }
        }
        brolls = move(temp);
    }

    // 정렬 후 투포인터로 A가 이기는 경우 계산
    sort(arolls.begin(), arolls.end());
    sort(brolls.begin(), brolls.end());

    long long winCount = 0;
    int j = 0;
    for (int i = 0; i < (int)arolls.size(); ++i)
    {
        while (j < (int)brolls.size() && brolls[j] < arolls[i])
        {
            j++;
        }
        winCount += j;
    }

    long long totalCount = (long long)arolls.size() * brolls.size();
    double winRate = (double)winCount / totalCount;

    // 최고 승률이면 갱신
    if (winRate > maxWinRate)
    {
        maxWinRate = winRate;
        ans = adice;
    }
}


void choose(vector<vector<int>> &dice, vector<int> adice, vector<int> bdice, int dicecount, int start)
{
    if (adice.size() == dicecount / 2)
    {
        for (int i = 0; i < dicecount; i++)
        {
            if (std::find(adice.begin(), adice.end(), i) == adice.end())
            {
                bdice.push_back(i);
            }
        }
        check(dice, adice, bdice);
        return;
    }

    for (int i = start; i < dicecount; i++)
    {
        adice.push_back(i);
        choose(dice, adice, bdice, dicecount, i + 1);
        adice.pop_back();
    }
}


vector<int> solution(vector<vector<int>> dice) {
    vector<int> adice;
    vector<int> bdice;
    choose(dice,adice,bdice,dice.size(),0);
    for(auto &i : ans)
    {
        i++;
    }
    return ans;
}