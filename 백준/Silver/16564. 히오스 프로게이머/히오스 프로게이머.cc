#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    //freopen("test.txt", "rt", stdin);
    int n, k;
    cin >> n >> k;
    vector<int> arr(n);
    int ans = 0;
    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    sort(arr.begin(),arr.end());
    int curstandidx = 0;
    while(1)
    {
        if(curstandidx < n && arr[curstandidx] == arr[curstandidx + 1])
        {
            curstandidx++;
            continue;
        }
        if(k - (curstandidx + 1) < 0)
        {
            ans = arr[curstandidx];
            break;
        }
        k -= curstandidx + 1;
        arr[curstandidx]++;
    }
    cout << ans;
    return 0;
}
