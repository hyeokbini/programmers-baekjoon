#include <bits/stdc++.h>

using namespace std;

int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
int maze[101][101];
bool visited[101][101];
int n, m;

void bfs(int startx, int starty)
{
    queue<pair<int, int>> Q;
    Q.push({startx, starty});
    visited[startx][starty] = true;
    maze[startx][starty] = 1;
    while (!Q.empty())
    {
        pair<int, int> cur = Q.front();
        Q.pop();
        for (int i = 0; i < 4; i++)
        {
            int nx = cur.first + dx[i];
            int ny = cur.second + dy[i];
            if (nx >= n || ny >= m || nx < 0 || ny < 0 || visited[nx][ny])
            {
                continue;
            }
            if (maze[nx][ny] == 0)
            {
                continue;
            }
            visited[nx][ny] = true;
            maze[nx][ny] = min(maze[cur.first][cur.second] + 1,maze[nx][ny]);
            Q.push({nx, ny});
        }
    }
    return;
}

int main()
{
    //freopen("test.txt", "rt", stdin);
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        string tmp;
        cin >> tmp;
        for (int j = 0; j < m; j++)
        {
            if(tmp[j] - '0' == 0)
            {
                maze[i][j] = tmp[j] - '0';
            }
            else
            {
                maze[i][j] = INT_MAX;
            }
        }
    }
    bfs(0, 0);
    cout << maze[n - 1][m - 1];
    return 0;
}