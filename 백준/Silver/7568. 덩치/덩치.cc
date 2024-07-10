#include <bits/stdc++.h>

using namespace std;

int main()
{
    //freopen("test.txt", "rt", stdin);
    int n;
    cin >> n;
    vector<vector<int>> arr(n,vector<int>(3,1));
    for(int i = 0; i < n; i++)
    {
        cin >> arr[i][0] >> arr[i][1];
    }
    for(int i = 0; i < n ;i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(i == j)
            {
                continue;
            }
            if(arr[i][0] < arr[j][0] && arr[i][1] < arr[j][1])
            {
                arr[i][2]++;
            }
        }
    }
    for(auto i : arr)
    {
        cout << i[2] << " ";
    }
    return 0;
}