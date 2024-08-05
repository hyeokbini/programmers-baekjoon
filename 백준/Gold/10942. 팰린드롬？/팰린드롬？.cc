#include <bits/stdc++.h>

using namespace std;

vector<vector<bool>> dp;
vector<int> tmparr;

/*bool func(int start, int end)
{
    while(start <= end)
    {
        if(tmparr[start] == tmparr[end])
        {
            start++;
            end--;
        }
        else
        {
            return false;
        }
    }
    return true;
}*/

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    //freopen("test.txt", "rt", stdin);
    int n;
    cin >> n;
    dp.resize(n + 1, vector<bool>(n + 1));
    tmparr.resize(n + 1);
    for (int i = 1; i < n + 1; i++)
    {
        cin >> tmparr[i];
    }

    for (int i = 1; i < n + 1; i++)
    {
        dp[i][i] = true;
        if (i < n && tmparr[i] == tmparr[i + 1])
        {
            dp[i][i + 1] = true;
        }
    }

    for (int length = 3; length <= n; length++)
    {
        for (int i = 1; i <= n - length + 1; i++)
        {
            int j = i + length - 1;
            if (tmparr[i] == tmparr[j] && dp[i + 1][j - 1])
            {
                dp[i][j] = true;
            }
        }
    }

    /*for(int i = 1; i < n + 1; i++)
    {
        for(int j = i; j < n + 1; j++)
        {
            dp[i][j] = func(i - 1,j - 1);
        }
    }*/
    int m;
    cin >> m;
    while(m--)
    {
        int x,y;
        cin >> x >> y;
        cout << (dp[x][y] ? 1 : 0) << "\n";
    }
    /*for (int i = 1; i < n + 1; i++)
    {
        for (int j = 1; j < n + 1; j++)
        {
            cout << (dp[i][j] ? 1 : 0) << " ";
        }
        cout << "\n";
    }*/
    return 0;
}