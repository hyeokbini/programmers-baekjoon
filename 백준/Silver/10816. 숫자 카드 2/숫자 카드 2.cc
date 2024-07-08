#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    //freopen("test.txt", "rt", stdin);
    int n;
    cin >> n;
    unordered_map <int,int> arr;
    for(int i = 0; i < n; i++)
    {
        int tmp;
        cin >> tmp;
        if(arr.find(tmp) == arr.end())
        {
            arr.insert({tmp,1});
        }
        else
        {
            arr[tmp]++;
        }
    }
    int m;
    cin >> m;
    for(int i = 0; i < m; i++)
    {
        int tmp;
        cin >> tmp;
        if(arr.find(tmp) != arr.end())
        {
            cout << arr[tmp] << " ";
        }
        else
        {
            cout << 0 << " ";
        }
    }
    return 0;
}
