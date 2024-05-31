#include <bits/stdc++.h>

using namespace std;

int n;
int ans = 0;

void func(vector<vector<int>> arr, int curhandidx, int count)
{
    if (curhandidx == arr.size())
    {
        ans = max(ans, count);
        return;
    }
    if (arr[curhandidx][0] <= 0)
    {
        func(arr, curhandidx + 1, count);
        return;
    }
    bool check = false;
    for (int i = 0; i < arr.size(); i++) 
    {
        if (i == curhandidx || arr[i][0] <= 0) 
        {
            continue;
        }
        check = true;
        arr[curhandidx][0] -= arr[i][1];
        arr[i][0] -= arr[curhandidx][1];
        int breakcount = 0;
        if (arr[curhandidx][0] <= 0) breakcount++;
        if (arr[i][0] <= 0) breakcount++;

        func(arr,curhandidx + 1, count + breakcount);

        arr[curhandidx][0] += arr[i][1];
        arr[i][0] += arr[curhandidx][1];
    }
    if (!check)
    {
        func(arr, curhandidx + 1, count);
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    vector<vector<int>> arr(n, vector<int>(2, 0));
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i][0] >> arr[i][1];
    }
    func(arr, 0, 0);
    cout << ans;
}