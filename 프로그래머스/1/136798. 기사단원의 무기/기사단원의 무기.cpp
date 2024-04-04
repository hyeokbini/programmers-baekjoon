#include <string>
#include <vector>
#include <cmath>

using namespace std;

int solution(int number, int limit, int power) {
    int answer = 0;
    vector<int> arr(number,0);
    for(int i = 1; i <= number; i++)
    {
        for(int j = 1; j * j <= i; j++)
        {
            if(i % j == 0)
            {
                arr[i - 1]++;
                if(j * j < i)
                {
                    arr[i - 1] ++;
                }
            }
        }
    }
    for(auto& i : arr)
    {
        if(i > limit)
        {
            i = power;
        }
        answer += i;
    }
    return answer;
}