#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include<stack>
#include<string>
using namespace std;
class Solution {
public:
    int evalRPN(vector<string>& tokens)
    {
        stack<int> s;
        int i = 0;
        for (i = 0;i < tokens.size();i++)
        {
            if (tokens[i] == "+")
            {
                int num1 = s.top();
                s.pop();
                int num2 = s.top();
                s.pop();
                s.push(num2 + num1);
            }
            else if (tokens[i] == "/")
            {
                int num1 = s.top();
                s.pop();
                int num2 = s.top();
                s.pop();
                s.push(num2 / num1);
            }
            else if (tokens[i] == "*")
            {
                int num1 = s.top();
                s.pop();
                int num2 = s.top();
                s.pop();
                s.push(num2 * num1);
            }
            else if (tokens[i] == "-")
            {
                int num1 = s.top();
                s.pop();
                int num2 = s.top();
                s.pop();
                s.push(num2 - num1);
            }
            else
            {

                s.push(std::stol(tokens[i]));
            }
        }
        int ret = s.top();
        s.pop();
        return ret;
    }

};
int main()
{
    return 0;
}