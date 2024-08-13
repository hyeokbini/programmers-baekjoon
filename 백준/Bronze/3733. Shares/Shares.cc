#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    //freopen("test.txt", "rt", stdin);
    int n,m;
    while(cin >> n >> m)
    {
        cout << m / (n + 1) << "\n";
    }
    return 0;
}
