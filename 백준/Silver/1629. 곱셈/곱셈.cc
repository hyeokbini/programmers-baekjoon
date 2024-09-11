#include <bits/stdc++.h>

using namespace std;

long long int a,b,c;

long long int func(int val)
{
    if(val == 1)
    {
        return a % c;
    }

    long long int tmpval = func(val / 2);

    if(val % 2 == 0)
    {
        return tmpval * tmpval % c;
    }
    else
    {
        return tmpval * tmpval % c * a % c;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    //freopen("test.txt", "rt", stdin);
    cin >> a >> b >> c;
    cout << func(b);
    return 0;
}