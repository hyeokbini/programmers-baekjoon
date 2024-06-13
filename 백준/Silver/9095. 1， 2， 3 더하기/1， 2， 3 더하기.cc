#include <bits/stdc++.h>

using namespace std;

int dp[11];

int func(int n)
{
    if (n == 1)
    {
        return dp[1] = 1;
    }
    if (n == 2)
    {
        return dp[2] = 2;
    }
    if (n == 3)
    {
        return dp[3] = 4;
    }
    if (dp[n])
    {
        return dp[n];
    }
    return dp[n] = func(n - 1) + func(n - 2) + func(n - 3);
}

int main()
{
    // freopen("test.txt", "rt", stdin);
    int t, n;
    cin >> t;
    while (t--)
    {
        cin >> n;
        cout << func(n) << "\n";
    }
    return 0;
}