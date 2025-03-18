#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    //freopen("test.txt", "rt", stdin);
    int n, m;
    cin >> n >> m;
    int stand = min(n,m) - 1;
    int ans = 1;
    if(stand == 0)
    {
        cout << 1;
        return 0;
    }
    vector<vector<int>> arr(n, vector<int> (m));
    for(int i = 0; i < n; i++)
    {
        string tmp;
        cin >> tmp;
        for(int j = 0; j < m; j++)
        {

            arr[i][j] = tmp[j] - '0';
        }
    }
    for(int i = 1; i <= stand; i++)
    {
        for(int j = 0; j < n - i; j++)
        {
            for(int k = 0; k < m - i; k++)
            {
                int val = arr[j][k];
                if(val == arr[j + i][k] && val == arr[j][k + i]
                && val == arr[j + i][k + i])
                {
                    ans = max(ans,(int)pow(i + 1,2));
                }
            }
        }
    }
    cout << ans;
    return 0;
}
