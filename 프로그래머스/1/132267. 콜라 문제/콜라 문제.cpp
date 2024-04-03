#include <string>
#include <vector>

using namespace std;

int solution(int a, int b, int n) {
    int answer = 0;
    int tmp = 0;
    while(1)
    {
        if(n < a)
        {
            n += tmp;
            if(n < a)
            {
                break;
            }
            tmp = 0;
        }
        answer += ((n / a) * b);
        tmp += n % a;
        n = ((n / a) * b);
    }
    return answer;
}