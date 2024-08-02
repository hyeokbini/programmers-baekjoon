#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    //freopen("test.txt", "rt", stdin);
    int n, m;
    cin >> n;
    vector<int> wei(n);
    for (int i = 0; i < n; i++)
    {
        cin >> wei[i];
    }
    cin >> m;
    vector<int> box(m);
    for (int i = 0; i < m; i++)
    {
        cin >> box[i];
    }
    sort(wei.begin(), wei.end(), greater<>());
    sort(box.begin(), box.end(), greater<>());
    if (wei[0] < box[0])
    {
        cout << -1;
        return 0;
    }
    int craincount = wei.size();
    int boxcount = box.size();
    int ans = 0;
    while (1)
    {

        if (box[0] <= 0)
        {
            cout << ans;
            return 0;
        }
        int usecrainidx = 0;

        for (int targetboxidx = 0; targetboxidx < boxcount; targetboxidx++)
        {
            if (usecrainidx >= craincount)
            {
                break;
            }
            if (wei[usecrainidx] >= box[targetboxidx])
            {
                box[targetboxidx] -= wei[usecrainidx];
                usecrainidx++;
            }
        }

        sort(box.begin(), box.end(), greater<>());
        ans++;
    }
}