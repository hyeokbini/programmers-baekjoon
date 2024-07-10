#include <bits/stdc++.h>

using namespace std;

int main()
{
    //freopen("test.txt", "rt", stdin);
    long long ans = 0;
    int n;
    string str;
    cin >> n >> str;
    for(int i = 0; i < n; i++)
    {
        int val = str[i] - 96;
        int tmp = 1;
        for(int j = 0; j < i; j++)
        {
            tmp *= 31;
            tmp %= 1234567891;
        }
        ans += val * tmp;
    }
    cout << ans;
    return 0;
}