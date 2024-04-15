#include <string>
#include <vector>

using namespace std;

int arr[2001];
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
    return arr[n] = (ans(n - 1) + ans(n - 2)) % 1234567;
}

long long solution(int n) {
    long long answer = 0;
    answer = ans(n);
    return answer;
}