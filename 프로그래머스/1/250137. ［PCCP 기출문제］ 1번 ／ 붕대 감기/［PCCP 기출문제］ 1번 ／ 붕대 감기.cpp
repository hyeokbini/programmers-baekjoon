#include <string>
#include <vector>

using namespace std;

int solution(vector<int> bandage, int health, vector<vector<int>> attacks) {
    int answer = 0;
    int timecount = 0;
    int curhealth = health;
    int healthidx = 0;
    int healthcool = bandage[0];
    int onetimehealth = bandage[1];
    int bonushealth = bandage[2];
    int attackidx = 0;
    while(1)
    {
        if(attacks[attackidx][0] == timecount)
        {
            curhealth -= attacks[attackidx][1];
            if(curhealth <= 0)
            {
                return -1;
            }
            attackidx++;
            healthidx = 0;
        }
        else
        {
            curhealth += onetimehealth;
            healthidx++;
        }
        if(healthidx == healthcool)
        {
            curhealth += bonushealth;
            healthidx = 0;
        }
        if(curhealth > health)
        {
            curhealth = health;
        }
        if(attackidx == attacks.size())
        {
            return curhealth;
        }
        timecount++;
    }
    return answer;
}