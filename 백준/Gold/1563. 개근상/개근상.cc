#include <bits/stdc++.h>
using namespace std;

int m = 1000000;
int dp[1001][2][3];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    //freopen("test.txt", "rt", stdin);
    int n;
    cin >> n;
    dp[1][0][0] = 1; // O
    dp[1][1][0] = 1; // L
    dp[1][0][1] = 1; // A

    for (int i = 2; i <= n; ++i)
    {
        // 전날 L별 총합
        int latezero = (dp[i - 1][0][0] + dp[i - 1][0][1] + dp[i - 1][0][2]) % m;
        int lateone = (dp[i - 1][1][0] + dp[i - 1][1][1] + dp[i - 1][1][2]) % m;

        // 1) 오늘 O
        dp[i][0][0] = latezero;
        dp[i][1][0] = (dp[i][1][0] + lateone) % m;
        dp[i][1][0] = (dp[i][1][0] + latezero) % m;

        // 2) 오늘 A, 최대2
        dp[i][0][1] = dp[i - 1][0][0] % m;
        dp[i][1][1] = dp[i - 1][1][0] % m;
        dp[i][0][2] = dp[i - 1][0][1] % m;
        dp[i][1][2] = dp[i - 1][1][1] % m;
    }

    int ans = 0;
    for (int l = 0; l <= 1; ++l)
    {
        for (int a = 0; a <= 2; ++a)
        {
            ans = (ans + dp[n][l][a]) % m;
        }
    }

    cout << ans;
    return 0;
}
