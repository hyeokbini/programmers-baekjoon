#include <bits/stdc++.h>

using namespace std;

vector<int> val;
vector<int> cnt;

void func(int idx)
{
    if(cnt[idx] < val[idx])
    {
        cout << cnt[idx] << " ";
        return;
    }
    else if(cnt[idx] % val[idx] == 0)
    {
        cout << cnt[idx] - (cnt[idx] / val[idx] - 1) << " ";
        return;
    }
    else
    {
        cout << cnt[idx] - (cnt[idx] / val[idx]) << " ";
        return;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    //freopen("test.txt", "rt", stdin);
    int n;
    cin >> n;
    val.resize(n);
    cnt.resize(n);
    for(int i = 0; i < n; i++)
    {
        cin >> val[i];
    }
    for(int i = 0; i < n; i++)
    {
        cin >> cnt[i];
    }
    for(int i = 0; i < n; i++)
    {
        func(i);
    }
    return 0;
}