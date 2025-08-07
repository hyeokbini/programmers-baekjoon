#include <bits/stdc++.h>
using namespace std;

int ans = -1;
int firval, secval;
void dfs(vector<vector<int>> arr, vector<bool> visited,int curval, int depth)
{
    if(visited[curval])
    {
        return;
    }
    if(curval == secval)
    {
        ans = depth;
        return;
    }
    visited[curval] = true;
    for(int i = 0; i < arr[curval].size(); i++)
    {
        dfs(arr,visited,arr[curval][i],depth + 1);
    }
    return;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    //freopen("test.txt", "rt", stdin);
    int n;
    cin >> n;
    vector<vector<int>> arr(n + 1);
    vector<bool> visited(n + 1,false);
    cin >> firval >> secval;
    int m;
    cin >> m;
    for (int i = 0; i < m; i++)
    {
        int parent, child;
        cin >> parent >> child;
        arr[parent].push_back(child);
        arr[child].push_back(parent);
    }
    dfs(arr,visited,firval,0);
    cout << ans;
    return 0;
}
