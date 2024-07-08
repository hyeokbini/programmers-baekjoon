#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    // freopen("test.txt", "rt", stdin);

    int start = 666;
    int idx = 1;
    int n;
    cin >> n;
    while (idx != n)
    {
        start++;
        if (to_string(start).find("666") != string::npos)
        {
            idx++;
            if (idx == n)
            {
                break;
            }
        };
    }
    cout << start;

    return 0;
}
