#include <bits/stdc++.h>

using namespace std;

int n,m;
int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};
vector<vector<int>> cheese;

void melt(vector<vector<int>> check)
{
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            if(check[i][j] >= 2)
            {
                cheese[i][j] = 0;
            }
        }
    }
}

void bfs()
{
    vector<vector<int>> check(n,vector<int>(m,0));
    vector<vector<bool>> visited(n,vector<bool>(m,false));
    queue<pair<int,int>> Q;
    visited[0][0] = true;
    Q.push({0,0});
    while(!Q.empty())
    {
        pair<int,int> cur = Q.front();
        Q.pop();
        for(int i = 0; i < 4; i++)
        {
            int nx = dx[i] + cur.first;
            int ny = dy[i] + cur.second;
            if(nx >= n || ny >= m || nx < 0 || ny < 0 || visited[nx][ny])
            {
                continue;
            }
            if(cheese[nx][ny] == 1)
            {
                check[nx][ny]++;
            }
            if(cheese[nx][ny] == 0 && !visited[nx][ny])
            {
                visited[nx][ny] = true;
                Q.push({nx,ny});
            }
        }
    }
    melt(check);
}

bool anscheck()
{
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            if(cheese[i][j] == 1)
            {
                return false;
            }
        }
    }
    return true;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    //freopen("test.txt", "rt", stdin);
    int ans = 0;
    cin >> n >> m;
    cheese.resize(n,vector<int>(m));
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            cin >> cheese[i][j];
        }
    }
    while(1)
    {
        if(anscheck())
        {
            break;
        }
        ans++;
        bfs();
    }
    cout << ans;
    return 0;
}