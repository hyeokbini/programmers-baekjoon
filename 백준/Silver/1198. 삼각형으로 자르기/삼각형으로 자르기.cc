#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    //freopen("test.txt", "rt", stdin);
    int n;
    int ans = 0;
    cin >> n;
    vector<pair<int,int>> dot(n);
    for(int i = 0; i < n; i++)
    {
        int a,b;
        cin >> a >> b;
        dot[i] = make_pair(a,b);
    }
    for(int i = 0; i < n - 2; i++)
    {
        for(int j = 1; j < n - 1; j++)
        {
            for(int k = 2; k < n; k++)
            {
                int x1 = dot[i].first;
                int y1 = dot[i].second;
                int x2 = dot[j].first;
                int y2 = dot[j].second;
                int x3 = dot[k].first;
                int y3 = dot[k].second;

                int area = abs(x1 * y2 + x2 * y3 + x3 * y1 - x2 * y1 - x3 * y2 - x1 * y3);
                ans = max(ans,area);
            }
        }
    }
    if (ans % 2 == 0)
    {
        cout << ans / 2 << ".0";
    }
    else
    {
        cout << ans / 2 << ".5";
    }
    return 0;
}
