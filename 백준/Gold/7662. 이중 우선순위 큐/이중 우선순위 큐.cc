#include <bits/stdc++.h>

using namespace std;

multiset<int> arr;

void func(string s, int n)
{
    if (s == "I")
    {
        arr.insert(n);
    }
    else if (s == "D")
    {
        if (arr.empty())
        {
            return;
        }
        if (n == -1)
        {
            arr.erase(arr.begin());
        }
        else if(n == 1)
        {
            arr.erase(--arr.end());
        }
    }
    return;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    //freopen("test.txt", "rt", stdin);
    int n;
    cin >> n;
    while (n--)
    {
        int k;
        cin >> k;
        while (k--)
        {
            string com;
            int t;
            cin >> com >> t;
            func(com, t);
        }
        if(arr.empty())
        {
            cout << "EMPTY" << "\n";
        }
        else
        {
            cout  << *(--arr.end()) << " " << *arr.begin() << "\n";
        }
        arr = {};
    }
    return 0;
}