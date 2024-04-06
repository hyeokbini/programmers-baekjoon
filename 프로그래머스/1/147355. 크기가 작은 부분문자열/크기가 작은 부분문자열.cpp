#include <string>
#include <vector>

using namespace std;

int solution(string t, string p) {
    int answer = 0;
    long long intp = stoll(p);
    for(int i = 0; i <= t.length() - p.length(); i++)
    {
        if(stoll(t.substr(i,p.length())) <= intp)
        {
            answer++;
        }
    }
    return answer;
}