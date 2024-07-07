#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    //freopen("test.txt", "rt", stdin);
    vector<bool> rem(42,false);
    int tmp,ans = 0;
    for(int i = 0; i < 10; i++)
    {
        cin >> tmp;
        if(!rem[tmp % 42])
        {
            ans++;
            rem[tmp % 42] = true;
        }
    }
    cout << ans;
    return 0;
}
