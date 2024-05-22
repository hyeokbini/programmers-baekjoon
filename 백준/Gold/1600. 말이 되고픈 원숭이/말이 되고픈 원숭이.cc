#include <bits/stdc++.h>

using namespace std;

int kdx[8] = {1, 2, 2, 1, -1, -2, -2, -1};
int kdy[8] = {2, 1, -1, -2, -2, -1, 1, 2};
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

struct State
{
    int x, y, k, dist;
};

int main()
{
    int w, h, k, tmp;
    cin >> k >> w >> h;
    vector<vector<int>> grid(h, vector<int>(w));
    vector<vector<vector<int>>> dist(h, vector<vector<int>>(w, vector<int>(k + 1, INT_MAX)));

    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < w; j++)
        {
            cin >> grid[i][j];
        }
    }

    queue<State> q;
    q.push({0, 0, k, 0});
    dist[0][0][k] = 0;

    while (!q.empty())
    {
        State cur = q.front();
        q.pop();

        if (cur.x == h - 1 && cur.y == w - 1)
        {
            cout << cur.dist;
            return 0;
        }

        for (int i = 0; i < 4; i++)
        {
            int nx = cur.x + dx[i], ny = cur.y + dy[i];
            if (nx >= 0 && ny >= 0 && nx < h && ny < w && grid[nx][ny] == 0)
            {
                if (dist[nx][ny][cur.k] > cur.dist + 1)
                {
                    dist[nx][ny][cur.k] = cur.dist + 1;
                    q.push({nx, ny, cur.k, cur.dist + 1});
                }
            }
        }

        if (cur.k > 0)
        {
            for (int i = 0; i < 8; i++)
            {
                int nx = cur.x + kdx[i], ny = cur.y + kdy[i];
                if (nx >= 0 && ny >= 0 && nx < h && ny < w && grid[nx][ny] == 0)
                {
                    if (dist[nx][ny][cur.k - 1] > cur.dist + 1)
                    {
                        dist[nx][ny][cur.k - 1] = cur.dist + 1;
                        q.push({nx, ny, cur.k - 1, cur.dist + 1});
                    }
                }
            }
        }
    }
    cout << -1;
    return 0;
}
