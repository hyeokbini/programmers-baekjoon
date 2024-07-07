#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    //freopen("test.txt", "rt", stdin);
    int n,tmp = 0;
    for(int i = 0; i < 5; i++)
    {
        cin >> n;
        tmp += n*n;
    }
    cout << tmp % 10;
    return 0;
}
