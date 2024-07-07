#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    // freopen("test.txt", "rt", stdin);
    int a, b;
    while (1)
    {
        cin >> a >> b;
        if(!(a || b))
        {
            break;
        }
        cout << a + b << "\n";
    }
    return 0;
}
