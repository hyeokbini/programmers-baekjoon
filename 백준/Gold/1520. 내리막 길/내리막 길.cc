#include <bits/stdc++.h>

using namespace std;

int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};

vector<vector<int>> arr;
vector<vector<int>> dp;

int n,m;
int ans = 0;

int dfs(int curx, int cury, vector<vector<bool>> &visited)
{
    if(visited[curx][cury] == true)
    {
        return dp[curx][cury];
    }
    if(curx == n - 1 && cury == m - 1)
    {
        return 1;
    }
    for(int i = 0; i < 4; i++)
    {
        int nx = curx + dx[i];
        int ny = cury + dy[i];
        if(nx >= n || ny >= m || nx < 0 || ny < 0)
        {
            continue;
        }
        if(arr[curx][cury] <= arr[nx][ny])
        {
            continue;
        }
        
        dp[curx][cury] += dfs(nx,ny, visited);
    }
    visited[curx][cury] = true;
    return dp[curx][cury];
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    //freopen("test.txt", "rt", stdin);
    cin >> n >> m;
    arr.resize(n,vector<int>(m));
    dp.resize(n,vector<int>(m,0));
    vector<vector<bool>> visited(n,vector<bool>(m, false));
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            cin >> arr[i][j];
        }
    }
    cout << dfs(0,0, visited);
    return 0;
}