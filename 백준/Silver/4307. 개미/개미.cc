#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    //freopen("test.txt", "rt", stdin);
    int n;
    cin >> n;
    while(n--)
    {
        int minval = 0;
        int maxval = 0;
        int len,ants;
        cin >> len >> ants;
        for(int i = 0; i < ants; i++)
        {
            int curant;
            cin >> curant;
            int shortcut = min(curant,len - curant);
            int longcut = max(curant,len - curant);
            minval = max(minval,shortcut);
            maxval = max(maxval,longcut);
        }
        cout << minval << " " << maxval << "\n";
    }
}
