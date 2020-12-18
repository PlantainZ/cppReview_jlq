#include<vector>
#include<stdio.h>
#include<iostream>
using namespace std;

/*====================================================================================
 @ title   : 在一个 n * m 的二维数组中，每一行都按照从左到右递增的顺序排序，每一列都按照从上到下递增的顺序排序。
			 请完成一个高效的函数，输入这样的一个二维数组和一个整数，判断数组中是否含有该整数。

 @ example : 有矩阵 //[ [1,   4,  7, 11, 15],
				       [2,   5,  8, 12, 19],
					   [3,   6,  9, 16, 22],
					   [10, 13, 14, 17, 24],
					   [18, 21, 23, 26, 30] ]

			 输入 target = 5 , 输出 5
			 输入 target = 20, 输出 20
			
 @ limited : 0 <= n <= 1000
			 0 <= m <= 1000
======================================================================================*/

class Solution {
public:
    int findNumberIn2DArray(vector<vector<int> >& matrix, int target) {
        int i = matrix.size() - 1, j = 0; // 从左下角开始遍历
        while (i >= 0 && j < matrix[0].size())
        {
            if (matrix[i][j] > target) i--;
            else if (matrix[i][j] < target) j++;
            else return matrix[i][j];
        }
        return false;
    }
};



// *** main *** //
//int main() {
//    Solution test;
//    vector<vector<int> > a = { {1 , 4 , 7 , 11, 15},
//                               {2 , 5 , 8 , 12, 19},
//                               {3 , 6 , 9 , 16, 22},
//                               {10, 13, 14, 17, 24},
//                               {18, 21, 23, 26, 30} };
//
//    int result1 = test.findNumberIn2DArray(a,5);
//    int result2 = test.findNumberIn2DArray(a, 20);
//    cout << "result1:" << result1<<endl;
//    cout << "result2:" << result2 << endl;
//}