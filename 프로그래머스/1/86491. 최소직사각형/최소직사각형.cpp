#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> sizes) {
    int answer = 0;
    int tmp = 0;
    int maxwide = 0;
    int maxheight = 0;
    for(auto &i : sizes)
    {
        if(i[0] < i[1])
        {
            tmp = i[0];
            i[0] = i[1];
            i[1] = tmp;
        }
    }
    for(auto i : sizes)
    {
        if(i[0] > maxwide)
        {
            maxwide = i[0];
        }
        if(i[1] > maxheight)
        {
            maxheight = i[1];
        }
    }
    return maxwide * maxheight;
}