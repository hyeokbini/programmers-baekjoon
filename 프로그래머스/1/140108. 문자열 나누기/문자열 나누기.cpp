#include <string>
#include <vector>

using namespace std;

int solution(string s) {
    int answer = 0;
    char a = s[0];
    int x = 0;
    int notx = 0;
    for(int i = 0; i < s.length(); i++)
    {
        if(s[i] == a)
        {
            x++;
        }
        else if(s[i] != a)
        {
            notx++;
        }
        if(x != notx && i == s.length() - 1)
        {
            answer++;
            break;
        }
        if(x != 0 && notx != 0 && x == notx)
        {
            answer++;
            x = 0;
            notx = 0;
            a = s[i + 1];
        }
    }
    return answer;
}