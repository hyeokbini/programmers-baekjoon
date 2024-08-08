#include <bits/stdc++.h>

using namespace std;

int n;
int dx[6] = {0, 1, 1, 0, -1, -1};
int dy[6] = {1, 0, -1, -1, 0, 1};
vector<bool> used(3, false);
vector<vector<char>> arr;
vector<vector<int>> recordmap; // 색깔 기록 맵

void dfs(int i, int j, int color)
{
    recordmap[i][j] = color;
    used[color] = true;
    for (int t = 0; t < 6; t++)
    {
        int nx = i + dx[t];
        int ny = j + dy[t];
        if (nx >= n || ny >= n || nx < 0 || ny < 0)
        {
            continue;
        }
        if (arr[nx][ny] == 'X' && recordmap[nx][ny] == -1)
        {
            dfs(nx,ny,1-color);
        }
        else if (arr[nx][ny] == 'X' && recordmap[nx][ny] == color)
        {
            used[2] = true;
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    //freopen("test.txt", "rt", stdin);
    cin >> n;
    arr.resize(n, vector<char>(n));
    recordmap.resize(n, vector<int>(n, -1));
    for (int i = 0; i < n; i++)
    {
        string tmp;
        cin >> tmp;
        for (int j = 0; j < n; j++)
        {
            arr[i][j] = tmp[j];
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (arr[i][j] == 'X' && recordmap[i][j] == -1)
            {
                dfs(i, j, 0);
            }
        }
    }
    int ans = 0;
    for (int i = 0; i < 3; i++)
    {
        if (used[i])
        {
            ans++;
        }
    }
    cout << ans;
    return 0;
}
