#include <string>
#include <vector>

using namespace std;

int check(int n)
{
    int ans = 0;
    while(n > 0)
    {
        if(n % 2 == 1)
        {
            ans++;
        }
        n /= 2;
    }
    return ans;
}

int solution(int n) {
    int answer = n + 1;
    while(1)
    {
        if(check(n) == check(answer))
        {
            break;
        }
        answer++;
    }
    return answer;
}