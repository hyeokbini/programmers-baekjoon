#include <bits/stdc++.h>

using namespace std;

int n;
vector<vector<int>> originval;
vector<vector<int>> dp;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    //freopen("test.txt", "rt", stdin);
    cin >> n;
    originval.resize(n, vector<int>(3));
    dp.resize(n, vector<int>(3, INT_MAX));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cin >> originval[i][j];
        }
    }
    for(int i = 0; i < 3; i++)
    {
        dp[0][i] = originval[0][i]; // 초기값 입력
    }
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < 3; j++) // n-1번째 인덱스
        {
            for (int k = 0; k < 3; k++) // n번째 인덱스
            {
                if (j == k)
                {
                    continue;
                }
                dp[i + 1][k] = min(dp[i + 1][k], dp[i][j] + originval[i + 1][k]);
            }
        }
    }
    cout << min(min(dp[n - 1][0], dp[n - 1][1]), dp[n - 1][2]);
    return 0;
}
