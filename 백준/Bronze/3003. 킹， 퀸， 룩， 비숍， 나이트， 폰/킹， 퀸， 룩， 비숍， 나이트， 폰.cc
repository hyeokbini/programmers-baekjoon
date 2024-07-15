#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    //freopen("test.txt", "rt", stdin);
    vector<int> stand = {1,1,2,2,2,8};
    for(int i = 0; i < 6; i++)
    {
        int n;
        cin >> n;
        cout << stand[i] - n << " ";
    }
    return 0;
}
