#include <string>
#include <vector>

using namespace std;

int arr[100001];

int fun(int n)
{
    if(n == 1)
    {
        return 1;
    }
    if(n == 2)
    {
        return 1;
    }
    if(arr[n])
    {
        return arr[n];
    }
    return arr[n] = (fun(n-1) + fun(n-2)) %  1234567;
}
int solution(int n) {
    return fun(n);
}