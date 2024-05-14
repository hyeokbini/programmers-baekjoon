#include <bits/stdc++.h>

using namespace std;

int ans[3];

void fun(vector<vector<int>> &arr, int xstart, int xend, int ystart, int yend)
{
    int comp = arr[xstart][ystart];
    bool check = true;
    for (int i = xstart; i < xend; i++)
    {
        for (int j = ystart; j < yend; j++)
        {
            if (arr[i][j] != comp)
            {
                check = false;
                break;
            }
        }
        if (check == false)
        {
            break;
        }
    }
    if (check == false)
    {
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                int new_xstart = xstart + (xend - xstart) * i / 3;
                int new_xend = xstart + (xend - xstart) * (i + 1) / 3;
                int new_ystart = ystart + (yend - ystart) * j / 3;
                int new_yend = ystart + (yend - ystart) * (j + 1) / 3;
                fun(arr, new_xstart, new_xend, new_ystart, new_yend);
            }
        }
    }
    else
    {
        ans[comp + 1]++;
        return;
    }
}

int main()
{
    int n;
    cin >> n;
    vector<vector<int>> arr(n, vector<int>(n));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> arr[i][j];
        }
    }
    fun(arr, 0, n, 0, n);
    for (auto i : ans)
    {
        cout << i << "\n";
    }
    return 0;
}