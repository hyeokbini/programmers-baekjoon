#include <bits/stdc++.h>
using namespace std;

struct cur
{
    int curx;
    int cury;
    int curz;
    int curmove;
};

int dx[6] = {1, -1, 0, 0, 0, 0};
int dy[6] = {0, 0, 1, -1, 0, 0};
int dz[6] = {0, 0, 0, 0, 1, -1};
int mindis = INT_MAX;

int maze[5][5][5];
int rotatedmaze[5][5][5];

void bfs()
{
    if (rotatedmaze[0][0][0] == 0 || rotatedmaze[4][4][4] == 0)
    {
        return; // 출발지 또는 도착지가 막혀 있는 경우
    }

    queue<cur> q;
    bool visited[5][5][5] = {false};
    q.push({0, 0, 0, 0});
    visited[0][0][0] = true;

    while (!q.empty())
    {
        cur now = q.front();
        q.pop();

        if (now.curx == 4 && now.cury == 4 && now.curz == 4)
        {
            mindis = min(mindis, now.curmove);
            return;
        }

        for (int i = 0; i < 6; ++i)
        {
            int nx = now.curx + dx[i];
            int ny = now.cury + dy[i];
            int nz = now.curz + dz[i];

            if (nx >= 0 && nx < 5 && ny >= 0 && ny < 5 && nz >= 0 && nz < 5 &&
                !visited[nx][ny][nz] && rotatedmaze[nx][ny][nz] == 1)
            {
                visited[nx][ny][nz] = true;
                q.push({nx, ny, nz, now.curmove + 1});
            }
        }
    }
}

void mazerotate(int maze[5][5])
{
    int tmp[5][5];
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            tmp[i][j] = maze[i][j];
        }
    }
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            int targeti = (j - 2) * -1 + 2;
            int targetj = i;
            maze[targeti][targetj] = tmp[i][j];
        }
    }
}

void allmazerotate(int depth)
{
    if (depth == 5)
    {
        bfs();
        return;
    }
    for (int i = 0; i < 4; i++)
    {
        mazerotate(rotatedmaze[depth]);
        allmazerotate(depth + 1);
    }
}

void ans(vector<int> &layers, int depth)
{
    if (depth == 5)
    {
        for (int i = 0; i < 5; ++i)
        {
            for (int j = 0; j < 5; ++j)
            {
                for (int k = 0; k < 5; ++k)
                {
                    rotatedmaze[i][j][k] = maze[layers[i]][j][k];
                }
            }
        }
        allmazerotate(0);
        return;
    }

    for (int i = depth; i < 5; ++i)
    {
        swap(layers[depth], layers[i]);
        ans(layers, depth + 1);
        swap(layers[depth], layers[i]);
    }
}

int main()
{
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            for (int k = 0; k < 5; k++)
            {
                cin >> maze[i][j][k]; // j , k가 한 판 구성, i는 각 층
            }
        }
    }
    vector<int> layers = {0, 1, 2, 3, 4};
    ans(layers, 0);
    if (mindis == INT_MAX)
    {
        cout << -1;
    }
    else
    {
        cout << mindis;
    }
    return 0;
}
