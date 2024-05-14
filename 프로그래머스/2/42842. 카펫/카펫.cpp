#include <string>
#include <vector>

using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    int tmp = brown / 2 + 2;
    for(int row = 3; row < tmp; row++)
    {
        if((row - 2) * (tmp - row - 2) == yellow)
        {
            if(row < tmp - row)
            {
                answer.push_back(tmp - row);
                answer.push_back(row);
                break;
            }
            else
            {
                answer.push_back(row);
                answer.push_back(tmp - row);
                break;
            }
        }
    }
    return answer;
}