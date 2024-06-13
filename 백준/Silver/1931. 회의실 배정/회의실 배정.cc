#include <bits/stdc++.h>

using namespace std;

bool comp(vector<int> arr1, vector<int> arr2)
{
    if(arr1[1] == arr2[1])
    {
        return arr1[0] < arr2[0];
    }
    return arr1[1] < arr2[1];
}

int main()
{
    //freopen("test.txt","rt",stdin);
    
    int ans = 0;
    int n;
    cin >> n;
    vector<vector<int>> arr(n,vector<int>(2));
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < 2; j++)
        {
            cin >> arr[i][j];
        }
    }
    sort(arr.begin(),arr.end(),comp);
    int starttime = arr[0][0];
    for(int i = 0; i < n; i++)
    {
        if(arr[i][0] >= starttime)
        {
            starttime = arr[i][1];
            ans++;
        }
    }
    cout << ans;
    return 0;
}