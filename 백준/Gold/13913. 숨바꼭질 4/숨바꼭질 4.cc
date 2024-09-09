#include <bits/stdc++.h>

using namespace std;

int n, k;
vector<int> arr(100001, INT_MAX);

void bfs()
{
    vector<int> idx;
    idx.push_back(n);
    queue<tuple<int, int, vector<int>>> Q; // 위치,시간,인덱스 저장배열
    Q.push({n, 0, idx});
    arr[n] = 0;
    while (!Q.empty())
    {
        tuple<int, int, vector<int>> cur = Q.front();
        Q.pop();
        if (get<0>(cur) == k)
        {
            cout << get<1>(cur) << "\n";
            for(auto i : get<2>(cur))
            {
                cout << i << " ";
            }
            return;
        }

        if (get<0>(cur) + 1 <= 100000 && arr[get<0>(cur) + 1] > get<1>(cur) + 1)
        {
            arr[get<0>(cur) + 1] = get<1>(cur) + 1;
            get<2>(cur).push_back(get<0>(cur) + 1);
            Q.push({get<0>(cur) + 1, get<1>(cur) + 1, get<2>(cur)});
            get<2>(cur).pop_back();
        }
        if (get<0>(cur) - 1 >= 0 && arr[get<0>(cur) - 1] > get<1>(cur) + 1)
        {
            arr[get<0>(cur) - 1] = get<1>(cur) + 1;
            get<2>(cur).push_back(get<0>(cur) - 1);
            Q.push({get<0>(cur) - 1, get<1>(cur) + 1, get<2>(cur)});
            get<2>(cur).pop_back();
        }
        if (get<0>(cur) * 2 <= 100000 && arr[get<0>(cur) * 2] > get<1>(cur) + 1)
        {
            arr[get<0>(cur) * 2] = get<1>(cur) + 1;
            get<2>(cur).push_back(get<0>(cur) * 2);
            Q.push({get<0>(cur) * 2, get<1>(cur) + 1, get<2>(cur)});
            get<2>(cur).pop_back();
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
    return 0;
}
