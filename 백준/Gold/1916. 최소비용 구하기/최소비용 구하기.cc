#include <bits/stdc++.h>

using namespace std;

int n,m,ansstart,ansend;
vector<vector<pair<int,int>>> arr;
vector<int> dist;

void func(int start)// 다익스트라
{
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;

    pq.push({0,start});
    dist[start] = 0;

    while(!pq.empty())
    {
        int curdist = pq.top().first;
        int cur = pq.top().second;
        pq.pop();

        if(dist[cur] < curdist)
        {
            continue;
        }

        for(int i = 0; i < arr[cur].size(); i++)
        {
            int cost = curdist + arr[cur][i].second;
            if(cost < dist[arr[cur][i].first])
            {
                dist[arr[cur][i].first] = cost;
                pq.push({cost,arr[cur][i].first});
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    //freopen("test.txt", "rt", stdin);
    cin >> n >> m;
    arr.resize(n + 1,vector<pair<int,int>>());
    dist.resize(n + 1,INT_MAX);
    for(int i = 0; i < m; i++)
    {
        int start, end, weight;
        cin >> start >> end >> weight;
        arr[start].push_back({end,weight});
    }
    cin >> ansstart >> ansend;
    func(ansstart);
    cout << dist[ansend];
}
