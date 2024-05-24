#include <string>
#include <vector>

using namespace std;

int solution(vector<int> priorities, int location) {
    int curidx = 0;
    int count = 1;
    vector<bool> check (priorities.size(),false);
    while(1)
    {
        while(check[curidx])
        {
            curidx++;
            curidx %= priorities.size();
        }
        int tmp = priorities[curidx];
        int tmpidx = curidx;
        for(int j = 0; j < priorities.size(); j++)
        {
            int i = (j + curidx) % priorities.size();
            if(!check[i] && priorities[i] > tmp)
            {
                tmp = priorities[i];
                tmpidx = i;
            }
        }
        curidx = tmpidx;
        check[curidx] = true;
        if(curidx == location)
        {
            break;
        }
        count++;
        curidx++;
        curidx %= priorities.size();
    }
    return count;
}