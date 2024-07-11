#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    //freopen("test.txt", "rt", stdin);
    int n, ans = 0;
    cin >> n;
    vector<int> arr(n);
    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    sort(arr.begin(), arr.end());
    for(int i = n; i > 0; i--)
    {
        ans += arr[n - i] * i;
    }
    cout << ans;
    return 0;
}
