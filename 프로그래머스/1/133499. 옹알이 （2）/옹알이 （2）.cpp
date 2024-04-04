#include <string>
#include <vector>

using namespace std;

int solution(vector<string> babbling) {
    int answer = 0;
    for(auto i : babbling)
    {
        int check = 0;
        bool ans = true;
        for(int j = 0; j < i.length(); j++)
        {
            if(i.substr(j,3) == "aya" && check != 1)
            {
                j += 2;
                check = 1;
            }
            else if(i.substr(j,3) == "woo" && check != 2)
            {
                j += 2;
                check = 2;
            }
            else if(i.substr(j,2) == "ye" && check != 3)
            {
                j += 1;
                check = 3;
            }
            else if(i.substr(j,2) == "ma" && check != 4)
            {
                j += 1;
                check = 4;
            }
            else
            {
                ans = false;
                break;
            }
        }
        if(ans)
        {
            answer++;
        }
    }
    return answer;
}