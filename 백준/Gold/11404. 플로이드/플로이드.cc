#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    //freopen("test.txt", "rt", stdin);
    int n;
    cin >> n;
    vector<vector<int>> arr(n,vector<int>(n,1000000000));
    int m;
    cin >> m;
    for(int i = 0; i < m; i++)
    {
        int start,end,val;
        cin >> start >> end >> val;
        if(arr[start - 1][end - 1] > val)
        {
            arr[start - 1][end - 1] = val;
        }
    }
    for(int k = 0; k < n; k++)
    {
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(i == j)
                {
                    continue;
                }
                if(arr[i][k] + arr[k][j] < arr[i][j])
                {
                    arr[i][j] = arr[i][k] + arr[k][j];
                }
            }
        }
    }
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(arr[i][j] >= 1000000000)
            {
                cout << 0 << " ";
            }
            else
            {
                cout << arr[i][j] << " ";
            }
        }
        cout << "\n";
    }
    return 0;
}
