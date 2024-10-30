#include <bits/stdc++.h>

using namespace std;

int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};
vector<vector<int>> arr(501,vector<int>(501,INT_MAX));
vector<vector<int>> areaval(501,vector<int>(501,1));

void bfs()
{
    deque<pair<int,int>> Q;
    Q.push_back({0,0});
    while(!Q.empty())
    {
        pair<int,int> cur = Q.front();
        Q.pop_front();
        for(int i = 0; i < 4; i++)
        {
            int nx = cur.first + dx[i];
            int ny = cur.second + dy[i];
            if(nx >= 501 || ny >= 501 || nx < 0 || ny < 0)
            {
                continue;
            }
            if(areaval[nx][ny] == 0)
            {
                continue;
            }
            if(arr[cur.first][cur.second] + 1 >= arr[nx][ny])
            {
                continue;
            }
            if(areaval[nx][ny] == 1)
            {
                arr[nx][ny] = arr[cur.first][cur.second];
                Q.push_front({nx,ny});
            }
            else if(areaval[nx][ny] != 1)
            {
                arr[nx][ny] = arr[cur.first][cur.second] + 1;
                Q.push_back({nx,ny});
            }
            
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    //freopen("test.txt", "rt", stdin);
    int n,m;
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        int x1,y1,x2,y2;
        cin >> x1 >> y1 >> x2 >> y2;
        if(x1 > x2)
        {
            swap(x1,x2);
        }
        if(y1 > y2)
        {
            swap(y1,y2);
        }
        for(int j = x1; j <= x2; j++)
        {
            for(int k = y1; k <= y2; k++)
            {
                areaval[j][k]++;
            }
        }
    }
    cin >> m;
    for(int i = 0; i < m; i++)
    {
        int x1,y1,x2,y2;
        cin >> x1 >> y1 >> x2 >> y2;
        if(x1 > x2)
        {
            swap(x1,x2);
        }
        if(y1 > y2)
        {
            swap(y1,y2);
        }
        for(int j = x1; j <= x2; j++)
        {
            for(int k = y1; k <= y2; k++)
            {
                areaval[j][k] = 0;
            }
        }
    }
    arr[0][0] = 0;
    bfs();
    if(arr[500][500] == INT_MAX)
    {
        cout << -1;
        return 0;
    }
    cout << arr[500][500];
    return 0;
}
