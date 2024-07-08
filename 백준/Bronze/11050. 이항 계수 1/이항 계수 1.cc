#include <bits/stdc++.h>

using namespace std;

int func(int n)
{
    int val = 1;
    for(int i = 1; i <= n; i++)
    {
        val *= i;
    }
    return val;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    //freopen("test.txt", "rt", stdin);
    int n,k;
    cin >> n >> k;
    cout << func(n) / (func(k) * func(n - k));
    return 0;
}
