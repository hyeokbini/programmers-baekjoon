#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    //freopen("test.txt", "rt", stdin);
    int tmp;
    bool as = true;
    bool de = true;
    for(int i = 1; i <= 8; i++)
    {
        cin >> tmp;
        if(tmp != i)
        {
            as = false;
        }
        if(9 - tmp != i)
        {
            de = false;
        }
    }
    if(as)
    {
        cout << "ascending";
    }
    else if(de)
    {
        cout << "descending";
    }
    else
    {
        cout << "mixed";
    }
}
