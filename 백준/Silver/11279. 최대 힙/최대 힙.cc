#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    //freopen("test.txt", "rt", stdin);
    priority_queue <int> arr;
    int t;
    cin >> t;
    while(t--)
    {
        int val;
        cin >> val;
        if(val == 0)
        {
            if(arr.empty())
            {
                cout << 0 << "\n";
            }
            else
            {
                cout << arr.top() << "\n";
                arr.pop();
            }
        }
        else
        {
            arr.push(val);
        }
    }
    return 0;
}
