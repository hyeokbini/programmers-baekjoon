#include <bits/stdc++.h>

using namespace std;

int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin >> T;
    char map[T][T];
    char tmp;
    int normalvisitedmap[T][T] = {
        0,
    };
    int notnormalvisitedmap[T][T] = {
        0,
    };
    int normalcount = 0;
    int notnormalcount = 0;
    for (int i = 0; i < T; i++)
    {
        for (int j = 0; j < T; j++)
        {
            cin >> tmp;
            map[i][j] = tmp;
        }
    }
    for (int i = 0; i < T; i++)
    {
        for (int j = 0; j < T; j++)
        {
            if (normalvisitedmap[i][j] == 1)
            {
                continue;
            }
            tmp = map[i][j];
            normalcount++;
            queue<pair<int, int>> Q;
            normalvisitedmap[i][j] = 1;
            Q.push({i, j});
            while (!Q.empty())
            {
                pair<int, int> cur = Q.front();
                Q.pop();
                for (int k = 0; k < 4; k++)
                {
                    int nx = cur.first + dx[k];
                    int ny = cur.second + dy[k];
                    if (nx >= T || ny >= T || nx < 0 || ny < 0)
                    {
                        continue;
                    }
                    if (normalvisitedmap[nx][ny] == 1 || map[nx][ny] != tmp)
                    {
                        continue;
                    }
                    normalvisitedmap[nx][ny] = 1;
                    Q.push({nx, ny});
                }
            }
        }
    }
    for (int i = 0; i < T; i++)
    {
        for (int j = 0; j < T; j++)
        {
            if (notnormalvisitedmap[i][j] == 1)
            {
                continue;
            }
            tmp = map[i][j];
            notnormalcount++;
            queue<pair<int, int>> Q;
            notnormalvisitedmap[i][j] = 1;
            Q.push({i, j});
            while (!Q.empty())
            {
                pair<int, int> cur = Q.front();
                Q.pop();
                for (int k = 0; k < 4; k++)
                {
                    int nx = cur.first + dx[k];
                    int ny = cur.second + dy[k];
                    if (nx >= T || ny >= T || nx < 0 || ny < 0)
                    {
                        continue;
                    }
                    if (notnormalvisitedmap[nx][ny] == 1)
                    {
                        continue;
                    }
                    if (tmp == 'R' || tmp == 'G')
                    {
                        if(map[nx][ny] == 'B')
                        continue;
                    }
                    if (map[nx][ny] == 'R' || map[nx][ny] == 'G')
                    {
                        if(tmp == 'B')
                        continue;
                    }
                    notnormalvisitedmap[nx][ny] = 1;
                    Q.push({nx, ny});
                }
            }
        }
    }
    cout << normalcount << " " << notnormalcount;
    return 0;
}
