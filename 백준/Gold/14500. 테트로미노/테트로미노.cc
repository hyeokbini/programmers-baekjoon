#include <bits/stdc++.h>

using namespace std;

int n,m;
int ans = 0;
int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};
vector<vector<int>> arr;
vector<vector<bool>> visited;

void dfs(int curx, int cury, int dep, int curval)
{
    visited[curx][cury] = true;
    int newval = curval + arr[curx][cury];
    if(dep == 4)
    {
        ans = max(ans, newval);
        visited[curx][cury] = false;
        return;
    }
    for(int i = 0; i < 4; i++)
    {
        int nx = curx + dx[i];
        int ny = cury + dy[i];
        if(nx >= n || ny >= m || nx < 0 || ny < 0)
        {
            continue;
        }
        if(visited[nx][ny])
        {
            continue;
        }
        dfs(nx, ny, dep + 1, newval);
    }
    visited[curx][cury] = false;
}

void minibfs(int curx, int cury, int ignoreidx)
{
    int curval = arr[curx][cury];
    for(int i = 0; i < 4; i++)
    {
        if(i == ignoreidx)
        {
            continue;
        }
        int nx = curx + dx[i];
        int ny = cury + dy[i]; 
        if(nx >= n || ny >= m || nx < 0 || ny < 0)
        {
            return;
        }
        curval += arr[nx][ny];
    }
    ans = max(ans,curval);
    return;
}

void func(int x, int y)
{
    dfs(x,y,1,0); // 일자, L자, 지그재그 모양 
    if(x < n - 1 && y < m - 1)
    {
        ans = max(ans,arr[x][y] + arr[x + 1][y] + arr[x][y + 1] + arr[x + 1][y + 1]);
    } // 정사각형 모양
    for(int i = 0; i < 4; i++)
    {
        minibfs(x,y,i);
    } // T자 모양
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    //freopen("test.txt", "rt", stdin);
    cin >> n >> m;
    arr.resize(n,vector<int>(m));
    visited.resize(n,vector<bool>(m,false));
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            cin >> arr[i][j];
        }
    }
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            func(i,j);
        }
    }
    cout << ans;
    return 0;
}
