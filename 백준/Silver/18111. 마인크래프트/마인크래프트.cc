#include <bits/stdc++.h>

using namespace std;

int timeans = INT_MAX;
int heightans = INT_MIN;
int n,m;

void func(vector<vector<int>> arr, int h, int b)
{
    int tmptime = 0;
    int curblockcount = b;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            if(h < arr[i][j])
            {
                curblockcount += arr[i][j] - h;
                tmptime += 2 * (arr[i][j] - h);
            }
            else if(h > arr[i][j])
            {
                curblockcount -= h - arr[i][j];
                tmptime += 1 * (h - arr[i][j]);
            }
        }
    }
    if(curblockcount >= 0 && timeans >= tmptime)
    {
        if(timeans == tmptime)
        {
            if(h <= heightans)
            {
                return;
            }
        }
        timeans = tmptime;
        heightans = h;
    }
    return;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    //freopen("test.txt", "rt", stdin);
    int b;
    cin >> n >> m >> b;
    int minh = INT_MAX;
    int maxh = INT_MIN;
    vector<vector<int>> arr (n,vector<int>(m));
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            cin >> arr[i][j];
            if(minh > arr[i][j])
            {
                minh = arr[i][j];
            }
            if(maxh < arr[i][j])
            {
                maxh = arr[i][j];
            }
        }
    }
    for(int idx = minh; idx <= maxh; idx++)
    {
        func(arr,idx,b);
    }
    cout << timeans << " " << heightans;
    return 0;
}
