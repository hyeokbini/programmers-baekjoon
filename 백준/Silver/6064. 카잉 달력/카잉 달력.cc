#include <bits/stdc++.h>

using namespace std;

int gcd(int a, int b)
{
    int n;
    while (b != 0)
    {
        n = a % b;
        a = b;
        b = n;
    }
    return a;
}

int main()
{
    // freopen("test.txt", "rt", stdin);
    int n;
    cin >> n;
    while (n--)
    {
        int m, n, x, y;
        cin >> m >> n >> x >> y;
        int val = m * n / gcd(m, n);
        while (1)
        {
            if ((y - 1) % m + 1 == x)
            {
                cout << y << "\n";
                break;
            }
            if (y > val)
            {
                cout << -1 << "\n";
                break;
            }
            y += n;
        }
    }
    return 0;
}
