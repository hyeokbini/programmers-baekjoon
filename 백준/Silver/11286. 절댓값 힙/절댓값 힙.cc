#include <bits/stdc++.h>

using namespace std;

struct compare
{
    bool operator()(int a, int b) const
    {
        if (abs(a) == abs(b))
        {
            return a < b;
        }
        return abs(a) < abs(b);
    }
};

multiset<int, compare> arr;

void func(int n)
{
    if (n)
    {
        arr.insert(n);
    }
    else
    {
        if (arr.empty())
        {
            cout << 0 << "\n";
            return;
        }
        cout << *arr.begin() << "\n";
        arr.erase(arr.begin());
    }
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
        int t;
        cin >> t;
        func(t);
    }
    return 0;
}
