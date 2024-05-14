#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 0;
    int tmpsum = 0;
    for(int i = 1; i <= n; i++)
    {
        int j = i;
        while(1)
        {
            tmpsum += j;
            j++;
            if(tmpsum == n)
            {
                answer++;
                tmpsum = 0;
                break;
            }
            else if(tmpsum > n)
            {
                tmpsum = 0;
                break;
            }
        }
    }
    return answer;
}