#include <bits/stdc++.h>
using namespace std;

vector<long long int> dp;

long long int fibo(int n)
{
    if(dp[n])
    {
        return dp[n];
    }
    if(n == 0)
    {
        return dp[0] = 0;
    }
    if(n == 1)
    {
        return dp[1] = 1;
    }
    return dp[n] = fibo(n - 1) + fibo(n - 2);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    //freopen("test.txt", "rt", stdin);
    int n;
    cin >> n;
    dp.resize(n + 1,0);
    cout << fibo(n);
    return 0;
}
