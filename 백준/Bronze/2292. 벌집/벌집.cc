#include <bits/stdc++.h>

using namespace std;

int main()
{
    // freopen("test.txt", "rt", stdin);
    int tmpsum = 1;
    int ans = 1;
    int n;
    cin >> n;
    while(1)
    {
        if(tmpsum >= n)
        {
            cout << ans;
            return 0;
        }
        tmpsum += ans * 6;
        ans++;
    }
}