#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<string> wallpaper) {
    int maxx = 0;
    int maxy = 0;
    int minx = 51;
    int miny = 51;
    for(int i = 0; i < wallpaper.size(); i++)
    {
        for(int j = 0; j < wallpaper[i].length(); j++)
        {
            if(wallpaper[i][j] == '#')
            {
                if(i < miny)
                {
                    miny = i;
                }
                if(i > maxy)
                {
                    maxy = i;
                }
                if(j < minx)
                {
                    minx = j;
                }
                if(j > maxx)
                {
                    maxx = j;
                }
            }
        }
    }
    vector<int> answer = {miny,minx,maxy + 1,maxx + 1};
    return answer;
}