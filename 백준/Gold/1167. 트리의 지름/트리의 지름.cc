#include <bits/stdc++.h>

using namespace std;

int n;
int startnode = 0;
int longweight = 0;
vector<vector<pair<int, int>>> tree;
vector<bool> visited;
void dfs(int curnodeidx, int curweight)
{
    visited[curnodeidx] = true;
    int len = tree[curnodeidx].size();
    for (int i = 0; i < len; i++)
    {
        if (!visited[tree[curnodeidx][i].first])
        {
            dfs(tree[curnodeidx][i].first, curweight + tree[curnodeidx][i].second);
        }
    }
    if (curweight > longweight)
    {
        startnode = curnodeidx;
        longweight = curweight;
    }
    return;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    // freopen("test.txt", "rt", stdin);
    cin >> n;
    tree.resize(n + 1);
    visited.resize(n + 1, false);
    for (int i = 0; i < n - 1; i++)
    {
        int start, end, weight;
        cin >> start;
        while (1)
        {
            cin >> end;
            if (end == -1)
            {
                break;
            }
            cin >> weight;
            tree[start].push_back({end, weight});
            tree[end].push_back({start, weight});
        }
    }
    dfs(1, 0);
    fill(visited.begin(), visited.end(), false);
    longweight = 0;
    dfs(startnode, 0);
    cout << longweight;
    return 0;
}
