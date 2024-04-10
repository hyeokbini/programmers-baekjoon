#include <vector>
#include <map>
#include <queue>
#include <cmath>

using namespace std;

vector<int> solution(int m, int n, vector<vector<int>> picture) {
    int number_of_area = 0;
    int max_size_of_one_area = 0;
    bool vis[m][n];
    for(int i = 0; i < m; i++)
    {
        for(int j = 0; j < n; j++)
        {
            vis[i][j] = false;
        }
    }
    int dx[4] = {0,1,0,-1};
    int dy[4] = {1,0,-1,0};
    for(int i = 0; i < m; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(picture[i][j] == 0 || vis[i][j])
            {
                continue;
            }
            int comp = picture[i][j];
            number_of_area++;
            queue<pair<int,int>> Q;
            vis[i][j] = 1;
            Q.push({i,j});
            int area = 0;
            while(!Q.empty())
            {
                area++;
                pair<int,int> current = Q.front();
                Q.pop();
                for(int i = 0; i < 4; i++)
                {
                    int nx = current.first + dx[i];
                    int ny = current.second + dy[i];
                    if(nx < 0 || nx >= m || ny < 0 || ny >= n)
                    {
                        continue;
                    }
                    if(vis[nx][ny] || picture[nx][ny] != comp)
                    {
                        continue;
                    }
                    if(picture[nx][ny] == comp)
                    {
                        vis[nx][ny] = 1;
                        Q.push({nx,ny});
                    }
                }
            }
            max_size_of_one_area = max(max_size_of_one_area,area);
        }
    }
    vector<int> answer(2);
    answer[0] = number_of_area;
    answer[1] = max_size_of_one_area;
    return answer;
}