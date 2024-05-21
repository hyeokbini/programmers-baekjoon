#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    int idx = 0;
    int tmp = 0;
    while(1)
    {
        if(progresses[idx] == 100)
        {
            while(progresses[idx] == 100)
            {
                idx++;
                tmp++;
            }
            answer.push_back(tmp);
            tmp = 0;
        }
        if(idx == speeds.size())
        {
            break;
        }
        for(int i = 0; i < speeds.size(); i++)
        {
            if(progresses[i] < 100)
            {
                progresses[i] += speeds[i];
                if(progresses[i] > 100)
                {
                    progresses[i] = 100;
                }
            }
        }
    }
    return answer;
}