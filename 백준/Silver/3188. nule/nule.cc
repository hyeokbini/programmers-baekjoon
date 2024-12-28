#include <bits/stdc++.h>
#define maxval 5000000

using namespace std;

vector<vector<pair<int,int>>> arr;

void calc(int i, int j, int num)
{
    if(num == 0)
    {
        return;
    }

    int tcount = 0;
    int fcount = 0;
    while(num % 5 == 0)
    {
        fcount++;
        num /= 5;
    }
    while(num % 2 == 0)
    {
        tcount++;
        num /= 2;
    }
    arr[i][j].first = tcount;
    arr[i][j].second = fcount;
    return;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    //freopen("test.txt", "rt", stdin);
    int n;
    cin >> n;
    arr.resize(n,vector<pair<int,int>>(n,{maxval,maxval}));

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            int num;
            cin >> num;
            calc(i,j,num);
        }
    }

    vector<vector<pair<int, int>>> dp(n, vector<pair<int, int>>(n, {maxval, maxval}));
    dp[0][0] = arr[0][0];

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(arr[i][j].first == maxval && arr[i][j].second == maxval)
            {
                continue;
            }

            if(i > 0)
            {
                dp[i][j].first = min(dp[i][j].first, dp[i-1][j].first + arr[i][j].first);
                dp[i][j].second = min(dp[i][j].second, dp[i-1][j].second + arr[i][j].second);
            }
            if(j > 0)
            {
                dp[i][j].first = min(dp[i][j].first, dp[i][j-1].first + arr[i][j].first);
                dp[i][j].second = min(dp[i][j].second, dp[i][j-1].second + arr[i][j].second);
            }
        }
    }

    int result = min(dp[n-1][n-1].first, dp[n-1][n-1].second);
    cout << result << "\n";

    return 0;
}
