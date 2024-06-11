#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;
    int standval = 1;
    for (int i = 2; i <= n; ++i)
    {
        standval = (standval + k - 1) % i + 1;
    }
    cout << standval;
    return 0;
}
