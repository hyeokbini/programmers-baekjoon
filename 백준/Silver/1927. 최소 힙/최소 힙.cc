#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    //freopen("test.txt", "rt", stdin);
    priority_queue <int,vector<int>,greater<>> arr;
    int n,tmp;
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        cin >> tmp;
        if(tmp == 0)
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
            arr.push(tmp);
        }
    }
    return 0;
}
