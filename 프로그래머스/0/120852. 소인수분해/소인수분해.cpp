#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n) {
    vector<int> answer;
    for(int i = 2; i <= n; i++)
    {  
        if(n % i == 0)
        {
            while(n % i == 0)
            {
                n /= i;
            }
            answer.push_back(i);
        }
    }
    return answer;
}