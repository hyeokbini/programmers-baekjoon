#include <bits/stdc++.h>

using namespace std;

vector<string> arr;

bool comp(string a, string b)
{
    if (a == b)
    {
        return false;
    }
    if (a.length() == b.length())
    {
        return a >= b;
    }
    else
    {
        string original_a = a;
        string original_b = b;

        while (a.length() != b.length())
        {
            while (a.length() < b.length())
            {
                a += original_a;
            }
            while (b.length() < a.length())
            {
                b += original_b;
            }
        }

        return a >= b;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    //freopen("test.txt", "rt", stdin);
    int n;
    string tmp;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> tmp;
        arr.push_back(tmp);
    }
    sort(arr.begin(), arr.end(), comp);
    if (arr[0] == "0")
    {
        cout << 0;
        return 0;
    }
    for (auto i : arr)
    {
        cout << i;
    }
    return 0;
}
