#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    //freopen("test.txt", "rt", stdin);
    bool curidxisend = true;
    string S, T;
    cin >> S >> T;
    while(T.length() > S.length())
    {
        if(T.back() == 'A')
        {
            T.pop_back();
        }
        else if(T.back() == 'B')
        {
            T.pop_back();
            reverse(T.begin(),T.end());
        }
    }
    cout << (T == S) ? 1 : 0;
    return 0;
}
