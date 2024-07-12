#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    //freopen("test.txt", "rt", stdin);
    int n;
    cin >> n;
    vector<int>arr(n);
    vector<int>coparr(n);
    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
        coparr[i] = arr[i];
    }
    sort(coparr.begin(),coparr.end());
    coparr.erase(unique(coparr.begin(),coparr.end()),coparr.end());
    unordered_map <int,int> tmpmap;
    for(int i = 0; i < coparr.size(); i++)
    {
        tmpmap.insert({coparr[i],i});
    }
    for(int i = 0; i < n; i++)
    {
        arr[i] = tmpmap[arr[i]];
    }
    for(auto i : arr)
    {
        cout << i << " ";
    }
    return 0;
}