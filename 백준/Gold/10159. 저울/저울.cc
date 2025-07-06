#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    //freopen("test.txt", "rt", stdin);
    int n,m;
    cin >> n >> m;
    vector<vector<bool>> arr(n,vector<bool>(n,false));
    for(int i = 0; i < m; i++)
    {
        int x,y;
        cin >> x >> y;
        arr[x - 1][y - 1] = true;
    }
    for(int k = 0; k < n; k++)
    {
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(arr[i][k] && arr[k][j])
                {
                    arr[i][j] = true;
                }
            }
        }
    }
    for(int i = 0; i < n; i++)
    {
        int count = 0;
        for(int j = 0; j < n; j++)
        {
            if(!arr[i][j] && !arr[j][i])
            {
                count++;
            }
        }
        cout << count - 1 << "\n";
    }
    return 0;
}
