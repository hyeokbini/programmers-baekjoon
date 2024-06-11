#include <bits/stdc++.h>

using namespace std;

vector<int> arr;
vector<int> findval;

void func(int val, int start, int end)
{
    int stand = (start + end) / 2;
    if (start > end)
    {
        cout << "0\n";
        return;
    }
    if (arr[stand] == val)
    {
        cout << "1\n";
        return;
    }
    else if (val > arr[stand])
    {
        func(val, stand + 1, end);
    }
    else
    {
        func(val, start, stand - 1);
    }
}

int main()
{
    // freopen("test.txt", "rt", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n;
    arr.resize(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    sort(arr.begin(), arr.end());
    cin >> m;
    for (int i = 0; i < m; i++)
    {
        int tmp;
        cin >> tmp;
        func(tmp, 0, n - 1);
    }
    return 0;
}
