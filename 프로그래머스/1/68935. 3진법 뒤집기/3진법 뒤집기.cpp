#include <string>
#include <vector>
#include <cmath>

using namespace std;

int solution(int n) {
    int answer = 0;
    int j = 0;
    vector<int> tmp;
    while(n != 0)
    {
        tmp.push_back(n % 3);
        n /= 3;
    }
    for(int i = tmp.size() - 1; i >= 0 ; i--)
    {
        answer += tmp[i] * pow(3,j);
        j++;
    }
    return answer;
}