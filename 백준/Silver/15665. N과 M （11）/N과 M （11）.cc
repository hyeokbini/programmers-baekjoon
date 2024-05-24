#include <bits/stdc++.h>

using namespace std;

int n, m;
vector<int> arr;
int ans[10];
bool visited[10];

void func(int cur)
{
    if (cur == m)
    {
        for (int i = 0; i < m; i++)
        {
            cout << ans[i] << " ";
        }
        cout << "\n";
        return;
    }
    int last = 0;
    for (int i = 0; i < n; i++)
    {
        if (last != arr[i])
        {
            last = arr[i];
            ans[cur] = arr[i];
            func(cur + 1);
        }
    }
}

    int main()
    {
        cin >> n >> m;
        int tmp;
        for (int i = 0; i < n; i++)
        {
            cin >> tmp;
            arr.push_back(tmp);
        }
        sort(arr.begin(), arr.end());
        func(0);
    }
