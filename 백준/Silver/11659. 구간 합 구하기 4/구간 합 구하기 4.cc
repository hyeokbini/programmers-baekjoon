#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    //freopen("test.txt", "rt", stdin);
    int n, m, tmp;
    cin >> n >> m;
    vector<int> arr(n + 1,0);
    for (int i = 1; i < n + 1; i++)
    {
        cin >> tmp;
        arr[i] = tmp + arr[i - 1];
    }
    while(m--)
    {
        int i,j;
        cin >> i >> j;
        cout << arr[j] - arr[i - 1] << "\n";
    }
    return 0;
}
