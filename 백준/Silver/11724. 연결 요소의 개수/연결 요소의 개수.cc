#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> arr;
vector<bool> visited;
int ans = 0;

void bfs()
{
    for(int i = 1; i < visited.size(); i++)
    {
        if(visited[i])
        {
            continue;
        }
        queue<int> Q;
        Q.push(i);
        visited[i] = true;
        while(!Q.empty())
        {
            int cur = Q.front();
            Q.pop();
            for(int j = 0; j < arr[cur].size(); j++)
            {
                if(visited[arr[cur][j]])
                {
                    continue;
                }
                Q.push(arr[cur][j]);
                visited[arr[cur][j]] = true;
            }
        }
        ans++;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    //freopen("test.txt", "rt", stdin);
    int n,m;
    cin >> n >> m;
    arr.resize(n + 1,vector<int>());
    visited.resize(n + 1);
    for(int i = 0; i < m; i++)
    {
        int a,b;
        cin >> a >> b;
        arr[a].push_back(b);
        arr[b].push_back(a);
    }
    bfs();
    cout << ans;
    return 0;
}
