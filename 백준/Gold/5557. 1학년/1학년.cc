#include <bits/stdc++.h>

using namespace std;

int n;
vector<int> arr;
vector<vector<long long>> dp;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    //freopen("test.txt", "rt", stdin);
    cin >> n;
    arr.resize(n);
    dp.resize(21, vector<long long>(n, 0));
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    dp[arr[0]][0] = 1;

    for (int i = 0; i < n - 2; i++)
    {
        for (int j = 0; j < 21; j++)
        {
            if (j + arr[i + 1] <= 20)
            {
                dp[j + arr[i + 1]][i + 1] += dp[j][i];
            }
            if (j - arr[i + 1] >= 0)
            {
                dp[j - arr[i + 1]][i + 1] += dp[j][i];
            }
        }
    }
    cout << dp[arr[n - 1]][n - 2];
    return 0;
}