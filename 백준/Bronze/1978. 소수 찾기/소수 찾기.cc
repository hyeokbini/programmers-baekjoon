#include <bits/stdc++.h>

using namespace std;

int ans;

void func(int n)
{
    if(n == 1)
    {
        return;
    }
    for(int i = 2; i < n; i++)
    {
        if(n % i == 0)
        {
            return;
        }
    }
    ans++;
    return;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    //freopen("test.txt", "rt", stdin);
    int n,tmp;
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        cin >> tmp;
        func(tmp);
    }
    cout << ans;
    return 0;
}
