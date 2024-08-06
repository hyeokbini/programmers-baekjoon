#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    // freopen("test.txt", "rt", stdin);
    long long int n;
    long long int ans = 0;
    cin >> n;
    n /= 2;
    long long int compn = n * n;
    long double preval = n;
    long double conval;
    for (long double i = 1; i <= n; i++)
    {
        conval = (long double)sqrt(compn - i * i);
        if (preval - (long long int)preval == 0)
        {
            ans += (long long int)preval - (long long int)conval;
        }
        else
        {
            ans += (long long int)preval - (long long int)conval + 1;
        }
        preval = conval;
    }
    cout << ans * 4;
    return 0;
}
