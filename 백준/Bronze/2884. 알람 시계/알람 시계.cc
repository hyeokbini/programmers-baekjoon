#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    //freopen("test.txt", "rt", stdin);
    int n,m;
    cin >> n >> m;
    if(m < 45)
    {
        m += 15;
        n--;
    }
    else
    {
        m -= 45;
    }
    if(n < 0)
    {
        n += 24;
    }
    cout << n << " " << m;
    return 0;
}
