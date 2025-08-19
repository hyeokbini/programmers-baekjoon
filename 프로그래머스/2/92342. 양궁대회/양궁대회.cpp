#include <bits/stdc++.h>

using namespace std;

vector<int> peachinfo;
int arrowcount;
vector<int> answer = {-1};
int curdiff = 0;

// func에서 뽑은 목록이 가능한지 체크 후 갱신
void check(vector<bool> lion)
{
    int n = arrowcount;
    int lionscore = 0;
    int peachscore = 0;
    vector<int> lionarrow(lion.size(),0);
    for(int i = 0; i < lion.size(); i++)
    {
        // 라이언이 이긴 점수
        if(lion[i])
        {
            lionarrow[i] += peachinfo[i] + 1;
            n -= peachinfo[i] + 1;
            lionscore += (10 - i);
        }
        // 피치가 이긴 점수
        else
        {
            if(peachinfo[i] > 0)
            {
                peachscore += (10 - i);
            }
        }
    }
    // 남은 화살은 전부 0점으로
    if(n > 0)
    {
        lionarrow[10] += n;
    }
    // 지거나 무승부
    if(lionscore <= peachscore)
    {
        return;
    }
    // 화살 n개보다 더 많이 사용
    if(n < 0)
    {
        return;
    }
    // 점수차가 더 커서 갱신하는 경우
    // 점수차가 더 크면 무조건 갱신
    if(lionscore - peachscore > curdiff)
    {
        curdiff = lionscore - peachscore;
        answer = lionarrow;
    }
    // 점수 차이가 같으면 낮은 점수부터 비교해서 더 많이 맞힌 쪽 선택
    else if(lionscore - peachscore == curdiff)
    {
        for(int i = 10; i >= 0; i--)
        {
            if(lionarrow[i] > answer[i])
            {
                answer = lionarrow;
                break;
            }
            else if(lionarrow[i] < answer[i])
            {
                // 기존 배열이 더 나음
                break; 
            }
        }
    }
}

// 라이언의 승리 점수 목록 뽑는 함수
void func(vector<bool> lion, int depth)
{
    if(depth == 11)
    {
        check(lion);
        return;
    }
    func(lion, depth + 1);
    lion[depth] = true;
    func(lion, depth + 1);
    return;
}

vector<int> solution(int n, vector<int> info) {
    arrowcount = n;
    peachinfo = info;
    vector<bool> lion(11,false);
    func(lion,0);
    
    return answer;
}