#include <string>
#include <vector>
#include <cmath>
#include <iostream>

using namespace std;

string solution(int n) {
    string answer = "";
    int idx = 1;
    while(pow(3,idx) < n)
    {
        idx++;
    }
    while(n != 0)
    {
        if(n % 3 == 0)
        {
            answer = "4" + answer;
            n--;
        }
        else if(n % 3 == 1)
        {
            answer = "1" + answer;
        }
        else if(n % 3 == 2)
        {
            answer = "2" + answer;
        }
        n /= 3;
    }
    return answer;
}