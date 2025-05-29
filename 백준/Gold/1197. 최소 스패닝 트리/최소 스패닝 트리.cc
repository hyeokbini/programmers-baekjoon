#include <bits/stdc++.h>

using namespace std;

struct Edge
{
    int pre, next, weight;

    // 연산자 오버로딩
    bool operator<(const Edge &other) const
    {
        return weight < other.weight;
    }
};

vector<int> parent;

// find
int find(int x)
{
    if (parent[x] == x)
    {
        return x;
    }
    return parent[x] = find(parent[x]);
}

// unite
void unite(int a, int b)
{
    a = find(a);
    b = find(b);
    if (a != b)
    {
        parent[b] = a;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    //freopen("test.txt", "rt", stdin);
    int V, E;
    cin >> V >> E;

    vector<Edge> edges(E);
    for (int i = 0; i < E; i++)
    {
        cin >> edges[i].pre >> edges[i].next >> edges[i].weight;
    }

    sort(edges.begin(), edges.end());

    parent.resize(V + 1);
    for (int i = 1; i <= V; i++)
    {
        parent[i] = i;
    }

    int totalWeight = 0;
    for (Edge e : edges)
    {
        if (find(e.pre) != find(e.next))
        {
            unite(e.pre, e.next);
            totalWeight += e.weight;
        }
    }

    cout << totalWeight;

    return 0;
}
