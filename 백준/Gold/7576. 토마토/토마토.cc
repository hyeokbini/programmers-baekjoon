#include <bits/stdc++.h>

using namespace std;

int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
int n, m;
vector<vector<int>> arr;
queue<pair<int, int>> Q;

int main()
{
    //freopen("test.txt", "rt", stdin);
    cin >> m >> n;
    int tmp;
    arr.resize(n, vector<int>(m));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> tmp;
            arr[i][j] = tmp;
            if (tmp == 1)
            {
                Q.push({i, j});
            }
        }
    }
    int day = -1;
    while (!Q.empty())
    {
        int qlength = Q.size();
        while (qlength--)
        {
            pair<int, int> cur = Q.front();
            Q.pop();
            for(int i = 0; i < 4; i++)
            {
                int nx = cur.first + dx[i];
                int ny = cur.second + dy[i];
                if(nx < 0 || ny < 0 || nx >= n || ny >= m || arr[nx][ny] != 0)
                {
                    continue;
                }
                arr[nx][ny] = 1;
                Q.push({nx,ny});
            }
        }
        day++;
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if(arr[i][j] == 0)
            {
                cout << -1;
                return 0;
            }
        }
    }
    cout << day;
}