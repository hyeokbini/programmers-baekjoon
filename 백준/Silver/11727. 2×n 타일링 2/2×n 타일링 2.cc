#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    //freopen("test.txt", "rt", stdin);
    int n;
    cin >> n;
    vector<int> arr(n + 1);
    arr[1] = 1;
    arr[2] = 3;
    for(int i = 3; i <= n; i++)
    {
        arr[i] = (((arr[i - 2] * 2) % 10007) + (arr[i - 1] % 10007)) % 10007;
    }
    cout << arr[n];
    return 0;
}
