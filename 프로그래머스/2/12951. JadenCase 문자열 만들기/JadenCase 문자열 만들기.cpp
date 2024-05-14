#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    string answer = "";
    answer += toupper(s[0]);
    for(int i = 1; i < s.length(); i++)
    {
        if(s[i] == ' ')
        {
            answer += ' ';
        }
        else if(s[i - 1] == ' ' && s[i] != ' ')
        {
            answer += toupper(s[i]);
        }
        else if(s[i - 1] != ' ' && s[i] != ' ')
        {
            answer += tolower(s[i]);
        }
    }
    return answer;
}