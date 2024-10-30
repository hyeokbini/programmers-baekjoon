#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    //freopen("test.txt", "rt", stdin);
    int n;
    cin >> n;
    vector<int> T(n + 2);
    vector<int> P(n + 2);
    vector<int> dp(n + 2,0);
    for(int i = 1; i <= n; i++)
    {
        cin >> T[i] >> P[i];
    }
    int tmpval = 0;
    for(int i = 1; i <= n + 1; i++)
    {
        tmpval = max(tmpval,dp[i]);
        if(T[i] + i > n + 1)
        {
            continue;
        }
        dp[i + T[i]] = max(dp[i + T[i]], tmpval + P[i]);
    }
    cout << tmpval;
    return 0;
    
}
