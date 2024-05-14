#include <iostream>
#include <string>
#include <stack>

using namespace std;

int solution(string s)
{
    stack<char> S;
    for(int i = 0; i < s.length(); i++)
    {
        if(S.empty() || S.top() != s[i])
        {
            S.push(s[i]);
        }
        else if(S.top() == s[i])
        {
            S.pop();
        }
    }
    return S.empty();
}