#include <bits/stdc++.h>

using namespace std;

int n,m;
int arr[10];

void func(int cur)
{
    if(cur == m)
    {
        for(int i = 0; i < m; i++)
        {
            cout << arr[i] << " ";
        }
        cout << "\n";
        return;
    }
    for(int i = 1; i <= n; i++)
    {
        if(i >= arr[cur - 1])
        {
            arr[cur] = i;
            func(cur + 1);
        }
    }
}

int main()
{
    cin >> n >> m;
    func(0);
}
