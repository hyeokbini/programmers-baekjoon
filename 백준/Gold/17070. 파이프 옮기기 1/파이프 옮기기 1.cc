#include <bits/stdc++.h>

using namespace std;

// 1차원 인덱스 : 초기상태 가로, 세로, 대각선(0,1,2)
// 2차원 인덱스 : 다음상태에서 체크해야 할 모양
// 3차원 인덱스 : 다음상태에서 실제로 체크해야 할 좌표값
vector<vector<vector<int>>> dx = {{{0}, {0, 1, 1}}, {{1}, {0, 1, 1}}, {{0}, {1}, {0, 1, 1}}};
vector<vector<vector<int>>> dy = {{{1}, {1, 0, 1}}, {{0}, {1, 0, 1}}, {{1}, {0}, {1, 0, 1}}};
vector<vector<int>> arr;
int n;
int ans = 0;

void dfs(int x, int y, int curstate)
{
    if (x == n - 1 && y == n - 1)
    {
        ans++;
        return;
    }
    if (curstate == 0)
    {
        for (int i = 0; i < dx[curstate].size(); i++)
        {
            int size = dx[curstate][i].size();
            bool flag = true;
            for (int j = 0; j < size; j++)
            {
                int nx = x + dx[curstate][i][j];
                int ny = y + dy[curstate][i][j];
                if (nx >= n || ny >= n || nx < 0 || ny < 0)
                {
                    flag = false;
                    break;
                }
                if (arr[nx][ny] == 1)
                {
                    flag = false;
                    break;
                }
            }
            if (!flag)
            {
                continue;
            }
            else
            {
                if (i == 0)
                {
                    dfs(x, y + 1, 0);
                }
                else if (i == 1)
                {
                    dfs(x + 1, y + 1, 2);
                }
            }
        }
    }
    else if (curstate == 1)
    {
        for (int i = 0; i < dx[curstate].size(); i++)
        {
            int size = dx[curstate][i].size();
            bool flag = true;
            for (int j = 0; j < size; j++)
            {
                int nx = x + dx[curstate][i][j];
                int ny = y + dy[curstate][i][j];
                if (nx >= n || ny >= n || nx < 0 || ny < 0)
                {
                    flag = false;
                    break;
                }
                if (arr[nx][ny] == 1)
                {
                    flag = false;
                    break;
                }
            }
            if (!flag)
            {
                continue;
            }
            else
            {
                if (i == 0)
                {
                    dfs(x + 1, y, 1);
                }
                else if (i == 1)
                {
                    dfs(x + 1, y + 1, 2);
                }
            }
        }
    }
    else if (curstate == 2)
    {
        for (int i = 0; i < dx[curstate].size(); i++)
        {
            int size = dx[curstate][i].size();
            bool flag = true;
            for (int j = 0; j < size; j++)
            {
                int nx = x + dx[curstate][i][j];
                int ny = y + dy[curstate][i][j];
                if (nx >= n || ny >= n || nx < 0 || ny < 0)
                {
                    flag = false;
                    break;
                }
                if (arr[nx][ny] == 1)
                {
                    flag = false;
                    break;
                }
            }
            if (!flag)
            {
                continue;
            }
            else
            {
                if (i == 0)
                {
                    dfs(x, y + 1, 0);
                }
                else if (i == 1)
                {
                    dfs(x + 1, y, 1);
                }
                else if (i == 2)
                {
                    dfs(x + 1, y + 1, 2);
                }
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    //freopen("test.txt", "rt", stdin);
    cin >> n;
    arr.resize(n, vector<int>(n));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> arr[i][j];
        }
    }
    dfs(0, 1, 0);
    cout << ans;
}
