#include <bits/stdc++.h>

using namespace std;

long long ans[100];

long long func(int n)
{
    if (ans[n] != 0)
    {
        return ans[n];
    }
    return ans[n] = func(n - 1) + func(n - 5);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    // freopen("test.txt", "rt", stdin);
    ans[1] = 1;
    ans[2] = 1;
    ans[3] = 1;
    ans[4] = 2;
    ans[5] = 2;
    ans[6] = 3;
    int count, tmp;
    cin >> count;
    while (count--)
    {
        cin >> tmp;
        cout << func(tmp) << "\n";
    }
    return 0;
}
