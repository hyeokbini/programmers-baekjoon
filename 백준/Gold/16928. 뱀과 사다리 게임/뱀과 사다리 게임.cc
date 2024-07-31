#include <bits/stdc++.h>

using namespace std;

vector<int> arr(101,INT_MAX);
vector<bool> vis(101,false);
vector<pair<int,int>> ladder;
vector<pair<int,int>> snake;

void bfs()
{
    queue<int> Q;
    Q.push(1);
    arr[1] = 0;
    vis[1] = true;
    while(!Q.empty())
    {
        int cur = Q.front();
        Q.pop();
        for(int i = 1; i <= 6; i++)
        {
            int nextidx = i + cur;
            for(auto i : ladder)
            {
                if(i.first == nextidx)
                {
                    nextidx = i.second;
                }
            }
            for(auto i : snake)
            {
                if(i.first == nextidx)
                {
                    nextidx = i.second;
                }
            }
            if(nextidx > 100 || vis[nextidx])
            {
                continue;
            }
            vis[nextidx] = true;
            arr[nextidx] = min(arr[nextidx],arr[cur] + 1);
            Q.push(nextidx);
        }
    }
    return;
}

int main()
{
    //freopen("test.txt", "rt", stdin);
    int n,m;
    cin >> n >> m;
    ladder.resize(n);
    snake.resize(m);
    for(int i = 0; i < n; i++)
    {
        int a,b;
        cin >> a >> b;
        ladder[i] = {a,b};
    }
    for(int i = 0; i < m; i++)
    {
        int a,b;
        cin >> a >> b;
        snake[i] = {a,b};
    }
    bfs();
    cout << arr[100];
    return 0;
}