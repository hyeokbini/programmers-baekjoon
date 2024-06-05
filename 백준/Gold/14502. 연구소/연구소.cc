#include <bits/stdc++.h>

using namespace std;

int n,m;
vector<vector<int>> virusmap;
int ans = 0;
int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};

void bfs(vector<vector<int>> map)
{
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            if(map[i][j] != 2)
            {
                continue;
            }
            queue<pair<int,int>> Q;
            Q.push({i,j});
            while(!Q.empty())
            {
                pair<int,int> cur = Q.front();
                Q.pop();
                for(int k = 0; k < 4; k++)
                {
                    int nx = cur.first + dx[k];
                    int ny = cur.second + dy[k];
                    if(nx < 0 || nx >= n || ny < 0 || ny >= m)
                    {
                        continue;
                    }
                    if(map[nx][ny] == 2 || map[nx][ny] == 1)
                    {
                        continue;
                    }
                    map[nx][ny] = 2;
                    Q.push({nx,ny});
                }
            }
        }
    }
    int zerocount = 0;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            if(map[i][j] == 0)
            {
                zerocount++;
            }
        }
    }
    ans = max(zerocount,ans);
}

void check(vector<vector<int>> map, int a, int b, int c)
{
    if(a == b || b == c || c == a)
    {
        return;
    }
    int ax = a/m;
    int ay = a%m;
    int bx = b/m;
    int by = b%m;
    int cx = c/m;
    int cy = c%m;
    if(map[ax][ay] == 1 || map[bx][by] == 1 || map[cx][cy] == 1
    || map[ax][ay] == 2 || map[bx][by] == 2 || map[cx][cy] == 2)
    {
        return;
    }
    map[ax][ay] = 1;
    map[bx][by] = 1;
    map[cx][cy] = 1;
    bfs(map);
    return;
}

int main()
{
    cin >> n>>m;
    virusmap.resize(n,vector<int>(m));
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            cin >> virusmap[i][j];
        }
    }
    for(int i = 0; i < n*m; i++)
    {
        for(int j = 0; j < n*m; j++)
        {
            for(int k = 0; k < n*m; k++)
            {
                check(virusmap, i,j,k);
            }
        }
    }
    cout << ans;
    return 0;
}