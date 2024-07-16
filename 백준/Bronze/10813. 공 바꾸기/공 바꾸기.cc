#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    //freopen("test.txt", "rt", stdin);
    int n,m;
    cin >> n >> m;
    vector<int>arr(n);
    for(int i = 1; i <= n; i++)
    {
        arr[i - 1] = i;
    }
    while(m--)
    {
        int a,b;
        cin >> a >> b;
        swap(arr[a - 1],arr[b - 1]);
    }
    for(auto i : arr)
    {
        cout << i << " ";
    }
    return 0;
}
