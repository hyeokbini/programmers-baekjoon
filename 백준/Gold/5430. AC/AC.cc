#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    //freopen("test.txt", "rt", stdin);
    int n;
    cin >> n;
    while (n--)
    {
        string tmp;
        int num;
        string strarr;
        cin >> tmp >> num >> strarr;
        deque<int> D;
        int first = 0, second;
        int len = strarr.length();
        while (1)
        {
            for (int i = first + 1; i < len; i++)
            {
                if (strarr[i] == ',' || strarr[i] == ']')
                {
                    second = i;
                    break;
                }
            }
            if(second - 1 == first)
            {
                break;
            }
            D.push_back(stoi(strarr.substr(first + 1, second - (first + 1))));
            first = second;
            if (strarr[second] == ']')
            {
                break;
            }
        }
        bool truefront = true;
        bool errorcheck = false;
        for (auto i : tmp)
        {
            if (i == 'R')
            {
                if(truefront)
                {
                    truefront = false;
                }
                else
                {
                    truefront = true;
                }
            }
            else if (i == 'D')
            {
                if (D.empty())
                {
                    errorcheck = true;
                    break;
                }
                if (truefront)
                {
                    D.pop_front();
                }
                else
                {
                    D.pop_back();
                }
            }
        }
        if (errorcheck)
        {
            cout << "error\n";
        }
        else
        {
            int siz = D.size();
            if (truefront)
            {
                cout << "[";
                for (int i = 0; i < siz; i++)
                {
                    if (i == siz - 1)
                    {
                        cout << D[i];
                    }
                    else
                    {
                        cout << D[i] << ",";
                    }
                }
                cout << "]\n";
            }
            else
            {
                cout << "[";
                for (int i = siz - 1; i >= 0; i--)
                {
                    if (i == 0)
                    {
                        cout << D[i];
                    }
                    else
                    {
                        cout << D[i] << ",";
                    }
                }
                cout << "]\n";
            }
        }
    }
    return 0;
}