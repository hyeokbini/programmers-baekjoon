#include <bits/stdc++.h>

using namespace std;

int main()
{
    //freopen("test.txt", "rt", stdin);
    int n = 0;
    cin >> n;
    if(n == 0)
    {
        cout << 0;
        return 0;
    }
    vector<int> arr(n);
    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    sort(arr.begin(),arr.end());
    int cancle = floor((double)n * 0.15 + 0.5);
    double sumval = 0;
    for(int i = cancle; i < n - cancle; i++)
    {
        sumval += arr[i];
    }
    double ans = sumval / (n - cancle * 2);
    cout << floor(ans + 0.5);
    return 0;
}