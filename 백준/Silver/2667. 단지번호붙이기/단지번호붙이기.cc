#include <bits/stdc++.h>

using namespace std;

int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
int n;
vector<vector<int>> arr;
vector<vector<bool>> visited;
int allval;
vector<int> countval;

void bfs()
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (visited[i][j] || !arr[i][j])
            {
                continue;
            }
            allval++;
            queue<pair<int, int>> Q;
            Q.push({i, j});
            int val = 1;
            while (!Q.empty())
            {
                pair<int, int> cur = Q.front();
                Q.pop();
                visited[i][j] = true;
                for (int i = 0; i < 4; i++)
                {
                    int nx = cur.first + dx[i];
                    int ny = cur.second + dy[i];
                    if(nx < 0 || ny < 0 || nx >= n || ny >= n || visited[nx][ny] || !arr[nx][ny])
                    {
                        continue;
                    }
                    visited[nx][ny] = true;
                    Q.push({nx,ny});
                    val++;
                }
            }
            countval.push_back(val);
        }
    }
    return;
}

int main()
{
    //freopen("test.txt", "rt", stdin);

    cin >> n;
    arr.resize(n + 1, vector<int>(n + 1));
    visited.resize(n + 1, vector<bool>(n + 1));
    for (int i = 0; i < n; i++)
    {
        string tmp;
        cin >> tmp;
        for (int j = 0; j < n; j++)
        {
            arr[i][j] = tmp[j] - '0';
        }
    }
    bfs();
    cout << allval << "\n";
    sort(countval.begin(),countval.end());
    for(auto i : countval)
    {
        cout << i << "\n";
    }
    return 0;
}