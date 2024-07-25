#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    //freopen("test.txt", "rt", stdin);
    unordered_map <string,string> arr;
    int n,m;
    cin >> n >> m;
    while(n--)
    {
        string tmp1,tmp2;
        cin >> tmp1 >> tmp2;
        arr.insert({tmp1,tmp2});
    }
    while(m--)
    {
        string val;
        cin >> val;
        cout << arr[val] << "\n";
    }
    return 0;
}
