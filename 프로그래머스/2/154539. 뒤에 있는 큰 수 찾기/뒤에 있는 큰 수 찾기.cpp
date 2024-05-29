#include <string>
#include <vector>
#include <stack>

using namespace std;

vector<int> solution(vector<int> numbers) {
    vector<int> answer(numbers.size());
    /*
    bool check = false;
    for(int i = 0; i < numbers.size() - 1; i++)
    {
        for(int j = i + 1; j < numbers.size(); j++)
        {
            if(numbers[i] < numbers[j])
            {
                check = true;
                answer.push_back(numbers[j]);
                break;
            }
        }
        if(!check)
        {
            answer.push_back(-1);
        }
        check = false;
    }
    answer.push_back(-1);
    */
    stack<pair<int,int>> st;
    for(int i = 0; i < numbers.size(); i++)
    {
        if(st.empty() || st.top().second >= numbers[i])
        {
            st.push(make_pair(i,numbers[i]));
        }
        else if(numbers[i] > st.top().second)
        {
            while(!st.empty() && st.top().second < numbers[i])
            {
                answer[st.top().first] = numbers[i];
                st.pop();
            }
            st.push(make_pair(i,numbers[i]));
        }
    }
    while(!st.empty())
    {
        answer[st.top().first] = -1;
        st.pop();
    }
    return answer;
}