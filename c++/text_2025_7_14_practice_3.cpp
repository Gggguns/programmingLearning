#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     *
     * @param s string字符串
     * @return bool布尔型
     */
    bool isValid(string s) {
        string str;
        for (auto e : s)
        {
            if (e == '[' || e == '{' || e == '(')str += e;
            else if (e == ')')
            {
                if (str.back() == '(')str.pop_back();
                else return false;
            }
            else if (e == ']')
            {
                if (str.back() == '[')str.pop_back();
                else return false;
            }
            else if (e == '}')
            {
                if (str.back() == '{')str.pop_back();
                else return false;
            }
        }
        if (str.empty())return true;
        else return false;
    }
};
int main()
{
    Solution s;
    string strTest = "(){}[]";
    cout << s.isValid(strTest);
	return 0;
}