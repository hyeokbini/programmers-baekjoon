#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> dp;
vector<vector<int>> arr;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    //freopen("test.txt", "rt", stdin);
    int n,m;
    cin >> n >> m;
    dp.resize(n + 1,vector<int>(n + 1));
    arr.resize(n + 1,vector<int>(n + 1));
    for(int i = 1; i < n + 1; i++)
    {
        for(int j = 1; j < n + 1; j++)
        {
            cin >> arr[i][j];
            if(j == 1)
            {
                dp[i][j] = arr[i][j];
            }
        }
    }
    for(int i = 1; i < n + 1; i++)
    {
        for(int j = 2; j < n + 1; j++)
        {
            dp[i][j] = arr[i][j] + dp[i][j - 1];
        }
    }
    while(m--)
    {
        int startx,starty,endx,endy,ans = 0;
        cin >> startx >> starty >> endx >> endy;
        for(int i = startx; i <= endx; i++)
        {
            ans += dp[i][endy] - dp[i][starty - 1];
        }
        cout << ans << "\n";
    }
    return 0;
}
