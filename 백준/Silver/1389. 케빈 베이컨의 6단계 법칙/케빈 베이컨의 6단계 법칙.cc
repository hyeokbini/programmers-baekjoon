#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> arr;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    //freopen("test.txt", "rt", stdin);
    int n,m,tmp1,tmp2;
    cin >> n >> m;
    arr.resize(n,vector<int>(n,99999));
    while(m--)
    {
        cin >> tmp1 >> tmp2;
        arr[tmp1 - 1][tmp2 - 1] = 1;
        arr[tmp2 - 1][tmp1 - 1] = 1;
    }
    for(int i = 0; i < n; i++)
    {
        arr[i][i] = 0;
    }
    for(int k = 0; k < n; k++)
    {
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                
                if(arr[i][k] + arr[k][j] + 1 < arr[i][j])
                {
                    arr[i][j] = arr[i][k] + arr[k][j] + 1;
                }
            }
        }
    }
    vector<int> ans(n + 1,0);
    int minval = INT_MAX;
    int minidx = 0;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            ans[i] += arr[i][j];
        }
        if(ans[i] < minval)
        {
            minval = ans[i];
            minidx = i;
        }
    }
    cout << minidx + 1;
    return 0;
    }