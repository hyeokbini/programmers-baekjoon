#include <bits/stdc++.h>

using namespace std;

int main()
{
    //freopen("test.txt", "rt", stdin);
    int t;
    cin >> t;
    while (t--)
    {
        double x1, y1, r1, x2, y2, r2;
        cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;
        double d = sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
        
        if (x1 == x2 && y1 == y2)
        {
            if (r1 == r2)
            {
                cout << -1 << "\n";
            }
            else
            {
                cout << 0 << "\n";
            }
        }
        else
        {
            if (d > r1 + r2 || d < fabs(r1 - r2))
            {
                cout << 0 << "\n";
            }
            else if (d == r1 + r2 || d == fabs(r1 - r2))
            {
                cout << 1 << "\n";
            }
            else
            {
                cout << 2 << "\n";
            }
        }
    }
    return 0;
}
