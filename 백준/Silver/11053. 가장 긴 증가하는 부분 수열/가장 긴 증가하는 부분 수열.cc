#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    //freopen("test.txt", "rt", stdin);
    int n;
    cin >> n;
    vector<int> arr(n + 1,0);
    vector<int> dp(n + 1,0);
    for(int i = 1; i <= n; i++)
    {
        cin >> arr[i];
    }
    int ans = 0;
    for(int i = 1; i <= n; i++)
    {
        int idx = 0;
        for(int j = 1; j <= i; j++)
        {
            if(arr[i] > arr[j])
            {
                idx = max(idx,dp[j]);
            }
        }
        dp[i] = idx + 1;
        ans = max(ans,dp[i]);
    }
    cout << ans;
    return 0;
}