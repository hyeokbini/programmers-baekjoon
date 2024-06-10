#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    // freopen("test.txt","rt",stdin);
    int a;
    cin >> a;
    for (int i = 0; i < a; i++)
    {
        int n;
        cin >> n;                    // 8
        int checkval = (int)sqrt(n); // 2
        if (checkval * checkval == n)
        {
            cout << checkval * 4 << "\n";
        }
        else if (checkval * checkval < n && (checkval + 1) * checkval >= n)
        {
            cout << checkval * 4 + 2 << "\n";
        }
        else if ((checkval + 1) * checkval < n)
        {
            cout << checkval * 4 + 4 << "\n";
        }
    }
    return 0;
}
