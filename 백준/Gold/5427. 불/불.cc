#include <bits/stdc++.h>

using namespace std;

int w, h;
char building[1001][1001];
int firemap[1001][1001];
int sangmap[1001][1001];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

void bfsfire(queue<pair<int, int>> &fireq)
{
    while (!fireq.empty())
    {
        int x = fireq.front().first;
        int y = fireq.front().second;
        fireq.pop();

        for (int i = 0; i < 4; ++i)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx >= 0 && ny >= 0 && nx < h && ny < w)
            {
                if (building[nx][ny] == '.' && firemap[nx][ny] == -1)
                {
                    firemap[nx][ny] = firemap[x][y] + 1;
                    fireq.push({nx, ny});
                }
            }
        }
    }
}

int bfssang(pair<int, int> sangstart, queue<pair<int, int>> &sangq)
{
    while (!sangq.empty())
    {
        int x = sangq.front().first;
        int y = sangq.front().second;
        sangq.pop();

        for (int i = 0; i < 4; ++i)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx < 0 || ny < 0 || nx >= h || ny >= w)
            {
                return sangmap[x][y] + 1;
            }

            if (building[nx][ny] == '.' && sangmap[nx][ny] == -1)
            {
                if (firemap[nx][ny] == -1 || sangmap[x][y] + 1 < firemap[nx][ny])
                {
                    sangmap[nx][ny] = sangmap[x][y] + 1;
                    sangq.push({nx, ny});
                }
            }
        }
    }
    return -1;
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
        cin >> w >> h;

        queue<pair<int, int>> fireq;
        queue<pair<int, int>> sangq;
        pair<int, int> start;

        for (int i = 0; i < h; ++i)
        {
            for (int j = 0; j < w; ++j)
            {
                cin >> building[i][j];
                firemap[i][j] = -1;
                sangmap[i][j] = -1;

                if (building[i][j] == '*')
                {
                    fireq.push({i, j});
                    firemap[i][j] = 0;
                }
                else if (building[i][j] == '@')
                {
                    start = {i, j};
                    sangq.push(start);
                    sangmap[i][j] = 0;
                }
            }
        }

        bfsfire(fireq);
        int result = bfssang(start, sangq);

        if (result == -1)
        {
            cout << "IMPOSSIBLE\n";
        }
        else
        {
            cout << result << "\n";
        }
    }

    return 0;
}
