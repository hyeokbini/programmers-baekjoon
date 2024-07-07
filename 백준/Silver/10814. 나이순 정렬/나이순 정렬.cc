#include <bits/stdc++.h>

using namespace std;

bool comp(pair<int,string> pair1, pair<int,string> pair2)
{
    return pair1.first < pair2.first;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    //freopen("test.txt", "rt", stdin);
    int n;
    cin >> n;
    vector<pair<int,string>> arr(n);
    for(int i = 0; i < n; i++)
    {
        int tmp;
        string stmp;
        cin >> tmp >> stmp;
        arr[i] = make_pair(tmp,stmp);
    }
    stable_sort(arr.begin(),arr.end(),comp);
    for(auto i : arr)
    {
        cout << i.first << " " << i.second << "\n";
    }
    return 0;
}
