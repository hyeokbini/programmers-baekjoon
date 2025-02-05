#include <bits/stdc++.h>

using namespace std;

int anscount = 0;

void change(vector<vector<int>> &arr, int startx, int starty)
{
    for(int i = startx; i < startx + 3; i++)
    {
        for(int j = starty; j < starty + 3; j++)
        {
            if(arr[i][j] == 0)
            {
                arr[i][j] = 1;
            }
            else
            {
                arr[i][j] = 0;
            }
        }
    }
    anscount++;
    return;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    //freopen("test.txt", "rt", stdin);
    int n,m;
    cin >> n >> m;
    vector<vector<int>> arr(n,vector<int>(m));
    vector<vector<int>> ans(n,vector<int>(m));
    for(int i = 0; i < n; i++)
    {
        string tmp;
        cin >> tmp;
        for(int j = 0; j < m; j++)
        {
            arr[i][j] = tmp[j] - '0';
        }
    }
    for(int i = 0; i < n; i++)
    {
        string tmp;
        cin >> tmp;
        for(int j = 0; j < m; j++)
        {
            ans[i][j] = tmp[j] - '0';
        }
    }
    if(n < 3 || m < 3)
    {
        if(arr != ans)
        {
            cout << -1;
        }
    else
        {
            cout << anscount;
        }
        return 0;
    }
    for(int i = 0; i <= n - 3; i++)
    {
        for(int j = 0; j <= m - 3; j++)
        {
            if(arr[i][j] != ans[i][j])
            {
                change(arr,i,j);
            }
        }
    }
    if(arr != ans)
    {
        cout << -1;
    }
    else
    {
        cout << anscount;
    }
}
