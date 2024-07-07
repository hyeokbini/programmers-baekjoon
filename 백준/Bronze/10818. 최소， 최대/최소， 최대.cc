#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    //freopen("test.txt", "rt", stdin);
    int n,tmp;
    int min = INT_MAX;
    int max = INT_MIN;
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        cin >> tmp;
        if(tmp < min)
        {
            min = tmp;
        }
        if(tmp > max)
        {
            max = tmp;
        }
    }
    cout << min << " " << max;
    return 0;
}
