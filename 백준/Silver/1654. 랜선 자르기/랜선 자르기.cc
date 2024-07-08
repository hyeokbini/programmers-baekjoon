#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    //freopen("test.txt", "rt", stdin);
    int k, n;
    cin >> k >> n;
    vector<int> arr(k);
    for (int i = 0; i < k; i++)
    {
        cin >> arr[i];
    }
    sort(arr.begin(), arr.end());
    long long start = 1;
    long long end = arr.back();
    while (start <= end)
    {
        long long stand = (start + end) / 2;
        int val = 0;
        for (int i = 0; i < k; i++)
        {
            val += arr[i] / stand;
        }

        if(val < n)
        {
            end = stand - 1;
        }
        else
        {
            start = stand + 1;
        }
    }
    cout << end;
    return 0;
}
