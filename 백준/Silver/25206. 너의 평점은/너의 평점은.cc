#include <bits/stdc++.h>

using namespace std;

int main()
{
    //freopen("test.txt","rt",stdin);
    int counter = 0;
    string tmp;
    double sumscore = 0;
    double score;
    double divsum = 0;
    string grade;
    while(cin >> tmp)
    {
        if(counter % 3 == 0)
        {
            counter++;
            continue;
        }
        if(counter % 3 == 1)
        {
            counter++;
            score = stod(tmp);
            divsum += score;
            continue;
        }
        if(counter % 3 == 2)
        {
            counter++;
            if(tmp == "A+")
            {
                sumscore += score * 4.5;
            }
            else if(tmp == "A0")
            {
                sumscore += score * 4.0;
            }
            else if(tmp == "B+")
            {
                sumscore += score * 3.5;
            }
            else if(tmp == "B0")
            {
                sumscore += score * 3.0;
            }
            else if(tmp == "C+")
            {
                sumscore += score * 2.5;
            }
            else if(tmp == "C0")
            {
                sumscore += score * 2.0;
            }
            else if(tmp == "D+")
            {
                sumscore += score * 1.5;
            }
            else if(tmp == "D0")
            {
                sumscore += score * 1.0;
            }
            else if(tmp == "F")
            {
                sumscore += score * 0;
            }
            else if(tmp == "P")
            {
                divsum -= score;
            }
        }
    }
    cout << (sumscore / divsum);
    return 0;
}