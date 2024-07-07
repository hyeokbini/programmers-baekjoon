#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    //freopen("test.txt", "rt", stdin);
    int n,ans = 0;
    string tmp;
    cin >> n >> tmp;
    for(int i = 0; i < n; i++)
    {
        ans += tmp[i] - '0';
    }
    cout << ans;
    return 0;
}
