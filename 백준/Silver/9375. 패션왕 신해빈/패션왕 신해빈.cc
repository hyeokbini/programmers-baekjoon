#include <bits/stdc++.h>

using namespace std;

int main()
{
    //freopen("test.txt", "rt", stdin);
    int t;
    cin >> t;
    while (t--)
    {
        int ans = 1;
        int n;
        cin >> n;
        unordered_map<string, int> arr;
        string tmp, val;
        while (n--)
        {
            cin >> tmp >> val;
            if (arr.find(val) == arr.end())
            {
                arr.insert({val, 1});
            }
            else
            {
                arr[val]++;
            }
        }
        for (auto i = arr.begin(); i != arr.end(); i++)
        {
            ans *= i->second + 1;
        }
        ans--;
        cout << ans << "\n";
    }
    return 0;
}