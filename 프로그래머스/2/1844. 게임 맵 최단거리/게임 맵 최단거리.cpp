#include <vector>
#include <queue>
#include <map>

using namespace std;

int solution(vector<vector<int> > maps)
{
    int dx[4] = {0,1,0,-1};
    int dy[4] = {1,0,-1,0};
    queue<pair<int,int>> Q;
    Q.push({0,0});
    while(!Q.empty())
    {
        pair<int,int> cur = Q.front();
        Q.pop();
        for(int i = 0; i < 4; i++)
        {
            int nx = cur.first + dx[i];
            int ny = cur.second + dy[i];
            if(nx < 0 || ny < 0 || nx >= maps.size() || ny >= maps[0].size())
            {
                continue;
            }
            if(maps[nx][ny] != 1)
            {
                continue;
            }
            maps[nx][ny] = maps[cur.first][cur.second] + 1;
            Q.push({nx,ny});
        }
    }
    if(maps[maps.size() - 1][maps[0].size() - 1] != 1)
    {
        return maps[maps.size() - 1][maps[0].size() - 1];
    }
    else
    {
        return -1;
    }
}