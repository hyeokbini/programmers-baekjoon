#include <bits/stdc++.h>

using namespace std;

int n;
int ans = 0;
vector<bool> col, dia1, dia2;

void check(int level)
{
    if (level == n)
    {
        ans++;
        return;
    }
    for (int i = 0; i < n; i++)
    {
        if (!col[i] && !dia1[level + i] && !dia2[level - i + n - 1])
        {
            col[i] = dia1[level + i] = dia2[level - i + n - 1] = true;
            check(level + 1);
            col[i] = dia1[level + i] = dia2[level - i + n - 1] = false;
        }
    }
    return;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    col.resize(n, false);
    dia1.resize(2 * n - 1, false);
    dia2.resize(2 * n - 1, false);
    check(0);
    cout << ans;
}
