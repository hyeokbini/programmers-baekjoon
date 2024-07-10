#include <bits/stdc++.h>

using namespace std;

int main()
{
    // freopen("test.txt", "rt", stdin);
    int n;
    cin >> n;
    if (n == 2)
    {
        cout << 1;
        return 0;
    }
    else if (n == 4)
    {
        cout << 2;
        return 0;
    }
    else if (n == 6)
    {
        cout << 3;
        return 0;
    }
    else if (n == 8)
    {
        cout << 4;
        return 0;
    }
    int cur = 1;
    while (1)
    {
        int tmpcur = cur;
        int tmp = 0;
        while (tmpcur > 0)
        {
            tmp += tmpcur % 10;
            tmpcur /= 10;
        }
        if (cur + tmp == n)
        {
            cout << cur;
            return 0;
        }
        cur++;
        if (cur > n)
        {
            cout << 0;
            return 0;
        }
    }
}