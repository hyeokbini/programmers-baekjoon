#include <iostream>
#include <climits>
using namespace std;

/*
int dest = 0;
int minval = INT_MAX;

void dfs(int curidx, int vol)
{
    if(curidx == dest)
    {
        minval = min(vol,minval);
    }
    else if(curidx < dest)
    {
        dfs(curidx + 1, vol + 1);
        dfs(curidx * 2, vol);
    }
}
*/

int solution(int n)
{
    int answer = 0;
    while(n > 0)
    {
        if(n % 2 == 1)
        {
            n--;
            answer++;
        }
        else
        {
            n /= 2;
        }
    }
    return answer;
}