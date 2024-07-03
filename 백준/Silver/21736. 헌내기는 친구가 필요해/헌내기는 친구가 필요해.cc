#include <bits/stdc++.h>

using namespace std;

int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
int n, m;
vector<vector<char>> arr;
vector<vector<bool>> visited;
queue<pair<int, int>> Q;

int main()
{
    //freopen("test.txt", "rt", stdin);
    cin >> n >> m;
    arr.resize(n,vector<char>(m));
    visited.resize(n,vector<bool>(m));
    for(int i = 0; i < n; i++)
    {
        string tmp;
        cin >> tmp;
        for(int j = 0; j < m; j++)
        {
            arr[i][j] = tmp[j];
            if(arr[i][j] == 'I')
            {
                Q.push({i,j});
                visited[i][j] = true;
            }
        }
    }
    int count = 0;
    while(!Q.empty())
    {
        pair<int,int> cur = Q.front();
        Q.pop();
        for(int i = 0; i < 4; i++)
        {
            int nx = cur.first + dx[i];
            int ny = cur.second + dy[i];
            if(nx < 0 || ny < 0 || nx >= n || ny >= m || arr[nx][ny] == 'X' || visited[nx][ny])
            {
                continue;
            }
            visited[nx][ny] = true;
            if(arr[nx][ny] == 'P')
            {
                count++;
            }
            Q.push({nx,ny});
        }
    }
    if(!count)
    {
        cout << "TT";
    }
    else
    {
        cout << count;
    }
    return 0;
}