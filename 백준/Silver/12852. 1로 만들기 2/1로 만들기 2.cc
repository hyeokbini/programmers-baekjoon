#include <bits/stdc++.h>

using namespace std;

int x;
vector<int> dp(1000001,INT_MAX);
vector<int> tracedp(1000001);

void func(int n)
{
    if(n == x + 1)
    {
        return;
    }
    if(n + 1 <= 1000001 && dp[n + 1] > dp[n] + 1)
    {
        dp[n + 1] = dp[n] + 1;
        tracedp[n + 1] = n;
    }
    if(n * 2 <= 1000001 && dp[n * 2] > dp[n] + 1)
    {
        dp[n * 2] = dp[n] + 1;
        tracedp[n * 2] = n;
    }
    if(n * 3 <= 1000001 && dp[n * 3] > dp[n] + 1)
    {
        dp[n * 3] = dp[n] + 1;
        tracedp[n * 3] = n;
    }
    func(n + 1);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    //freopen("test.txt", "rt", stdin);
    cin >> x;
    dp[1] = 0;
    func(1);
    cout << dp[x] << "\n";
    cout << x << " ";
    while(x != 1)
    {
        cout << tracedp[x] << " ";
        x = tracedp[x];
    }
    return 0;
}