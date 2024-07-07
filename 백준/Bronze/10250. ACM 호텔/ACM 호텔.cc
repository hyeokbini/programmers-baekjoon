#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    //freopen("test.txt", "rt", stdin);
    int n;
    cin >> n;
    while (n--)
    {
        int h, w, n;
        cin >> h >> w >> n;
        int val1 = n % h;
        int val2 = n / h;
        if (!val1)
        {
            cout << h * 100 + (n / h);
        }
        else
        {
            cout << (n % h) * 100 + (n / h) + 1;
        }
        cout << "\n";
    }
    return 0;
}
