#include <bits/stdc++.h>

using namespace std;

int n,m;
vector<vector<pair<int,int>>> arr; //2차원 벡터는 출발점 인덱스, pair는 도착지, 가중치
vector<int> dist;

void func(int start)
{
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;

    pq.push({0,start});
    dist[start] = 0;

    while(!pq.empty())
    {
        int curdist = pq.top().first;
        int curidx = pq.top().second;
        pq.pop();

        if(dist[curidx] < curdist)
        {
            continue;
        }

        for(int i = 0; i < arr[curidx].size(); i++)
        {
            int cost = curdist + arr[curidx][i].second;
            if(cost < dist[arr[curidx][i].first])
            {
                dist[arr[curidx][i].first] = cost;
                pq.push({cost,arr[curidx][i].first});
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
    int startidx;
    cin >> startidx;
    for(int i = 0; i < m; i++)
    {
        int a,b,c;
        cin >> a >> b >> c;
        arr[a].push_back({b,c});
    }
    func(startidx);
    for(int i = 1; i < dist.size(); i++)
    {
        if(i == startidx)
        {
            cout << 0 << "\n";
        }
        else if(dist[i] == INT_MAX)
        {
            cout << "INF\n";
        }
        else
        {
            cout << dist[i] << "\n";
        }
    }
    return 0;
}