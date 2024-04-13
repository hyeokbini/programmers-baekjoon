#include <string>
#include <vector>
#include <iostream>

using namespace std;

int arr[60001];
int ans(int n)
{
    if(n == 1)
    {
        return 1;
    }
    if(n == 2)
    {
        return 2;
    }
    if(arr[n])
    {
        return arr[n];
    }
    return arr[n] = (ans(n - 1) + ans(n - 2)) % 1000000007;
}


int solution(int n) {
    int answer = 0;
    answer = ans(n);
    return answer;
}