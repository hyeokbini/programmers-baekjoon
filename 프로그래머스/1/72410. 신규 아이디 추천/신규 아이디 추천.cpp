#include <string>
#include <vector>

using namespace std;

string solution(string new_id) {
    string answer = "";
    for(int i = 0; i < new_id.length(); i++)
    {
        if(isalpha(new_id[i]))
        {
            answer += tolower(new_id[i]);
        }
        else if(new_id[i] == '-' || new_id[i] == '_' || isdigit(new_id[i]))
        {
            answer += new_id[i];
        }
        else if(new_id[i] == '.' && new_id[i + 1] != '.')
        {
            if(i != new_id.length() - 1 && answer.back() != '.')
            {
                answer += '.';
            }
        }
    }
    if(answer[0] == '.')
    {
        answer = answer.substr(1);
    }
    if(answer.back() == '.')
    {
        answer.pop_back();
    }
    if(answer.empty())
    {
        answer += 'a';
    }
    if(answer.length() > 15)
    {
        answer = answer.substr(0,15);
        {
            if(answer.back() == '.')
            {
                answer.pop_back();
            }
        }
    }
    if(answer.length() < 3)
    {
        while(answer.length() < 3)
        {
            answer += answer.back();
        }
    }
    
    return answer;
}