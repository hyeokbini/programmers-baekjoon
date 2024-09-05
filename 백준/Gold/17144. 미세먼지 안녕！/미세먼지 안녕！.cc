#include <bits/stdc++.h>

using namespace std;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, -1, 0, 1};
int n, m, t;
vector<vector<int>> arr;
vector<int> cleaneridx;

void spread()
{
    vector<vector<int>> tmparr = arr;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (arr[i][j] == 0)
            {
                continue;
            }
            int curidxdust = arr[i][j];
            int spreaddustamount = curidxdust / 5;
            int spreaddir = 0;
            for (int t = 0; t < 4; t++)
            {
                int nx = dx[t] + i;
                int ny = dy[t] + j;
                if (nx >= n || ny >= m || nx < 0 || ny < 0)
                {
                    continue;
                }
                if (arr[nx][ny] == -1)
                {
                    continue;
                }
                tmparr[nx][ny] += spreaddustamount;
                spreaddir++;
            }
            tmparr[i][j] -= spreaddustamount * spreaddir;
        }
    }
    arr = tmparr;
    return;
}

void clean() // cleaneridx[0]은 위쪽 기준점, cleaneridx[1]은 아래쪽 기준점
{
    vector<vector<int>> tmparr = arr;
    for (int i = 1; i < m - 1; i++)
    {
        tmparr[cleaneridx[0]][i + 1] = arr[cleaneridx[0]][i];
    }
    tmparr[cleaneridx[0]][1] = 0;
    for (int i = cleaneridx[0]; i > 0; i--)
    {
        tmparr[i - 1][m - 1] = arr[i][m - 1];
    }
    for (int i = m - 1; i > 0; i--)
    {
        tmparr[0][i - 1] = arr[0][i];
    }
    for (int i = 0; i < cleaneridx[0] - 1; i++)
    {
        tmparr[i + 1][0] = arr[i][0];
    }

    for (int i = 1; i < m - 1; i++)
    {
        tmparr[cleaneridx[1]][i + 1] = arr[cleaneridx[1]][i];
    }
    tmparr[cleaneridx[1]][1] = 0;
    for (int i = cleaneridx[1]; i < n - 1; i++)
    {
        tmparr[i + 1][m - 1] = arr[i][m - 1];
    }
    for (int i = m - 1; i > 0; i--)
    {
        tmparr[n - 1][i - 1] = arr[n - 1][i];
    }
    for (int i = n - 1; i > cleaneridx[1] + 1; i--)
    {
        tmparr[i - 1][0] = arr[i][0];
    }
    arr = tmparr;
    return;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    //freopen("test.txt", "rt", stdin);
    cin >> n >> m >> t;
    arr.resize(n, vector<int>(m));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> arr[i][j];
            if (arr[i][j] == -1)
            {
                cleaneridx.push_back(i);
            }
        }
    }
    while (t--)
    {
        spread();
        clean();
    }
    int ans = 0;
    for (auto i : arr)
    {
        for (auto j : i)
        {
            ans += j;
        }
    }
    cout << ans + 2;
    return 0;
}
