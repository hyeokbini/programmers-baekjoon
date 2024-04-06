#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(string s) {
    vector<int> answer;
    bool check = false;
    for(int i = s.length() - 1; i >=0; i--)
    {
        check = false;
        for(int j = i - 1; j >= 0; j--)
        {
            if(s[i] == s[j])
            {
                answer.push_back(i - j);
                check = true;
                break;
            }
        }
        if(!check)
        {
            answer.push_back(-1);
        }
    }
    reverse(answer.begin(),answer.end());
    return answer;
}