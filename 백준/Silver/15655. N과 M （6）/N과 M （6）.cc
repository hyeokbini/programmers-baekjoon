#include <bits/stdc++.h>

using namespace std;

int n,m;
vector<int> arr;
int ans[10];
bool visited[10];

void func(int cur)
{
    if(cur == m)
    {
        for(int i = 0; i < m; i++)
        {
            cout << ans[i] << " ";
        }
        cout << "\n";
        return;
    }
    for(int i = 0; i < n; i++)
    {
        if(!visited[i] && ans[cur - 1] < arr[i])
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
    cin >> n >> m;
    int tmp;
    for(int i = 0; i < n; i++)
    {
        cin >> tmp;
        arr.push_back(tmp);
    }
    sort(arr.begin(),arr.end());
    func(0);
}
