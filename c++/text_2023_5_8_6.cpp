#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
class Sum
{
public:
    Sum()
    {
        _ret = _ret + _i;
        _i++;
    }
    static int GetRet()
    {
        return _ret;
    }
private:
    static int _i;
    static int _ret;
};
int Sum::_i = 1;
int Sum::_ret = 0;
class Solution {
public:
    int Sum_Solution(int n) 
    {
        Sum* p = new Sum[n];
        return Sum::GetRet();
        delete p;
    }
    
};

int main()
{
    Solution d;
    cout << d.Sum_Solution(10) << endl;
	return 0;
}