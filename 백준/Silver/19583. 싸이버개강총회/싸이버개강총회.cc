#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie();
    //freopen("test.txt", "rt", stdin);
    unordered_map<string, pair<bool, bool>> arr;
    string start, end1, end2;
    cin >> start >> end1 >> end2;

    start.erase(2, 1);
    end1.erase(2, 1);
    end2.erase(2, 1);

    int startint = stoi(start);
    int end1int = stoi(end1);
    int end2int = stoi(end2);

    string time, id;
    while (cin >> time >> id)
    {
        time.erase(2, 1);
        int curtime = stoi(time);

        if (curtime <= startint)
        {
            arr[id].first = true;
        }

        else if (curtime >= end1int && curtime <= end2int)
        {
            arr[id].second = true;
        }
    }

    int ans = 0;
    for (auto &p : arr)
    {
        if (p.second.first && p.second.second)
            ans++;
    }

    cout << ans;
}
