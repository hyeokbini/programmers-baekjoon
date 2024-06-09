#include <bits/stdc++.h>

using namespace std;

int func(vector<int> &arr, int dest)
{
    vector<int> dp(dest + 1, 0);
    dp[0] = 1;

    for (int i = 0; i < arr.size(); i++)
    {
        for (int j = arr[i]; j <= dest; j++)
        {
            dp[j] += dp[j - arr[i]];
        }
    }

    return dp[dest];
}

int main()
{
    //freopen("test.txt", "rt", stdin);
    int t;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        int n, val;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        cin >> val;
        cout << func(arr, val) << "\n";
    }
    return 0;
}