#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie();
    //freopen("test.txt", "rt", stdin);
    vector<vector<double>> arr(2,vector<double>(6,0));
    int n;
    int k;
    int ans = 0;
    cin >> n >> k;
    for(int i = 0; i < n; i++)
    {
        int s;
        int g;
        cin >> s >> g;
        arr[s][g - 1]++;
    }
    for(int i = 0; i < 2; i++)
    {
        for(int j = 0; j < 6; j++)
        {
            ans += ceil(arr[i][j] / k);
        }
    }
    cout << ans;
}
