#include <string>
#include <vector>
#include <stack>
#include <iostream>

using namespace std;

int solution(string s) {
    int answer = 0;
    int j = 0;
    stack<char> st;
    if(s.length() % 2 == 1)
    {
        return 0;
    }
    for(int i = 0; i < s.length(); i++) // 시작인덱스
    {
        for(int k = i; k < s.length() + i; k++)
        {
            j = k % s.length();
            if(s[j] == '(' || s[j] == '{' || s[j] == '[' || st.empty())
            {
                st.push(s[j]);
            }
            else if(st.top() == '(' && s[j] == ')' ||
                    st.top() == '{' && s[j] == '}' ||
                    st.top() == '[' && s[j] == ']')
            {
                st.pop();
            }
        }
        if(st.empty())
        {
            answer++;
        }
        else
        {
            st = {};
        }
    }
    return answer;
}