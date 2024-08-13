#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    //freopen("test.txt", "rt", stdin);
    int n, limit, cur = 0,tmp;
    cin >> n >> limit;
    for(int i = 0; i < n; i++)
    {
        cin >> tmp;
        if(cur + tmp > limit)
        {
            cout << i;
            return 0;
        }
        cur += tmp;
    }
    cout << n;
    return 0;
}
