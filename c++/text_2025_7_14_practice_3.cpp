#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    /**
     * �����е����������������������Ѿ�ָ���������޸ģ�ֱ�ӷ��ط����涨��ֵ����
     *
     *
     * @param s string�ַ���
     * @return bool������
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