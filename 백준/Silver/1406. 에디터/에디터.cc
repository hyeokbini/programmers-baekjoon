#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie();
    //freopen("test.txt", "rt", stdin);
    list<char> L;
    string tmp;
    cin >> tmp;
    for (auto i : tmp)
    {
        L.push_back(i);
    }
    auto cursor = L.end();
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        char command;
        cin >> command;
        if (command == 'L')
        {
            if (cursor != L.begin())
            {
                cursor--;
            }
        }
        else if (command == 'D')
        {
            if (cursor != L.end())
            {
                cursor++;
            }
        }
        else if (command == 'B')
        {
            if (cursor != L.begin())
            {
                cursor--;
                cursor = L.erase(cursor);
            }
        }
        else if (command == 'P')
        {
            char tmp;
            cin >> tmp;
            L.insert(cursor, tmp);
        }
    }
    for (auto i : L)
    {
        cout << i;
    }
    return 0;
}
