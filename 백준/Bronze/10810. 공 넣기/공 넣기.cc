#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    //freopen("test.txt", "rt", stdin);
    int n,m;
    cin >> n >> m;
    vector<int> arr(n);
    for(auto i : arr)
    {
        i = 0;
    }
    while(m--)
    {
        int a,b,c;
        cin >> a >> b >> c;
        for(int i = a; i <= b; i++)
        {
            arr[i - 1] = c;
        }
    }
    for(auto i : arr)
    {
        cout << i << " ";
    }
    return 0;
}
