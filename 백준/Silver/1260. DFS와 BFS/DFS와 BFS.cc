#include <bits/stdc++.h>

using namespace std;

int n, m, v;
vector<bool> visited(1001);
vector<vector<int>> arr;

void dfs(int v)
{
    if (visited[v])
    {
        return;
    }
    else
    {
        cout << v << " ";
        visited[v] = true;
        for (int i = 0; i < arr[v].size(); i++)
        {
            dfs(arr[v][i]);
        }
    }
    return;
}

void bfs(int v)
{
    queue<int> Q;
    Q.push(v);
    visited[v] = true;
    while (!Q.empty())
    {
        int cur = Q.front();
        Q.pop();
        cout << cur << " ";
        
        for (int i = 0; i < arr[cur].size(); i++)
        {
            if (visited[arr[cur][i]])
            {
                continue;
            }
            Q.push(arr[cur][i]);
            visited[arr[cur][i]] = true;
        }
    }
    return;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    //freopen("test.txt", "rt", stdin);
    cin >> n >> m >> v;
    arr.resize(n + 1);
    int start, end;
    for (int i = 0; i < m; i++)
    {
        cin >> start >> end;
        arr[start].push_back(end);
        arr[end].push_back(start);
    }
    for(int i = 0; i < arr.size(); i++)
    {
        sort(arr[i].begin(),arr[i].end());
    }
    dfs(v);
    fill(visited.begin(), visited.end(), false);
    cout << "\n";
    bfs(v);
    return 0;
}
