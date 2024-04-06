#include <string>
#include <vector>

using namespace std;

vector<int> solution(string today, vector<string> terms, vector<string> privacies) {
    vector<int> answer;
    vector<int> inttoday = {stoi(today.substr(0,4)),stoi(today.substr(5,2)),stoi(today.substr(8,2))};
    int compa = 0;
    int compb = 0;
    for(int i = 0; i < privacies.size(); i++)
    {
        compa = (inttoday[0] - stoi(privacies[i].substr(0,4))) * 336 + (inttoday[1] - stoi(privacies[i].substr(5,2))) * 28 + (inttoday[2] - stoi(privacies[i].substr(8,2)));
        for(int j = 0; j < terms.size(); j++)
        {
            if(terms[j][0] == privacies[i][11])
            {
                compb = stoi(terms[j].substr(2)) * 28;
            }
        }
        if(compa >= compb)
        {
            answer.push_back(i + 1);
        }
    }
    return answer;
}