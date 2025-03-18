#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    //freopen("test.txt", "rt", stdin);
    int n;
    long long int ans = 0;
    cin >> n;
    vector<int> arr(n + 1,-1);
    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    sort(arr.begin(),arr.end(),greater<>());
    for(int i = 0; i < n; i++)
    {
        if(arr[i] - 1 != arr[i + 1])
        {
            ans += arr[i];
        }
        else
        {
            continue;
        }
    }
    cout << ans;
    return 0;
}
