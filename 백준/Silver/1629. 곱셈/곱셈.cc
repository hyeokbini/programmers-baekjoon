#include <bits/stdc++.h>

using namespace std;

long long int a, b, c;
unordered_map<int, long long int> dp;

long long int func(int val)
{
    if (dp.find(val) != dp.end())
    {
        return dp[val];
    }

    if (val == 1)
    {
        return dp[val] = a % c;
    }

    long long int tmpval = func(val / 2);
    long long int result;

    if (val % 2 == 0)
    {
        result = tmpval * tmpval % c;
    }
    else
    {
        result = tmpval * tmpval % c * a % c;
    }

    return dp[val] = result;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    //freopen("test.txt", "rt", stdin);
    
    cin >> a >> b >> c;

    cout << func(b) << endl;

    return 0;
}
