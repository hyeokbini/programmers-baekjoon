#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    //freopen("test.txt", "rt", stdin);
    for(int i = 0; i < 3; i++)
    {
        int a1,a2,a3,b1,b2,b3,ans1,ans2,ans3;
        cin >> a1 >> a2 >> a3 >> b1 >> b2 >> b3;
        if(b3 < a3)
        {
            b2 -= 1;
            b3 += 60;
        }
        ans3 = b3 - a3;
        if(b2 < a2)
        {
            b1 -= 1;
            b2 += 60;
        }
        ans2 = b2 - a2;
        ans1 = b1 - a1;
        cout << ans1 << " " << ans2 << " " << ans3 << "\n";
    }
    return 0;
}
