#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    //freopen("test.txt", "rt", stdin);
    int n;
    vector<bool> arr(30,false);
    for(int i = 0; i < 28; i++)
    {
        cin >> n;
        arr[n - 1] = true;
    }
    for(int i = 1; i <= 30; i++)
    {
        if(!arr[i - 1])
        {
            cout << i << "\n";
        }
    }
    return 0;
}
