#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    //freopen("test.txt", "rt", stdin);
    int n;
    cin >> n;
    vector<int> arr(n);
    vector<int> dp(n);
    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    dp[0] = arr[0];
    int ans = dp[0];
    for(int i = 1; i < n; i++)
    {
        dp[i] = max(dp[i - 1],0) + arr[i];
        ans = max(ans,dp[i]);
    }
    cout << ans;
    return 0;
}
