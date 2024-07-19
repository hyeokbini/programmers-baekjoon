#include <bits/stdc++.h>

using namespace std;

int n,m;
int ans = INT_MAX;
int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};
vector<pair<int,int>> virusstartidx;
vector<bool> curvirusused;
vector<vector<bool>> visited;


void bfs(vector<vector<int>> arr)
{
    queue<pair<int,int>> Q;
    for(int i = 0; i < virusstartidx.size(); i++)
    {
        arr[virusstartidx[i].first][virusstartidx[i].second] = 0;
        if(curvirusused[i])
        {
            Q.push(virusstartidx[i]);
            visited[virusstartidx[i].first][virusstartidx[i].second] = true;
        }
    }
    int tmpval = 0;
    while(!Q.empty())
    {
        int sz = Q.size();
        while(sz--)
        {
            pair<int,int> cur = Q.front();
            Q.pop();
            for (int i = 0; i < 4; i++)
			{
				int nx = cur.first + dx[i];
				int ny = cur.second + dy[i];
                if(nx < 0 || ny < 0 || nx >= n || ny >= n)
                {
                    continue;
                }
                if(visited[nx][ny] || arr[nx][ny] == 1)
                {
                    continue;
                }
                arr[nx][ny] = arr[cur.first][cur.second] + 1;
                tmpval = max(arr[nx][ny],tmpval);
                Q.push({nx,ny});
                visited[nx][ny] = true;
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (arr[i][j] == 0 && !visited[i][j])
            {
                return;
            }
        }
    }
    /*cout << "사용한 바이러스 위치 :";
    for(int i = 0; i < virusstartidx.size(); i++)
    {
        if(curvirusused[i])
        {
            cout <<"(" << virusstartidx[i].first << " " << virusstartidx[i].second << ")" << ",";
        }
    }
    cout << "\n\n";
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << "\n";
    }*/
    ans = min(ans,tmpval);
    //cout << ans << "\n\n";
}

void dfs(int cnt, int idx, vector<vector<int>> arr)
{
    if(cnt == m)
    {
        fill(visited.begin(),visited.end(),vector<bool>(n,false));
        bfs(arr);
        return;
    }

    for(int i = idx; i < virusstartidx.size(); i++)
    {
        if(curvirusused[i])
        {
            continue;
        }
        curvirusused[i] = true;
        dfs(cnt + 1, i + 1, arr);
        curvirusused[i] = false;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    //freopen("test.txt", "rt", stdin);
    cin >> n >> m;
    vector<vector<int>> arr(n,vector<int>(n));
    visited.resize(n,vector<bool>(n,false));
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            cin >> arr[i][j];
            if(arr[i][j] == 1)
            {
                visited[i][j] = true;
            }
            if(arr[i][j] == 2)
            {
                virusstartidx.push_back({i,j});
            }
        }
    }
    curvirusused.resize(virusstartidx.size(),false);
    dfs(0,0,arr);

    if (ans == INT_MAX)
    {
        cout << -1;
    }
    else
    {
        cout << ans;
    }
    return 0;
}
