#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(vector<int> ingredient) {
    int answer = 0;
    bool check = true;
    while(check)
    {
        check = false;
        for(int i = 3; i < ingredient.size(); i++)
        {
            if(ingredient[i - 3] == 1 && ingredient[i - 2] == 2 && ingredient[i - 1] == 3 && ingredient[i] == 1)
            {
                answer++;
                ingredient.erase(ingredient.begin() + i - 3,ingredient.begin() + i + 1);
                check = true;
                i -= 3;
            }
        }
    }
    return answer;
}