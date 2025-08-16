#include <bits/stdc++.h>

using namespace std;

int solution(int alp, int cop, vector<vector<int>> problems) {
    int maxalgo = 0;
    int maxcod = 0;
    for(int i = 0; i < problems.size(); i++)
    {
        maxalgo = max(maxalgo, problems[i][0]);
        maxcod = max(maxcod, problems[i][1]);
    }

    alp = min(alp, maxalgo);
    cop = min(cop, maxcod);

    vector<vector<int>> dp(maxalgo + 1, vector<int>(maxcod + 1, 1000000000));
    dp[alp][cop] = 0;

    for(int i = alp; i <= maxalgo; i++)
    {
        for(int j = cop; j <= maxcod; j++)
        {
            if(dp[i][j] == 1000000000)
            {
                continue;
            }

            // 공부해서 능력치 올리기
            if(i + 1 <= maxalgo)
            {
                dp[i + 1][j] = min(dp[i + 1][j], dp[i][j] + 1);
            }
            if(j + 1 <= maxcod)
            {
                dp[i][j + 1] = min(dp[i][j + 1], dp[i][j] + 1);
            }

            // 각 문제 풀기
            for(int k = 0; k < problems.size(); k++)
            {
                if(i >= problems[k][0] && j >= problems[k][1])
                {
                    int ni = min(maxalgo, i + problems[k][2]);
                    int nj = min(maxcod, j + problems[k][3]);
                    dp[ni][nj] = min(dp[ni][nj], dp[i][j] + problems[k][4]);
                }
            }
        }
    }

    return dp[maxalgo][maxcod];
}
