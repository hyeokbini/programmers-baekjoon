#include <bits/stdc++.h>

using namespace std;

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

int n, m;

void bfs(vector<vector<char>> &arr, vector<vector<int>> &count)
{
    queue<pair<int, int>> Q;
    Q.push({0, 0});
    count[0][0] = 1;
    while (!Q.empty())
    {
        pair<int, int> cur = Q.front();
        Q.pop();
        if (arr[cur.first][cur.second] == '-')
        {
            for (int i = 0; i < 2; i++)
            {
                int nx = cur.first + dx[i];
                int ny = cur.second + dy[i];
                if (nx >= n || ny >= m || nx < 0 || ny < 0)
                {
                    continue;
                }
                if (arr[nx][ny] == '*')
                {
                    continue;
                }
                if (count[nx][ny] && count[nx][ny] <= count[cur.first][cur.second] + 1)
                {
                    continue;
                }
                count[nx][ny] = count[cur.first][cur.second] + 1;
                Q.push({nx, ny});
            }
        }
        else if (arr[cur.first][cur.second] == '|')
        {
            for (int i = 2; i < 4; i++)
            {
                int nx = cur.first + dx[i];
                int ny = cur.second + dy[i];
                if (nx >= n || ny >= m || nx < 0 || ny < 0)
                {
                    continue;
                }
                if (arr[nx][ny] == '*')
                {
                    continue;
                }
                if (count[nx][ny] && count[nx][ny] <= count[cur.first][cur.second] + 1)
                {
                    continue;
                }
                count[nx][ny] = count[cur.first][cur.second] + 1;
                Q.push({nx, ny});
            }
        }
        else if (arr[cur.first][cur.second] == '+')
        {
            for (int i = 0; i < 4; i++)
            {
                int nx = cur.first + dx[i];
                int ny = cur.second + dy[i];
                if (nx >= n || ny >= m || nx < 0 || ny < 0)
                {
                    continue;
                }
                if (arr[nx][ny] == '*')
                {
                    continue;
                }
                if (count[nx][ny] && count[nx][ny] <= count[cur.first][cur.second] + 1)
                {
                    continue;
                }
                count[nx][ny] = count[cur.first][cur.second] + 1;
                Q.push({nx, ny});
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    //freopen("test.txt", "rt", stdin);
    int t;
    cin >> t;
    while (t--)
    {
        cin >> n >> m;
        vector<vector<char>> arr(n, vector<char>(m));
        vector<vector<int>> count(n, vector<int>(m, 0));
        for (int i = 0; i < n; i++)
        {
            string tmp;
            cin >> tmp;
            for (int j = 0; j < m; j++)
            {
                arr[i][j] = tmp[j];
            }
        }
        bfs(arr, count);
        if (count[n - 1][m - 1] == 0)
        {
            cout << -1 << "\n";
        }
        else
        {
            cout << count[n - 1][m - 1] << "\n";
        }
    }
    return 0;
}