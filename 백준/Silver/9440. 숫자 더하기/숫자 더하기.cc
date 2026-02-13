#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    //freopen("test.txt", "rt", stdin);
    while (1)
    {
        int n;
        cin >> n;
        if(n == 0)
        {
            break;
        }
        int zerocount = 0;
        vector<int> arr;
        for (int i = 0; i < n; i++)
        {
            int c;
            cin >> c;
            if (c == 0)
            {
                zerocount++;
            }
            else
            {
                arr.push_back(c);
            }
        }
        int stand = zerocount;
        sort(arr.begin(), arr.end());
        string s1, s2;
        s1 += to_string(arr[0]);
        s2 += to_string(arr[1]);
        bool s1turn = true;
        while (zerocount)
        {
            s1 += '0';
            zerocount--;
            if (zerocount == 0)
            {
                s1turn = !s1turn;
                break;
            }
            s2 += '0';
            zerocount--;
        }
        for(int i = 2; i < arr.size(); i++)
        {
            if(s1turn)
            {
                s1 += to_string(arr[i]);
                s1turn = !s1turn;
            }
            else
            {
                s2 += to_string(arr[i]);
                s1turn = !s1turn;
            }
        }
        cout << stoi(s1) + stoi(s2) << "\n";
    }
    return 0;
}
