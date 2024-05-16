#include <bits/stdc++.h>

using namespace std;

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
        cout << "(";
        for (int i = 0; i < 2; i++)
        {
            for (int j = 0; j < 2; j++)
            {
                int new_xstart = xstart + (xend - xstart) * i / 2;
                int new_xend = xstart + (xend - xstart) * (i + 1) / 2;
                int new_ystart = ystart + (yend - ystart) * j / 2;
                int new_yend = ystart + (yend - ystart) * (j + 1) / 2;
                fun(arr, new_xstart, new_xend, new_ystart, new_yend);
            }
        }
        cout << ")";
    }
    else
    {
        cout << comp;
        return;
    }
}

int main()
{
    ios::sync_with_stdio(0);
	cin.tie(0);
    int n;
    cin >> n;
    vector<vector<int>> arr(n, vector<int>(n));
    for (int i = 0; i < n; i++)
    {
        string tmp;
        cin >> tmp;
        for (int j = 0; j < n; j++)
        {
            arr[i][j] = tmp[j] - '0';
        }
    }
    fun(arr, 0, n, 0, n);
    return 0;
}