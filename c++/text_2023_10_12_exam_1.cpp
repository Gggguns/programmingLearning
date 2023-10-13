#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#define N 3
using namespace std;
class Board
{
public:
    bool checkWon(vector<vector<int> > board)
    {
        if (board[0][0] == board[0][1] && board[0][0] == board[0][2])
        {
            if (board[0][0] == 1)
                return true;
        }
        else if (board[1][0] == board[1][1] && board[1][0] == board[1][2])
        {
            if (board[1][0] == 1)
                return true;
        }
        else if (board[2][0] == board[2][1] && board[2][0] == board[2][2])
        {
            if (board[2][0] == 1)
                return true;
        }
        else if (board[0][0] == board[1][1] && board[0][0] == board[2][2])
        {
            if (board[0][0] == 1)
                return true;
        }
        else if (board[0][2] == board[1][1] && board[0][2] == board[3][0])
        {
            if (board[0][2] == 1)
                return true;
        }
        else
        {
            return false;
        }
        return false;
    }
};
int main()
{
    //获取数据
    vector<vector<int>> vv;
    int num = 0;
    int i = 0,j=0;
    for (i = 0;i < N;i++)
    {
        for(j=0;j<N;j++)
        {
            cin >> num;
            vv[i].push_back(num);
        }

    }
    //判断输赢
    Board b;
    cout<<b.checkWon(vv);
    return 0;
}