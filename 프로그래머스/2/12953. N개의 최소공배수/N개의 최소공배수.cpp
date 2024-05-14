#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int fun(int a,int b)
{
    int tmpa = a;
    int tmpb = b;
    int t = a % b;
    if(t == 0)
    {
        return a;
    }
    else
    {
        while(t != 0)
        {
            t = a % b;
            a = b;
            b = t;
        }
        return tmpa * tmpb / a;
    }
}

int solution(vector<int> arr) {
    sort(arr.begin(),arr.end(),greater<>());
    int answer = fun(arr[0],arr[1]);
    for(int i = 2; i < arr.size(); i++)
    {
        answer = fun(answer,arr[i]);
    }
    return answer;
}