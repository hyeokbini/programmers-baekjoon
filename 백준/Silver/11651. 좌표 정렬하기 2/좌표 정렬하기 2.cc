#include <bits/stdc++.h>

using namespace std;

bool comp(vector<int> arr1, vector<int> arr2)
{
    if (arr1[1] < arr2[1])
    {
        return arr1[1] < arr2[1];
    }
    else if (arr1[1] == arr2[1])
    {
        return arr1[0] < arr2[0];
    }
    else
    {
        return false;
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    //freopen("test.txt","rt",stdin);
    int n;
    cin >> n;
    vector<vector<int>> arr(n, vector<int>(2));
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i][0] >> arr[i][1];
    }
    sort(arr.begin(), arr.end(), comp);
    for (int i = 0; i < n; i++)
    {
        cout << arr[i][0] << " " << arr[i][1] << "\n";
    }
    return 0;
}
