#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
using namespace std;
#include <vector>
class Solution {
public:
    /**
     * �����е����������������������Ѿ�ָ���������޸ģ�ֱ�ӷ��ط����涨��ֵ����
     *
     *
     * @param pushV int����vector
     * @param popV int����vector
     * @return bool������
     */
    bool IsPopOrder(vector<int>& pushV, vector<int>& popV) {
        int size1 = pushV.size();
        int size2 = popV.size();
        vector<int> ST;
        for (int i = 0, j = 0; i < size1 && j < size2; i++)
        {
            ST.push_back(pushV[i]);
            while (!ST.empty() && ST.back() == popV[j])
            {
                j++;
                ST.pop_back();
            }
        }
        return ST.size() == 0;
    }
};
int main()
{
	return 0;
}