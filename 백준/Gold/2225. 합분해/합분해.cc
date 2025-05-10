#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    //freopen("test.txt", "rt", stdin);
    int n,k;
    cin >> n >> k;
    vector<vector<long long int>> dp(n + 1, vector<long long int>(k,1));
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j < k; j++)
        {
            dp[i][j] = (dp[i - 1][j] + dp[i][j - 1]) % 1000000000;
        }
    }
    cout << dp[n][k - 1] % 1000000000;
    return 0;
}

