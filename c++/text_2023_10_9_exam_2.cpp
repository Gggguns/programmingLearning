#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<stack>
using namespace std;
class Parenthesis {
public:
    bool chkParenthesis(string& A, int n)
    {
        stack<char> s;
        int i = 0;
        for (i = 0;i < n;i++)
        {
            if (A[i] == '(' || A[i] == '{' || A[i] == '[')
            {
                s.push(A[i]);
            }
            else if (A[i] == ')' || A[i] == '}' || A[i] == ']')
            {
                if (s.size())
                {
                    char ch = s.top();
                    s.pop();
                    if ((A[i] == ')' && ch != '(') || (A[i] == ']' && ch != '[') || (A[i] == '}' && ch != '{'))
                    {
                        return false;
                    }
                }
            }
            else
            {
                return false;
            }
        }
        if (s.size() == 0)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};
int main()
{
    string A;
    int N = 0;
    cin >> A >> N;
    Parenthesis p;
    cout<<p.chkParenthesis(A, N);
    return 0;
}