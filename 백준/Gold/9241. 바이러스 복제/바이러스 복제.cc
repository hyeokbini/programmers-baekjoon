#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    //freopen("test.txt", "rt", stdin);
    string origin;
    string later;
    cin >> origin >> later;

    int startidx = 0;
    int minLen = min(origin.length(), later.length());
    while (startidx < minLen && origin[startidx] == later[startidx])
    {
        startidx++;
    }

    int originendidx = origin.length() - 1;
    int laterendidx = later.length() - 1;
    while (originendidx >= startidx && laterendidx >= startidx && origin[originendidx] == later[laterendidx])
    {
        originendidx--;
        laterendidx--;
    }
    if (startidx >= minLen - (origin.length() - 1 - originendidx))
    {
        if (origin.length() > later.length())
        {
            cout << 0 << endl;
        }
        else
        {
            cout << later.length() - origin.length() << endl;
        }
    }
    else
    {
        cout << later.length() - startidx - (origin.length() - 1 - originendidx) << endl;
    }

    return 0;
}
