#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

string solution(string s, string skip, int index) {
    string answer = "";
    for(int tmp = 0; tmp < index; tmp++)
    {
        for(int i = 0; i < s.length(); i++)
        {
            s[i]++;
            if (s[i] > 'z')
            {
                s[i] -= 26;
            }
            if(skip.find(s[i]) == string::npos)
            {
                continue;
            }
            else if(skip.find(s[i]) != string::npos)
            {
                while(1)
                {
                    s[i]++;
                    if (s[i] > 'z')
                    {
                        s[i] -= 26;
                    }
                    if(skip.find(s[i]) == string::npos)
                    {
                        break;
                    }
                }
            }
        }
    }
    return s;
}