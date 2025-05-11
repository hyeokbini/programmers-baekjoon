#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    //freopen("test.txt", "rt", stdin);
    int n, m, ans = 0;
    cin >> n >> m;
    vector<vector<int>> dp(n,vector<int>(m,0));
    for(int i = 0; i < n; i++)
    {
        string tmp;
        cin >> tmp;
        for(int j = 0; j < m; j++)
        {
            dp[i][j] = tmp[j] - '0';
            if(dp[i][j])
            {
                ans = 1;
            }
        }
    }
    for(int i = 1; i < n; i++)
    {
        for(int j = 1; j < m; j++)
        {
            if(dp[i][j])
            {
                dp[i][j] = min({dp[i - 1][j - 1], dp[i - 1][j], dp[i][j - 1]}) + 1;
            }
            ans = max(ans,dp[i][j]);
        }
    }
    cout << ans * ans;
    return 0;
}
