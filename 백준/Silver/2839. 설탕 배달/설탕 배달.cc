#include <bits/stdc++.h>

using namespace std;

int n;
int ans = 0;
int dp[5001];

void func(int level)
{
    if(n == level - 1)
    {
        ans = dp[level - 1];
        return;
    }
    if(dp[level - 3] != 0 && dp[level - 5] == 0)
    {
        dp[level] = dp[level - 3] + 1;
    }
    else if(dp[level - 3] == 0 && dp[level - 5] != 0)
    {
        dp[level] = dp[level - 5] + 1;
    }
    else if(dp[level - 3] != 0 && dp[level - 5] != 0)
    {
        dp[level] = min(dp[level - 3],dp[level - 5]) + 1;
    }
    func(level + 1);
}

int main()
{
    cin >> n;
    dp[3] = 1;
    dp[5] = 1;
    func(0);
    if(ans == 0)
    {
        cout << -1;
    }
    else
    {
        cout << ans;
    }
}
