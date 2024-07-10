#include <bits/stdc++.h>

using namespace std;

int main()
{
    //freopen("test.txt", "rt", stdin);
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        int curidx = 0;
        int count = 1;
        vector<int> priorities(n);
        for(int i = 0; i < n; i++)
        {
            cin >> priorities[i];
        }
        vector<bool> check(n, false);
        while (1)
        {
            while (check[curidx])
            {
                curidx++;
                curidx %= n;
            }
            int tmp = priorities[curidx];
            int tmpidx = curidx;
            for (int j = 0; j < n; j++)
            {
                int i = (j + curidx) % n;
                if (!check[i] && priorities[i] > tmp)
                {
                    tmp = priorities[i];
                    tmpidx = i;
                }
            }
            curidx = tmpidx;
            check[curidx] = true;
            if (curidx == m)
            {
                break;
            }
            count++;
            curidx++;
            curidx %= n;
        }
        cout << count << "\n";
    }
    return 0;
}