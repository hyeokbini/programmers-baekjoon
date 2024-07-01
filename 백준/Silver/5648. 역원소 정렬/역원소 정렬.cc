#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    //freopen("test.txt", "rt", stdin);
    int n;
    string tmp;
    cin >> n;
    vector<long long int> arr;
    for(int i = 0; i < n; i++)
    {
        cin >> tmp;
        reverse(tmp.begin(),tmp.end());
        arr.push_back(stoll(tmp));
    }
    sort(arr.begin(),arr.end());
    for(int i = 0; i < n; i++)
    {
        cout << arr[i] << "\n";
    }
    return 0;
}
