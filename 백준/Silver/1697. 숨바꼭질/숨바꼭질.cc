#include <bits/stdc++.h>

using namespace std;

vector<int> dist(100001, INT_MAX);

int func(int N, int K)
{
    queue<int> q;
    q.push(N);
    dist[N] = 0;
    while (!q.empty())
    {
        int cur = q.front();
        q.pop();
        if (cur == K)
            break;
        if (cur - 1 >= 0 && dist[cur - 1] > dist[cur] + 1)
        {
            dist[cur - 1] = dist[cur] + 1;
            q.push(cur - 1);
        }
        if (cur + 1 <= 100000 && dist[cur + 1] > dist[cur] + 1)
        {
            dist[cur + 1] = dist[cur] + 1;
            q.push(cur + 1);
        }
        if (2 * cur <= 100000 && dist[2 * cur] > dist[cur])
        {
            dist[2 * cur] = dist[cur] + 1;
            q.push(2 * cur);
        }
    }

    return dist[K];
}

int main()
{
    int N, K;
    cin >> N >> K;
    cout << func(N, K);
    return 0;
}
