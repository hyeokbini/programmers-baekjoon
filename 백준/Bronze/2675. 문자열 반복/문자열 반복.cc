#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    //freopen("test.txt", "rt", stdin);
    int n;
    cin >> n;
    while (n--)
    {
        int m;
        string tmp;
        cin >> m >> tmp;
        for (int i = 0; i < tmp.length(); i++)
        {
            for (int j = 0; j < m; j++)
            {
                cout << tmp[i];
            }
        }
        cout << "\n";
    }
    return 0;
}
