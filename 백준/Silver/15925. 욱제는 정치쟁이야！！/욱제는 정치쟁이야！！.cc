#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    //freopen("test.txt", "rt", stdin);
    int n, k;
    cin >> n >> k;
    vector<vector<int>> arr(n, vector<int>(n));

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> arr[i][j];

    for (int rep = 0; rep < 2; rep++)
    {
        for (int i = 0; i < n; i++)
        {
            // 행 처리
            int cnt = 0;
            for (int j = 0; j < n; j++)
                if (arr[i][j] == k)
                    cnt++;
            if (cnt > n / 2)
                for (int j = 0; j < n; j++)
                    arr[i][j] = k;

            // 열 처리
            cnt = 0;
            for (int j = 0; j < n; j++)
                if (arr[j][i] == k)
                    cnt++;
            if (cnt > n / 2)
                for (int j = 0; j < n; j++)
                    arr[j][i] = k;
        }
    }
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (arr[i][j] != k)
            {
                cout << 0;
                return 0;
            }

    cout << 1;
    return 0;
}
