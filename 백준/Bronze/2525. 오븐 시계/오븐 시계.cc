#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    //freopen("test.txt", "rt", stdin);
    int n,m,pl;
    cin >> n >> m >> pl;
    int hour = n;
    int min = m + pl;
    if(min < 60)
    {
        cout << hour << " " << min;
    }
    else
    {
        hour += (min / 60);
        cout << hour % 24 << " " << min % 60;
    }
    return 0;
}
