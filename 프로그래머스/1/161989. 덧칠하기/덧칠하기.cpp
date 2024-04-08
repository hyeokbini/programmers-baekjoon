#include <string>
#include <vector>

using namespace std;

int solution(int n, int m, vector<int> section) {
    int answer = 0;
    vector<bool> arr (n,1);
    for(int i = 0; i < section.size(); i++)
    {
        arr[section[i] - 1] = false;
    }
    for(int j = 0; j < n; j++)
    {
        if(arr[j] == false)
        {
            for(int i = j; i < j + m && i < n; i++)
            {
                arr[i] = true;
            }
            answer++;
        }
    }
    return answer;
}