#include <string>
#include <vector>
#include <cmath>

using namespace std;

int solution(int left, int right) {
    int answer = 0;
    for(double i = left; i <= right; i++)
    {
        sqrt(i) - (int)sqrt(i) == 0 ? answer -= i : answer += i;
    }
    return answer;
}