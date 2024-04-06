#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N;
    cin >> N;

    vector<int> heights(N);
    for (int i = 0; i < N; ++i)
        cin >> heights[i];

    stack<pair<int, int>> s;
    vector<int> ans(N, 0);  

    for (int i = 0; i < N; ++i)
    {
        while (!s.empty())
        {
            if (s.top().first > heights[i])
            {                               
                ans[i] = s.top().second + 1;
                break;
            }
            s.pop();
        }
        s.push({heights[i], i});
    }

    for (int i = 0; i < N; ++i)
    {
        cout << ans[i];
        if (i != N - 1)
            cout << " ";
    }
    cout << endl;

    return 0;
}
