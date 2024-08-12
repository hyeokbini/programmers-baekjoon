#include <bits/stdc++.h>

using namespace std;

long long int ans = INT_MAX;
long long int n;

void bfs(long long int val)
{
    queue<pair<long long int,long long int>> Q;
    Q.push({val,1});
    while(!Q.empty())
    {
        pair<long long int,long long int> cur = Q.front();
        Q.pop();
        if(cur.first == n)
        {
            ans = min(ans,cur.second);
        }
        else if(cur.first > n)
        {
            continue;
        }
        else
        {
            Q.push({cur.first * 10 + 1,cur.second + 1});
            Q.push({cur.first * 2,cur.second + 1});
        }
    }
    return;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    //freopen("test.txt", "rt", stdin);
    long long int start;
    cin >> start >> n;
    bfs(start);
    if(ans == INT_MAX)
    {
        cout << -1;
    }
    else
    {
        cout << ans;
    }
    return 0;
}
