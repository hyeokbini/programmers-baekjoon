#include <bits/stdc++.h>

using namespace std;

int main()
{
    // freopen("test.txt", "rt", stdin);
    int n;
    double tmp = 0;
    cin >> n;
    vector<int> arr(n);
    unordered_map<int, int> fre;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        tmp += arr[i];
        fre[arr[i]]++;
    }
    sort(arr.begin(), arr.end());
    cout << floor((tmp / n) + 0.5) << "\n";
    cout << arr[n / 2] << "\n";
    int maxFreq = 0;
    vector<int> modes;
    for (auto& [key, value] : fre)
    {
        if (value > maxFreq)
        {
            maxFreq = value;
            modes = { key };
        }
        else if (value == maxFreq)
        {
            modes.push_back(key);
        }
    }
    sort(modes.begin(), modes.end());
    if (modes.size() > 1)
    {
        cout << modes[1] << "\n";
    }
    else
    {
        cout << modes[0] << "\n";
    }
    cout << arr.back() - arr[0] << "\n";

    return 0;
}