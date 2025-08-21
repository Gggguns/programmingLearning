#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        m = matrix.size();
        n = matrix[0].size();
        N = m * n;
        while (N)
        {
            {
                init(startx, starty);
                GoRight(matrix);
                if (N == 0) break;
                startx++;
            }
            {
                init(x + 1, y - 1);
                GoDown(matrix);
                if (N == 0) break;
                n--;
            }
            {
                init(x - 1, y - 1);
                GoLeft(matrix);
                if (N == 0) break;
                m--;
            }
            {
                init(x - 1, y + 1);
                GoUp(matrix);
                if (N == 0) break;
                starty++;
            }
        }
        return ret;
    }
    void GoRight(vector<vector<int>>& matrix)
    {
        N -= (n - y);
        while (y < n)
        {
            ret.push_back(matrix[x][y++]);
        }
    }
    void GoLeft(vector<vector<int>>& matrix)
    {
		N -= (y - starty + 1);
        while (y >= starty)
        {
            ret.push_back(matrix[x][y--]);
        }
    }
    void GoUp(vector<vector<int>>& matrix)
    {
		N -= (x - startx + 1);
        while (x >= startx)
        {
            ret.push_back(matrix[x--][y]);
        }
    }
    void GoDown(vector<vector<int>>& matrix)
    {
		N -= (m - x);
        while (x < m)
        {
            ret.push_back(matrix[x++][y]);
        }
    }
    void init(int x, int y)
    {
        this->x = x;
        this->y = y;
    }
    vector<int> ret;
    int startx = 0;
    int starty = 0;
    int x = 0;
    int y = 0;
    int m = 0;
    int n = 0;
    int N = 0;
};

int main()
{
    vector<vector<int>> matrix = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
	};
    Solution solution;
    vector<int> result = solution.spiralOrder(matrix);
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;
	return 0;
}