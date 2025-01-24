#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    //freopen("test.txt", "rt", stdin);
    int n;
    cin >> n;
    long long int sumval = 0;
    vector<pair<int,int>> arr(n,{0,0});
    for(int i = 0; i < n; i++)
    {
        int x, a;
        cin >> x >> a;
        arr[i].first = x;
        arr[i].second = a;
        sumval += a;
    }
    sort(arr.begin(),arr.end());
    long long int stand = 0;
    for(int i = 0; i < n; i++)
    {
        stand += arr[i].second;
        if(stand >= (double)sumval / 2)
        {
            cout << arr[i].first;
            break;
        }
    }
    return 0;
}