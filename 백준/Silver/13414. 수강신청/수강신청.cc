#include <bits/stdc++.h>
using namespace std;

bool comp(pair<string,int> a1, pair<string,int> a2)
{
    return a1.second < a2.second;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie();
    //freopen("test.txt", "rt", stdin);
    unordered_map<string,int> arr;
    int k,n;
    cin >> k >> n;
    for(int i = 0; i < n; i++)
    {
        string tmp;
        cin >> tmp;
        arr[tmp] = i;
    }
    vector<pair<string,int>> vec(arr.begin(),arr.end());
    sort(vec.begin(),vec.end(),comp);
    for(int i = 0; i < k && i < vec.size(); i++)
    {
        cout << vec[i].first << "\n";
    }
}
