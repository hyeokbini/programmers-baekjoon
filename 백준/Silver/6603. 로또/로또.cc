#include <bits/stdc++.h>

using namespace std;

int n;
vector<int> arr;
int ans[20];
bool visited[20];

void func(int cur)
{
    if (cur == 6)
    {
        for (int i = 0; i < 6; i++)
        {
            cout << ans[i] << " ";
        }
        cout << "\n";
        return;
    }
    for (int i = 0; i < n; i++)
    {
        if (!visited[i] && ans[cur - 1] < arr[i])
        {
            ans[cur] = arr[i];
            visited[i] = 1;
            func(cur + 1);
            visited[i] = 0;
        }
    }
}

int main()
{
    int tmp;
    while (1)
    {
        cin >> n;
        if (n == 0)
        {
            break;
        }
        for (int i = 0; i < n; i++)
        {
            cin >> tmp;
            arr.push_back(tmp);
        }
        func(0);
        arr = {};
        for (int i = 0; i < 20; i++)
        {
            ans[i] = 0;
            visited[i] = 0;
        }
        cout << "\n";
    }
    return 0;
}
