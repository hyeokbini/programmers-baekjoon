#include <bits/stdc++.h>

using namespace std;

int n, m;
int ans = 0;
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
vector<vector<char>> arr;

void dfs(int x, int y, int depth, vector<bool> &used)
{
    bool canmove = false;
    used[arr[x][y] - 65] = true;
    for (int i = 0; i < 4; i++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx >= n || ny >= m || nx < 0 || ny < 0)
        {
            continue;
        }
        if (used[arr[nx][ny] - 65])
        {
            continue;
        }
        canmove = true;
        dfs(nx, ny, depth + 1, used);
    }
    used[arr[x][y] - 65] = false;
    if (!canmove)
    {
        ans = max(ans, depth);
        return;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    //freopen("test.txt", "rt", stdin);
    cin >> n >> m;
    arr.resize(n, vector<char>(m));
    vector<bool> used(28, false);
    for (int i = 0; i < n; i++)
    {
        string tmp;
        cin >> tmp;
        for (int j = 0; j < m; j++)
        {
            arr[i][j] = tmp[j];
        }
    }
    dfs(0, 0, 1, used);
    cout << ans;
    return 0;
}
