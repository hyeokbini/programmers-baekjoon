#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    //freopen("test.txt", "rt", stdin);
    long long a, b, v;
    cin >> a >> b >> v;
    if ((v - a) % (a - b) != 0)
    {
        cout << (v - a) / (a - b) + 2;
    }
    else
    {
        cout << (v - a) / (a - b) + 1;
    }

    return 0;
}
