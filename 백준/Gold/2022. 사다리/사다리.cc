#include <bits/stdc++.h>

using namespace std;

double x, y, c;

bool check(double d)
{
    double h1 = sqrt(x * x - d * d);
    double h2 = sqrt(y * y - d * d);

    double cal = (h1 * h2) / (h1 + h2);

    return cal >= c;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    //freopen("test.txt", "rt", stdin);
    cin >> x >> y >> c;
    if (x < y)
    {
        swap(x, y);
    }
    double low = 0, high = min(x, y);
    double mid;
    double epsilon = 1e-3;
    while (high - low > epsilon)
    {
        mid = (low + high) / 2;
        if (check(mid))
        {
            low = mid;
        }
        else
        {
            high = mid;
        }
    }
    cout << mid;
    return 0;
}