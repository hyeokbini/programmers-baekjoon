#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    //freopen("test.txt", "rt", stdin);
    int n,k,ans=0;
    cin >> n >> k;
    vector<int> arr(n);
    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    for(int i = 0; i <= n - k; i++)
    {
        int minval = arr[i];
        int minidx = i;
        for(int j = i; j < i + k; j++)
        {
            if(arr[j] < minval)
            {
                minval = arr[j];
                minidx = j;
            }
        }
        ans = max(minval,ans);
        i = minidx;
    }
    cout << ans;
}