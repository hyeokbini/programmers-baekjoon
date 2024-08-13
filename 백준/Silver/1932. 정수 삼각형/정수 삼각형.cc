#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    //freopen("test.txt", "rt", stdin);
    int n;
    cin >> n;
    vector<vector<int>> triangle(n,vector<int>(n));
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j <= i; j++)
        {
            cin >> triangle[i][j];
        }
    }
    for(int i = n - 1; i >= 0; i--)
    {
        for(int j = i; j > 0; j--)
        {
            triangle[i - 1][j - 1] += max(triangle[i][j - 1],triangle[i][j]);
        }
    }
    cout << triangle[0][0];
    return 0;
}
