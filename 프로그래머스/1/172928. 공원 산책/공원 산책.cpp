#include <string>
#include <vector>
#include <iostream>

using namespace std;



vector<int> solution(vector<string> park, vector<string> routes) {
    vector<int> answer;
    bool check = false;
    for(int i = 0; i < park.size(); i++)
    {
        for(int j = 0; j < park[i].length(); j++)
        {
            if(park[i][j] == 'S')
            {
                answer.push_back(i);
                answer.push_back(j);
            }
        }
    }
    int tmpx = answer[0];
    int tmpy = answer[1];
    for(int i = 0; i < routes.size(); i++)
    {
        check = false;
        if(routes[i][0] == 'E')
        {
            for(int j = tmpy; j <= tmpy + (routes[i][2] - '0') && j < park[0].length(); j++)
            {
                if(park[tmpx][j] == 'X')
                {
                    check = true;
                    break;
                }
            }
            if(check == true)
            {
                continue;
            }
            if(tmpy + (routes[i][2] - '0') > park[0].length() - 1)
            {
                continue;
            }
            else
            {
                answer[1] += (routes[i][2] - '0');
                tmpy += (routes[i][2] - '0');
            }
        }
        else if(routes[i][0] == 'W')
        {
            for(int j = tmpy; j >= tmpy - (routes[i][2] - '0') && j >= 0; j--)
            {
                if(park[tmpx][j] == 'X')
                {
                    check = true;
                    break;
                }
            }
            if(check == true)
            {
                continue;
            }
            if(tmpy - (routes[i][2] - '0') < 0 )
            {
                continue;
            }
            else
            {
                answer[1] -= (routes[i][2] - '0');
                tmpy -= (routes[i][2] - '0');
            }
        }
        else if(routes[i][0] == 'S')
        {
            for(int j = tmpx; j <= tmpx + (routes[i][2] - '0') && j < park.size(); j++)
            {
                if(park[j][tmpy] == 'X')
                {
                    check = true;
                    break;
                }
            }
            if(check == true)
            {
                continue;
            }
            if(tmpx + (routes[i][2] - '0') > park.size() - 1)
            {
                continue;
            }
            else
            {
                answer[0] += (routes[i][2] - '0');
                tmpx += (routes[i][2] - '0');
            }
        }
        else if(routes[i][0] == 'N')
        {
            for(int j = tmpx; j >= tmpx - (routes[i][2] - '0') && j >= 0; j--)
            {
                if(park[j][tmpy] == 'X')
                {
                    check = true;
                    break;
                }
            }
            if(check == true)
            {
                continue;
            }
            if(tmpx - (routes[i][2] - '0') < 0)
            {
                continue;
            }
            else
            {
                answer[0] -= (routes[i][2] - '0');
                tmpx -= (routes[i][2] - '0');
            }
        }
        cout << answer[0] << "," << answer[1];
    }
    return answer;
}