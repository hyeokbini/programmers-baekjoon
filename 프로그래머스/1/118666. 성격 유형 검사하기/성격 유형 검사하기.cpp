#include <string>
#include <vector>

using namespace std;

int chooseidx (string survey)
{
    if(survey[0] == 'R' || survey[0] == 'T')
    {
        return 0;
    }
    else if(survey[0] == 'F' || survey[0] == 'C')
    {
        return 1;
    }
    else if(survey[0] == 'M' || survey[0] == 'J')
    {
        return 2;
    }
    else
    {
        return 3;
    }
}
string solution(vector<string> survey, vector<int> choices) {
    string answer = "";
    vector<int> num (4,0); // 양수가 RCJA
    int idx = 0;
    for(int i = 0; i < survey.size(); i++)
    {
        idx = chooseidx(survey[i]);
        if(choices[i] == 4)
        {
            continue;
        }
        else if(choices[i] < 4) // 비동의 - RCJA는 음수값, 나머지는 양수값 더해져야함
        {
            if(survey[i][0] == 'R' || survey[i][0] == 'C' || survey[i][0] == 'J' || survey[i][0] == 'A')
            {
                num[idx] -= choices[i] - 4;
            }
            else
            {
                num[idx] += choices[i] - 4;
            }
        }
        else // 동의 - RCJA에 양수값 더해져야함
        {
            if(survey[i][0] == 'R' || survey[i][0] == 'C' || survey[i][0] == 'J' || survey[i][0] == 'A')
            {
                num[idx] -= choices[i] - 4;
            }
            else
            {
                num[idx] += choices[i] - 4;
            }
        }
    }
    if(num[0] >= 0)
    {
        answer += 'R';
    }
    else
    {
        answer += 'T';
    }
    if(num[1] >= 0)
    {
        answer += 'C';
    }
    else
    {
        answer += 'F';
    }
    if(num[2] >= 0)
    {
        answer += 'J';
    }
    else
    {
        answer += 'M';
    }
    if(num[3] >= 0)
    {
        answer += 'A';
    }
    else
    {
        answer += 'N';
    }
    return answer;
}