#include <bits/stdc++.h>
using namespace std;

vector<bool> visited(10000);

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    // freopen("test.txt", "rt", stdin);
    string tmp;
    cin >> tmp;

    int val = 0, ans = 0;
    val += stoi(tmp.substr(0, 2)) * 60;
    val += stoi(tmp.substr(3, 2));

    // <현재값, 시행횟수, 시작버튼 여부>
    queue<tuple<int, int, bool>> Q;
    Q.push({0, 0, false});
    Q.push({30, 1, true});
    visited[0] = true;
    visited[30] = true;

    while (!Q.empty())
    {
        auto cur = Q.front();
        Q.pop();

        int t = get<0>(cur);
        int cnt = get<1>(cur);
        bool started = get<2>(cur);

        if (t == val)
        {
            ans = cnt + (!started);
            break;
        }

        if (t > 3600)
            continue;

        if (t + 10 <= 3600 && !visited[t + 10])
        {
            visited[t + 10] = true;
            Q.push({t + 10, cnt + 1, started});
        }
        if (t + 60 <= 3600 && !visited[t + 60])
        {
            visited[t + 60] = true;
            Q.push({t + 60, cnt + 1, started});
        }
        if (t + 600 <= 3600 && !visited[t + 600])
        {
            visited[t + 600] = true;
            Q.push({t + 600, cnt + 1, started});
        }
        if (t + 30 <= 3600 && !visited[t + 30])
        {
            visited[t + 30] = true;
            Q.push({t + 30, cnt + 1, started});
        }
    }

    cout << ans;
    return 0;
}
