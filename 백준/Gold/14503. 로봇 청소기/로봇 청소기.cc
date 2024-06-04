#include <bits/stdc++.h>
using namespace std;

// 0은 청소 x, 1은 벽, 2는 청소됨
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
int ans = 0;

struct robot
{
    int curx;
    int cury;
    int curdir;
};

// 현재 공간이 청소가능하다면 청소
void clean(vector<vector<int>> &map, robot robot)
{
    if (map[robot.curx][robot.cury] == 0)
    {
        map[robot.curx][robot.cury] = 2;
        ans++;
    }
    return;
}

// 주변 4방향 청소체크(청소해야하면 true)
bool cleancheck(vector<vector<int>> map, robot robot)
{
    for (int i = 0; i < 4; i++)
    {
        int nx = robot.curx + dx[i];
        int ny = robot.cury + dy[i];
        if (nx >= map.size() || ny >= map[0].size() || nx < 0 || ny < 0)
        {
            continue;
        }
        if (map[nx][ny] == 0)
        {
            return true;
        }
    }
    return false;
}

bool backcheckwall(vector<vector<int>> map, robot robot) // 벽이면 true
{
    int nx = robot.curx - dx[robot.curdir];
    int ny = robot.cury - dy[robot.curdir];
    if (nx >= map.size() || ny >= map[0].size() || nx < 0 || ny < 0)
    {
        return true;
    }
    if (map[robot.curx - dx[robot.curdir]][robot.cury - dy[robot.curdir]] == 1)
    {
        return true;
    }
    return false;
}

void dirotate(robot &robot) // 청소기 방향 회전
{
    if (robot.curdir == 0)
    {
        robot.curdir = 3;
        return;
    }
    robot.curdir--;
    return;
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> map(n, vector<int>(m, 0));
    robot cleanrobot;
    cin >> cleanrobot.curx >> cleanrobot.cury >> cleanrobot.curdir;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> map[i][j];
        }
    }
    while (1)
    {
        clean(map, cleanrobot);
        if (cleancheck(map, cleanrobot)) // 청소해야 한다
        {
            dirotate(cleanrobot);
            while (map[cleanrobot.curx + dx[cleanrobot.curdir]][cleanrobot.cury + dy[cleanrobot.curdir]] != 0)
            {
                dirotate(cleanrobot); // 방향 설정
            }
            cleanrobot.curx += dx[cleanrobot.curdir];
            cleanrobot.cury += dy[cleanrobot.curdir]; // 이동
        }
        else // 청소할곳이 없다(방향 유지한 채 후진)
        {
            if (!backcheckwall(map, cleanrobot)) // 뒤가 벽이 아니라면
            {
                cleanrobot.curx -= dx[cleanrobot.curdir];
                cleanrobot.cury -= dy[cleanrobot.curdir]; // 이동
            }
            else // 뒤가 벽이라면(작동중지)
            {
                break;
            }
        }
    }
    cout << ans;
    return 0;
}
