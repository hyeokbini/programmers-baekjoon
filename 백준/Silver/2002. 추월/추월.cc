#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie();
    //freopen("test.txt", "rt", stdin);
    int N;
    cin >> N;

    unordered_map<string, int> inPos;
    for (int i = 0; i < N; i++)
    {
        string s;
        cin >> s;
        inPos[s] = i;
    }
    vector<int> out(N);
    for (int i = 0; i < N; i++)
    {
        string s;
        cin >> s;
        out[i] = inPos[s];
    }

    int ans = 0;
    int expected = 0;

    for (int i = 0; i < N; i++)
    {
        if (out[i] != expected)
        {
            ans++;
        }
        else
        {
            expected++;
            while (expected < N)
            {
                bool found = false;
                for (int j = 0; j <= i; j++)
                {
                    if (out[j] == expected)
                    {
                        found = true;
                        break;
                    }
                }
                if (!found)
                    break;
                expected++;
            }
        }
    }

    cout << ans;
    return 0;
}
