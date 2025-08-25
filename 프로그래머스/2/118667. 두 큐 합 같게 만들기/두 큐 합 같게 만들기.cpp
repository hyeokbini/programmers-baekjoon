#include <bits/stdc++.h>

using namespace std;

int solution(vector<int> queue1, vector<int> queue2) {
    int answer = -1;
    deque<int> Q1(queue1.begin(), queue1.end());
    deque<int> Q2(queue2.begin(), queue2.end());
    long long sum1 = 0;
    long long sum2 = 0;
    int limit = queue1.size();
    int count = 0;
    for(int i = 0; i < limit; i++)
    {
        sum1 += queue1[i];
        sum2 += queue2[i];
    }
    while(count <= limit * 4)
    {
        if(sum1 > sum2)
        {
            Q2.push_back(Q1.front());
            sum1 -= Q1.front();
            sum2 += Q1.front();
            Q1.pop_front();
        }
        else if(sum1 < sum2)
        {
            Q1.push_back(Q2.front());
            sum1 += Q2.front();
            sum2 -= Q2.front();
            Q2.pop_front();
        }
        else
        {
            answer = count;
            break;
        }
        count++;
    }
    
    return answer;
}