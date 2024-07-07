#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    //freopen("test.txt", "rt", stdin);
    int a,b,c;
    cin >> a >> b >> c;
    cout << a + b - c << "\n";
    string tmpa = to_string(a);
    string tmpb = to_string(b);
    cout << stoi(tmpa + tmpb) - c;
    return 0;
}
