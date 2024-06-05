#include <bits/stdc++.h>

using namespace std;

int n;
int ans = INT_MAX;

void func(vector<vector<int>> arr, int idx, int count, vector<bool> team)
{
    if (count == n / 2)
    {
        int teamt = 0;
        int teamf = 0;
        for (int i = 0; i < n; i++)
        {
            if (team[i])
            {
                for (int j = 0; j < n; j++)
                {
                    if (team[j])
                    {
                        teamt += arr[i][j];
                    }
                }
            }
            else
            {
                for (int j = 0; j < n; j++)
                {
                    if (!team[j])
                    {
                        teamf += arr[i][j];
                    }
                }
            }
        }
        ans = min(ans, abs(teamt - teamf));
        return;
    }
    for (int i = idx; i < n; i++)
    {
        if (team[i])
        {
            continue;
        }
        else
        {
            team[i] = true;
            func(arr, i, count + 1, team);
            team[i] = false;
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    vector<vector<int>> arr(n, vector<int>(n));
    vector<bool> team(n, false);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> arr[i][j];
        }
    }
    func(arr,0, 0, team);
    cout << ans;
}