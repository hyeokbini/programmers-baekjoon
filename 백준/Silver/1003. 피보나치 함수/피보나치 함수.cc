#include <bits/stdc++.h>

using namespace std;

int dp[41];

int func(int n)
{
    if (n == 1)
    {
        return dp[1] = 1;
    }
    if (n == 2)
    {
        return dp[2] = 1;
    }
    if (dp[n])
    {
        return dp[n];
    }
    return dp[n] = func(n - 1) + func(n - 2);
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, val;
    cin >> n;
    while (n--)
    {
        cin >> val;
        if (val == 0)
        {
            cout << 1 << " " << 0 << "\n";
            continue;
        }
        else if (val == 1)
        {
            cout << 00 << " " << 1 << "\n";
            continue;
        }
        else
        {
            cout << func(val - 1) << " " << func(val) << "\n";
        }
    }
    return 0;
}
