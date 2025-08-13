#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    //freopen("test.txt", "rt", stdin);
    int n, m;
    cin >> n >> m;
    vector<int> arr(n);
    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
        
    int sum = 0;
    for(int i = 0; i < m; i++)
    {
        sum += arr[i];
    }
        
    int ans = sum;

    for(int i = m; i < n; i++)
    {
        sum = sum - arr[i - m] + arr[i];
        ans = max(ans, sum);
    }

    cout << ans;
    return 0;
}
