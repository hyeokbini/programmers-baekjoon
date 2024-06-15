#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> com;
bool visited[101];

void func(int idx)
{
    if(!visited[idx])
    {
        visited[idx] = true;
    }
    else
    {
        return;
    }
    for(int i = 0; i < com[idx].size(); i++)
    {
        func(com[idx][i]);
    }
    return;
}

int main()
{
    //freopen("test.txt", "rt", stdin);
    int n,k;
    int ans = 0;
    cin >> k;
    com.resize(k + 1);
    cin >> n;
    int a,b;
    for(int i = 0; i < n; i++)
    {
        cin >> a >> b;
        com[a].push_back(b);
        com[b].push_back(a);
    }
    func(1);
    for(int i = 2; i <= k; i++)
    {
        if(visited[i])
        {
            ans++;
        }
    }
    cout << ans;
}
