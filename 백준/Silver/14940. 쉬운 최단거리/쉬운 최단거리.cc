#include <bits/stdc++.h>

using namespace std;

int n, m;
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
vector<vector<int>> arr;
vector<vector<bool>> visited;
queue<pair<int, int>> Q;

void bfs()
{
    while (!Q.empty())
    {
        pair<int, int> cur = Q.front();
        Q.pop();
        for (int i = 0; i < 4; i++)
        {
            int nx = cur.first + dx[i];
            int ny = cur.second + dy[i];
            if (nx >= n || ny >= m || nx < 0 || ny < 0 || visited[nx][ny] || !arr[nx][ny])
            {
                continue;
            }
            arr[nx][ny] = arr[cur.first][cur.second] + 1;
            visited[nx][ny] = true;
            Q.push({nx, ny});
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    //freopen("test.txt", "rt", stdin);
    cin >> n >> m;
    arr.resize(n, vector<int>(m));
    visited.resize(n, vector<bool>(m));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> arr[i][j];
            if (arr[i][j] == 2)
            {
                Q.push({i, j});
                arr[i][j] = 0;
                visited[i][j] = true;
            }
        }
    }
    bfs();
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (arr[i][j] == 1 && !visited[i][j])
            {
                cout << -1 << " ";
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