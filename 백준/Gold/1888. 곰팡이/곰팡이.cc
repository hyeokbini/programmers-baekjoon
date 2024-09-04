#include <bits/stdc++.h>

using namespace std;

int n, m;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, -1, 0, 1};

bool check(vector<vector<int>> &arr)
{
    int checktmp = 0;
    vector<vector<bool>> visited(n, vector<bool>(m, false));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (arr[i][j] == 0 || visited[i][j])
            {
                continue;
            }
            checktmp++;
            queue<pair<int, int>> Q;
            Q.push({i, j});
            visited[i][j] = true;
            while (!Q.empty())
            {
                pair<int, int> cur = Q.front();
                Q.pop();
                for (int k = 0; k < 4; k++)
                {
                    int nx = cur.first + dx[k];
                    int ny = cur.second + dy[k];
                    if (nx < 0 || ny < 0 || nx >= n || ny >= m || visited[nx][ny] || arr[nx][ny] == 0)
                    {
                        continue;
                    }
                    visited[nx][ny] = true;
                    Q.push({nx, ny});
                }
            }
        }
    }
    return checktmp == 1;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    //freopen("test.txt", "rt", stdin);
    cin >> n >> m;
    vector<vector<int>> arr(n, vector<int>(m));
    queue<pair<int, int>> Q;
    for (int i = 0; i < n; i++)
    {
        string tmp;
        cin >> tmp;
        for (int j = 0; j < m; j++)
        {
            arr[i][j] = tmp[j] - '0';
            if (arr[i][j] != 0)
            {
                Q.push({i, j});
            }
        }
    }
    int ans = 0;
    while (1)
    {
        if (check(arr))
        {
            break;
        }
        vector<vector<int>> next_arr = arr;
        int size = Q.size();
        while (size--)
        {
            pair<int, int> cur = Q.front();
            Q.pop();
            int speed = arr[cur.first][cur.second];
            for (int i = cur.first - speed; i <= cur.first + speed; i++)
            {
                for (int j = cur.second - speed; j <= cur.second + speed; j++)
                {
                    if (i < 0 || j < 0 || i >= n || j >= m)
                    {
                        continue;
                    }
                    if (next_arr[i][j] < arr[cur.first][cur.second])
                    {
                        next_arr[i][j] = arr[cur.first][cur.second];
                        Q.push({i, j});
                    }
                }
            }
        }
        arr = next_arr;
        ans++;
    }

    cout << ans;
    return 0;
}
