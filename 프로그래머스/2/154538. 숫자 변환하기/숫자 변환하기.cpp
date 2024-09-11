#include <string>
#include <vector>
#include <queue>

using namespace std;

int startidx;
int endidx;
int plusval;
int ans = -1;
void bfs()
{
    vector<bool> visited(endidx + 1,false);
    queue<pair<int,int>> Q;
    Q.push({startidx,0});
    visited[startidx] = true;
    while(!Q.empty())
    {
        pair<int,int> cur = Q.front();
        Q.pop();
        if(cur.first == endidx)
        {
            ans = cur.second;
            return;
        }
        if(cur.first + plusval <= endidx && !visited[cur.first + plusval])
        {
            visited[cur.first + plusval] = true;
            Q.push({cur.first + plusval,cur.second + 1});
        }
        if(cur.first * 2 <= endidx && !visited[cur.first * 2])
        {
            visited[cur.first * 2] = true;
            Q.push({cur.first * 2,cur.second + 1});
        }
        if(cur.first * 3 <= endidx && !visited[cur.first * 3])
        {
            visited[cur.first * 3] = true;
            Q.push({cur.first * 3,cur.second + 1});
        }
    }
    return;
}
    
int solution(int x, int y, int n) {
    startidx = x;
    endidx = y;
    plusval = n;
    bfs();
    int answer = ans;
    return answer;
}