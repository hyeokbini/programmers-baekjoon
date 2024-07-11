#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    //freopen("test.txt", "rt", stdin);
    unordered_set <string> arr;
    vector<string> ansstr;
    int n,m;
    int ans = 0;
    string tmp;
    cin >> n >> m;
    for(int i = 0; i < n; i++)
    {
        cin >> tmp;
        arr.insert(tmp);
    }
    for(int i = 0; i < m; i++)
    {
        cin >> tmp;
        if(arr.find(tmp) != arr.end())
        {
            ans++;
            ansstr.push_back(tmp);
        }
    }
    sort(ansstr.begin(),ansstr.end());
    cout << ans << "\n";
    for(auto i : ansstr)
    {
        cout << i << "\n";
    }
}
