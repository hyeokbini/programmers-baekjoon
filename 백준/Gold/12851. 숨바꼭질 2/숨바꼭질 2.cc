#include <bits/stdc++.h>

using namespace std;

int n, k;
int secondans = 0;
vector<int> arr(100001, INT_MAX);

void bfs()
{
    queue<pair<int, int>> Q; // 위치,시간
    Q.push({n, 0});
    arr[n] = 0;
    while (!Q.empty())
    {
        pair<int, int> cur = Q.front();
        Q.pop();
        if (cur.first == k)
        {
            if (arr[k] > cur.second)
            {
                arr[k] = cur.second;
                secondans = 0;      
                secondans++;        
            }
            else if (arr[k] == cur.second)
            {
                secondans++;
            }
            continue;
        }

        if (cur.first + 1 <= 100000 && arr[cur.first + 1] >= cur.second + 1)
        {
            arr[cur.first + 1] = cur.second + 1;
            Q.push({cur.first + 1, cur.second + 1});
        }
        if (cur.first - 1 >= 0 && arr[cur.first - 1] >= cur.second + 1)
        {
            arr[cur.first - 1] = cur.second + 1;
            Q.push({cur.first - 1, cur.second + 1});
        }
        if (cur.first * 2 <= 100000 && arr[cur.first * 2] >= cur.second + 1)
        {
            arr[cur.first * 2] = cur.second + 1;
            Q.push({cur.first * 2, cur.second + 1});
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    //freopen("test.txt", "rt", stdin);
    cin >> n >> k;
    bfs();
    cout << arr[k] << "\n" << secondans;
    return 0;
}
