#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    // freopen("test.txt", "rt", stdin);
    int n, tmp;
    string com;
    set<int> arr;
    set<int> tmparr;
    for (int i = 1; i <= 20; i++)
    {
        tmparr.insert(i);
    }
    cin >> n;
    while (n--)
    {
        cin >> com;
        if (com == "add")
        {
            cin >> tmp;
            arr.insert(tmp);
        }
        else if (com == "remove")
        {
            cin >> tmp;
            if (arr.find(tmp) != arr.end())
            {
                arr.erase(tmp);
            }
        }
        else if (com == "check")
        {
            cin >> tmp;
            if (arr.find(tmp) != arr.end())
            {
                cout << "1\n";
            }
            else
            {
                cout << "0\n";
            }
        }
        else if (com == "toggle")
        {
            cin >> tmp;
            if (arr.find(tmp) != arr.end())
            {
                arr.erase(tmp);
            }
            else
            {
                arr.insert(tmp);
            }
        }
        else if (com == "all")
        {
            arr = tmparr;
        }
        else if (com == "empty")
        {
            arr = {};
        }
    }
    return 0;
}