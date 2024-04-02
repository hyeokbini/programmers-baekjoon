#include <string>
#include <vector>

using namespace std;

int solution(string s) {
    int answer = 0;
    string ansstr = "";
    for(int i = 0; i < s.length(); i++)
    {
        if(s[i] == 'z')
        {
            ansstr += '0';
        }
        else if(s[i] == 'o' && s[i + 1] == 'n' && s[i + 2] == 'e')
        {
            ansstr += '1';
        }
        else if(s[i] == 't')
        {
            if(s[i + 1] == 'w')
            {
                ansstr += '2';
            }
            else if(s[i + 1] == 'h')
            {
                ansstr += '3';
            }
        }
        else if(s[i] == 'f')
        {
            if(s[i + 1] == 'o')
            {
                ansstr += '4';
            }
            else if(s[i + 1] == 'i')
            {
                ansstr += '5';
            }
        }
        else if(s[i] == 's')
        {
            if(s[i + 1] == 'i')
            {
                ansstr += '6';
            }
            else if(s[i + 1] == 'e')
            {
                ansstr += '7';
            }
        }
        else if(s[i] == 'e' && s[i + 1] == 'i')
        {
            ansstr += '8';
        }
        else if(s[i] == 'n' && s[i + 1] == 'i')
        {
            ansstr += '9';
        }
        else if(isdigit(s[i]))
        {
            ansstr += s[i];
        }
    }
    answer = stoi(ansstr);
    return answer;
}