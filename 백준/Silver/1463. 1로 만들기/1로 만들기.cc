#include <bits/stdc++.h>

using namespace std;

int x;
vector<int> dp(1000001,INT_MAX);

void func(int n)
{
    if(n == x + 1)
    {
        return;
    }
    if(n + 1 <= 1000001 && dp[n + 1] > dp[n] + 1)
    {
        dp[n + 1] = dp[n] + 1;
    }
    if(n * 2 <= 1000001 && dp[n * 2] > dp[n] + 1)
    {
        dp[n * 2] = dp[n] + 1;
    }
    if(n * 3 <= 1000001 && dp[n * 3] > dp[n] + 1)
    {
        dp[n * 3] = dp[n] + 1;
    }
    func(n + 1);
}

int main()
{
    cin >> x;
    dp[1] = 0;
    func(1);
    cout << dp[x];
    return 0;
}