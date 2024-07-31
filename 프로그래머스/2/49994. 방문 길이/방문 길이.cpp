#include <bits/stdc++.h>

using namespace std;

int solution(string dirs) {
    int answer = 0;
    vector<vector<bool>> visited(21,vector<bool>(21,false));
    int curx = 10;
    int cury = 10;
    for(int i = 0; i < dirs.length(); i++)
    {
        if(dirs[i] == 'U')
        {
            if(curx - 2 < 0)
            {
                continue;
            }
            if(!visited[curx - 1][cury])
            {
                answer++;
                visited[curx - 1][cury] = true;
            }
            curx -= 2;
        }
        else if(dirs[i] == 'D')
        {
            if(curx + 2 > 20)
            {
                continue;
            }
            if(!visited[curx + 1][cury])
            {
                answer++;
                visited[curx + 1][cury] = true;
            }
            curx += 2;
        }
        else if(dirs[i] == 'R')
        {
            if(cury + 2 > 20)
            {
                continue;
            }
            if(!visited[curx][cury + 1])
            {
                answer++;
                visited[curx][cury + 1] = true;
            }
            cury += 2;
        }
        else if(dirs[i] == 'L')
        {
            if(cury - 2 < 0)
            {
                continue;
            }
            if(!visited[curx][cury - 1])
            {
                answer++;
                visited[curx][cury - 1] = true;
            }
            cury -= 2;
        }
    }
    return answer;
}