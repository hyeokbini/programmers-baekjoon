#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    //freopen("test.txt", "rt", stdin);
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    sort(arr.begin(),arr.end());
    int start = 0;
    int end = n - 1;
    int curval = abs(arr[start] + arr[end]);
    int ansstart = 0;
    int ansend = n - 1;
    while(start < end)
    {
        int sum = arr[start] + arr[end];
        if(abs(sum) < curval)
        {
            curval = abs(sum);
            ansstart = start;
            ansend = end;
        }
        if(sum < 0)
        {
            start++;
        }
        else if(sum > 0)
        {
            end--;
        }
        else
        {
            break;
        }
    }
    cout << arr[ansstart] << " " << arr[ansend];
    return 0;
}