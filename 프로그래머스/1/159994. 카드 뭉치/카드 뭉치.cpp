#include <string>
#include <vector>

using namespace std;

string solution(vector<string> cards1, vector<string> cards2, vector<string> goal) {
    string answer = "";
    int idx1 = 0;
    int idx2 = 0;
    int goalidx = 0;
    while(1)
    {
        if(goal[goalidx] == cards1[idx1])
        {
            goalidx++;
            idx1++;
        }
        else if(goal[goalidx] == cards2[idx2])
        {
            goalidx++;
            idx2++;
        }
        else
        {
            break;
        }
        if(goalidx == goal.size())
        {
            return "Yes";
        }
    }
    return "No";
}