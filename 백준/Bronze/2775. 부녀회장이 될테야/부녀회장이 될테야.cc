#include <bits/stdc++.h>

using namespace std;

int arr[15][15];

int main()
{
    //freopen("test.txt", "rt", stdin);
    int t;
    cin >> t;
    for(int i = 0; i < 15; i++)
    {
        arr[0][i] = i;
    }
    while(t--)
    {
        int n,k;
        cin >> n >> k;
        if(arr[n][k] != 0)
        {
            cout << arr[n][k] << "\n";
            continue;
        }
        for(int i = 1; i <= n; i++)
        {
            for(int j = 1; j <= k; j++)
            {
                if(arr[i][j] == 0)
                {
                    arr[i][j] = arr[i - 1][j] + arr[i][j - 1];
                }
            }
        }
        cout << arr[n][k] << "\n";
    }
    return 0;
}