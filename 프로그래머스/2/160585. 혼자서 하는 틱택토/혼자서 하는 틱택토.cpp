#include <string>
#include <vector>

using namespace std;

int solution(vector<string> board) {
    int answer = 1;
    int ocount = 0;
    int xcount = 0;
    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            if(board[i][j] == 'O')
            {
                ocount++;
            }
            else if(board[i][j] == 'X')
            {
                xcount++;
            }
        }
    }
    if(!((ocount == xcount) || (ocount - 1 == xcount)))
    {
        answer = 0;
    }
    bool isowin = false;
    bool isxwin = false;
    // 가로부터 검사
    for(int i = 0; i < 3; i++)
    {
        if(board[i][0] == board[i][1] && board[i][1] == board[i][2])
        {
            if(board[i][0] == 'O')
            {
                isowin = true;
            }
            else if(board[i][0] == 'X')
            {
                isxwin = true;
            }
        }
    }
    // 세로
    for(int i = 0; i < 3; i++)
    {
        if(board[0][i] == board[1][i] && board[1][i] == board[2][i])
        {
            if(board[0][i] == 'O')
            {
                isowin = true;
            }
            else if(board[0][i] == 'X')
            {
                isxwin = true;
            }
        }
    }
    // 대각
    if(board[0][0] == board[1][1] && board[1][1] == board[2][2])
    {
        if(board[0][0] == 'O')
        {
            isowin = true;
        }
        else if(board[0][0] == 'X')
        {
            isxwin = true;
        }
    }
    if(board[0][2] == board[1][1] && board[1][1] == board[0][2])
    {
        if(board[0][2] == 'O')
        {
            isowin = true;
        }
        else if(board[0][2] == 'X')
        {
            isxwin = true;
        }
    }
    if(isowin && isxwin)
    {
        answer = 0;
    }
    if(isowin)
    {
        if(ocount - 1 != xcount)
        {
            answer = 0;
        }
    }
    else if(isxwin && !isowin)
    {
        if(xcount != ocount)
        {
            answer = 0;
        }
    }
    return answer;
}