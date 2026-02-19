#include <bits/stdc++.h>
using namespace std;

vector<int> ans;

// <입력값, 사람번호>
void func(int inputval, int humanheight)
{
    int overvalcount = 0;
    int curidx = 0;
    while (curidx < ans.size())
    {
        if (overvalcount == inputval)
        {
            break;
        }
        if (ans[curidx] > humanheight)
        {
            overvalcount++;
        }
        curidx++;
    }
    ans.insert(ans.begin() + curidx, humanheight);
    return;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    //freopen("test.txt", "rt", stdin);
    int n;
    cin >> n;
    // <입력값, 사람번호>
    vector<pair<int, int>> arr;

    for (int i = 0; i < n; i++)
    {
        int t;
        cin >> t;
        arr.push_back({t, i + 1});
    }
    // 맨 뒤 원소 미리 삽입
    ans.push_back(arr[n - 1].second);
    // 맨 뒤 원소 빼고 모든 원소에 대해
    for (int i = n - 2; i >= 0; i--)
    {
        func(arr[i].first, arr[i].second);
    }
    for (auto i : ans)
    {
        cout << i << " ";
    }
    return 0;
}
