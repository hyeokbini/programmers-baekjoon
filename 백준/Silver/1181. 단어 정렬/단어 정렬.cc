#include <bits/stdc++.h>

using namespace std;

bool lengthsort(string str1, string str2)
{
    if(str1.length() < str2.length())
    {
        return str1.length() < str2.length();
    }
    else if(str1.length() == str2.length())
    {
        return str1 < str2;
    }
    else
    {
        return false;
    }
}

int main()
{
    //freopen("test.txt", "rt", stdin);
    int n;
    cin >> n;
    vector<string> arr(n);
    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    sort(arr.begin(), arr.end(), lengthsort);
    arr.erase(unique(arr.begin(),arr.end()),arr.end());
    for(int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << "\n";
    }
    return 0;
}
