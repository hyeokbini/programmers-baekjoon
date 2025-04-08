#include <bits/stdc++.h>

using namespace std;

bool comp(string a, string b)
{
    return a.length() < b.length();
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    //freopen("test.txt", "rt", stdin);
    int n;
    int ans = 0;
    cin >> n;
    vector<string> arr(n);
    vector<bool> check(n, true);
    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    sort(arr.begin(), arr.end(), comp);
    for(int i = 0; i < n; i++)
    {
        string cur = arr[i];
        int curlen = cur.length();
        for(int j = i + 1; j < n; j++)
        {
            if(arr[j].substr(0,curlen) == cur)
            {
                check[i] = false;
                break;
            }
        }
    }
    for(auto i : check)
    {
        if(i)
        {
            ans++;
        }
    }
    cout << ans;
}