#include <string>
#include <vector>

using namespace std;

int sol(vector<int> nums, int target, int idx, int curans)
{
    if(idx == nums.size() && curans == target)
    {
        return 1;
    }
    else if(idx == nums.size() && curans != target)
    {
        return 0;
    }
    return sol(nums, target, idx + 1, curans + nums[idx]) + sol(nums, target, idx + 1, curans - nums[idx]);
}

int solution(vector<int> numbers, int target) {
    return sol(numbers, target, 0, 0);
}