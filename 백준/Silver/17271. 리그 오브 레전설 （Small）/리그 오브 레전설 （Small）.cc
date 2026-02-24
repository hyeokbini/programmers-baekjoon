#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    //freopen("test.txt", "rt", stdin);
    int n,m;
    cin >> n >> m;
    vector<int> dp (10200,1);
    for(int i = m; i <= n; i++)
    {
        dp[i] = (dp[i - 1] + dp[i - m]) % 1000000007;
    }
    cout << dp[n];
    return 0;
}
