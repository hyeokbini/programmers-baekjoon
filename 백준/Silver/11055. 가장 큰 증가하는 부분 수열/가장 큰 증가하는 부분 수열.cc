#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    //freopen("test.txt", "rt", stdin);
    int n,ans = 0;
    cin >> n;
    vector<int> arr(n + 1,0);
    vector<int> sumdp(n + 1,0);
    for(int i = 1; i <= n; i++)
    {
        cin >> arr[i];
    }
    for(int i = 0; i <= n; i++)
    {
        for(int j = 0; j <= i; j++)
        {
            if(arr[i] > arr[j])
            {
                sumdp[i] = max(sumdp[i],sumdp[j] + arr[i]);
            }
        }
        ans = max(sumdp[i],ans);
    }
    cout << ans;
}