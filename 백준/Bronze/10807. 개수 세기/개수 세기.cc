#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    //freopen("test.txt", "rt", stdin);
    int n;
    cin >> n;
    unordered_map<int,int> arr;
    while(n--)
    {
        int a;
        cin >> a;
        if(arr.find(a) != arr.end())
        {
            arr[a]++;
        }
        else
        {
            arr.insert({a,1});
        }
    }
    int findval;
    cin >> findval;
    cout << arr[findval];
    return 0;
}
