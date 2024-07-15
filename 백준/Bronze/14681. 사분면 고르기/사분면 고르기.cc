#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    //freopen("test.txt", "rt", stdin);
    int n,m;
    cin >> n >> m;
    if(n > 0 && m > 0)
    {
        cout << 1;
    }
    else if(n < 0 && m > 0)
    {
        cout << 2;
    }
    else if(n < 0 && m < 0)
    {
        cout << 3;
    }
    else
    {
        cout << 4;
    }
    return 0;
}
