#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    //freopen("test.txt", "rt", stdin);
    int stand, comp = 0;
    cin >> stand;
    int n;
    cin >> n;
    while(n--)
    {
        int a,b;
        cin >> a >> b;
        comp += a * b;
    }
    cout << ((stand == comp) ? "Yes" : "No");
    return 0;
}
