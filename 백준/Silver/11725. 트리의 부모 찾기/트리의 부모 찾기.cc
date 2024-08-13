#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> tree;
vector<int> dist;

void dfs(int curidx, int curdist)
{
    if(dist[curidx] < curdist)
    {
        return;
    }
    int size = tree[curidx].size();
    dist[curidx] = curdist;
    for(int i = 0; i < size; i++)
    {
        dfs(tree[curidx][i],curdist + 1);
    }
}

void printans(int idx)
{
    int minval = INT_MAX;
    int paridx;
    int size = tree[idx].size();
    for(int i = 0; i < size; i++)
    {
        if(dist[tree[idx][i]] < minval)
        {
            minval = dist[tree[idx][i]];
            paridx = tree[idx][i];
        }
    }
    cout << paridx << "\n";
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    //freopen("test.txt", "rt", stdin);
    int n;
    cin >> n;
    tree.resize(n + 1,vector<int>());
    dist.resize(n + 1, INT_MAX);
    for(int i = 0; i < n - 1; i++)
    {
        int a,b;
        cin >> a >> b;
        tree[a].push_back(b);
        tree[b].push_back(a);
    }
    dfs(1,0);
    for(int i = 2; i <= n; i++)
    {
        printans(i);
    }
    return 0;
}
