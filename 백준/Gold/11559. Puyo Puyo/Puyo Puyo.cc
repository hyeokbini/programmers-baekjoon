#include <bits/stdc++.h>

using namespace std;

vector<vector<char>> arr(12, vector<char>(6));
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
int ans = 0;

void func()
{
    while (1) // 한 단계의 계산
    {
        bool visited[12][6] = {0,};
        bool curlevbomb = false;
        for (int i = 0; i < 12; i++)
        {
            for (int j = 0; j < 6; j++) // 지점마다 bfs
            {
                if (visited[i][j] == true || arr[i][j] == '.')
                {
                    continue;
                }
                queue<pair<int, int>> Q;
                stack<pair<int, int>> S;
                int ifcountfour = 0;
                char checkchar = arr[i][j];
                Q.push({i, j});
                S.push({i, j});
                while (!Q.empty())
                {
                    pair<int, int> cur = Q.front();
                    Q.pop();
                    for (int k = 0; k < 4; k++)
                    {
                        int nx = cur.first + dx[k];
                        int ny = cur.second + dy[k];
                        if (nx < 0 || ny < 0 || nx >= 12 || ny >= 6)
                        {
                            continue;
                        }
                        if (visited[nx][ny] || arr[nx][ny] != checkchar)
                        {
                            continue;
                        }
                        ifcountfour++;
                        visited[nx][ny] = 1;
                        S.push({nx, ny});
                        Q.push({nx, ny});
                    }
                }
                if (ifcountfour >= 4)
                {
                    curlevbomb = true;
                    while (!S.empty())
                    {
                        pair<int, int> cur = S.top();
                        S.pop();
                        arr[cur.first][cur.second] = '.';
                    }
                }
            }
        }
        if (!curlevbomb)
        {
            break;
        }
        if (curlevbomb)
        {
            for (int j = 0; j < 6; j++)
            {
                int write_pos = 11;
                for (int i = 11; i >= 0; i--)
                {
                    if (arr[i][j] != '.')
                    {
                        arr[write_pos--][j] = arr[i][j];
                    }
                }
                for (int i = write_pos; i >= 0; i--)
                {
                    arr[i][j] = '.';
                }
            }
        }
        ans++;
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    for (int i = 0; i < 12; i++)
    {
        string tmp;
        cin >> tmp;
        for (int j = 0; j < 6; j++)
        {
            arr[i][j] = tmp[j];
        }
    }
    func();
    cout << ans;
}