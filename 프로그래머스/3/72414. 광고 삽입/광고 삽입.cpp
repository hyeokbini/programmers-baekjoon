#include <bits/stdc++.h>

using namespace std;

vector<int> arr(360000,0);

int timetoidx(string time)
{
    int h = stoi(time.substr(6,2));
    int m = stoi(time.substr(3,2)) * 60;
    int s = stoi(time.substr(0,2)) * 3600;
    
    return h + m + s;
}

string idxtotime(int idx)
{
    string time = "";
    string h = to_string(idx / 3600);
    string m = to_string((idx % 3600) / 60);
    string s = to_string((idx % 3600) % 60);
    if(h.length() == 1)
    {
        h = "0" + h;
    }
    if(m.length() == 1)
    {
        m = "0" + m;
    }
    if(s.length() == 1)
    {
        s = "0" + s;
    }
    return h + ":" + m + ":" + s;
}

string solution(string play_time, string adv_time, vector<string> logs) {
    string answer = "";
    for(int i = 0; i < logs.size(); i++)
    {
        arr[timetoidx(logs[i].substr(0,8))]++; // 시작시간
        arr[timetoidx(logs[i].substr(9))]--; // 끝시간
    }
    int playtime = timetoidx(play_time);
    int advtime = timetoidx(adv_time);
    for(int i = 1; i < playtime; i++)
    {
        arr[i] += arr[i - 1];
    }
    long long curres = 0; // 탐색 중 갱신되는 값
    long long finalres = 0; // 최종값
    queue<int> Q; // 앞에서는 원소 삭제, 뒤에서는 원소 삽입
    for(int i = 0; i < advtime; i++)
    {
        // 0 ~ advtime까지(초기상태)
        finalres += arr[i];
        curres += arr[i];
        Q.push(arr[i]);
    }
    
    int curansidx = 0; // 답 인덱스 초기값은 0으로
    
    for(int i = advtime; i < playtime; i++)
    {
        curres -= Q.front(); // 구간합 맨 앞 원소 삭제
        curres += arr[i]; // 다음 차례 원소 추가
        Q.pop();
        Q.push(arr[i]); // 큐에도 동일한 연산 적용
        if(curres > finalres)
        {
            finalres = curres;
            curansidx = i - advtime + 1; // 인덱스 갱신
        }
    }
    
    return idxtotime(curansidx);
}