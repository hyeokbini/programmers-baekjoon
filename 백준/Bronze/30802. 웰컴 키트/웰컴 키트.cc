#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    //freopen("test.txt", "rt", stdin);
    int n;
    cin >> n;
    vector<int> sizeval(6);
    for(int i = 0; i < 6; i++)
    {
        cin >> sizeval[i];
    }
    int t,p;
    cin >> t >> p;
    int ans1 = 0;
    for(int i = 0; i < 6; i++)
    {
        if(sizeval[i] % t == 0)
        {
            ans1 += sizeval[i] / t;
        }
        else
        {
            ans1 += sizeval[i] / t + 1;
        }
    }
    cout << ans1 << "\n";
    cout << n / p << " " << n % p;
    return 0;
}
