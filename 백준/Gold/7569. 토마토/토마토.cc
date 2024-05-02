#include <bits/stdc++.h>

using namespace std;

int dx[6] = {0, 0, 0, 0, 1, -1};
int dy[6] = {0, 0, 1, -1, 0, 0};
int dz[6] = {1, -1, 0, 0, 0, 0};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    bool flag = false;
    int x, y, z, tmp;
    int count = 0;
    cin >> x >> y >> z;
    int map[z][y][x] = {0};
    for (int i = 0; i < z; i++)
    {
        for (int j = 0; j < y; j++)
        {
            for (int k = 0; k < x; k++)
            {
                cin >> tmp;
                map[i][j][k] = tmp;
            }
        }
    }

    queue<tuple<int, int, int>> q;
    for (int i = 0; i < z; i++)
    {
        for (int j = 0; j < y; j++)
        {
            for (int k = 0; k < x; k++)
            {
                if (map[i][j][k] == 1)
                {
                    q.push({i, j, k});
                }
            }
        }
    }

    while (!q.empty())
    {
        int size = q.size();
        for (int i = 0; i < size; i++)
        {
            auto [cz, cy, cx] = q.front();
            q.pop();
            for (int j = 0; j < 6; j++)
            {
                int nz = cz + dz[j];
                int ny = cy + dy[j];
                int nx = cx + dx[j];
                if (nz >= 0 && nz < z && ny >= 0 && ny < y && nx >= 0 && nx < x && map[nz][ny][nx] == 0)
                {
                    q.push({nz, ny, nx});
                    map[nz][ny][nx] = 1;
                }
            }
        }
        if (!q.empty())
        {
            count++;
        }
    }

    for (int i = 0; i < z; i++)
    {
        for (int j = 0; j < y; j++)
        {
            for (int k = 0; k < x; k++)
            {
                if (map[i][j][k] == 0)
                {
                    cout << -1;
                    return 0;
                }
            }
        }
    }

    cout << count;
    return 0;
}
