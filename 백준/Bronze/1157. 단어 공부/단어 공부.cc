#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    //freopen("test.txt", "rt", stdin);
    string str;
    cin >> str;
    vector<int> arr(26,0);
    int maxval = 0;
    char maxchar;
    for(int i = 0; i < str.length(); i++)
    {
        arr[toupper(str[i]) - 'A']++;
    }
    for(int i = 0; i < 26; i++)
    {
        maxval = max(arr[i],maxval);
    }
    int maxcount = 0;
    for(int i = 0; i < 26; i++)
    {
        if(arr[i] == maxval)
        {
            maxcount++;
            maxchar = i + 'A';
        }
    }
    if(maxcount > 1)
    {
        cout << "?";
    }
    else
    {
        cout << maxchar;
    }
    return 0;
}
