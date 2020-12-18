#include<vector>
#include<stdio.h>
#include<iostream>
using namespace std;

/*====================================================================================
 @ title   : ��һ�� n * m �Ķ�ά�����У�ÿһ�ж����մ����ҵ�����˳������ÿһ�ж����մ��ϵ��µ�����˳������
			 �����һ����Ч�ĺ���������������һ����ά�����һ���������ж��������Ƿ��и�������

 @ example : �о��� //[ [1,   4,  7, 11, 15],
				       [2,   5,  8, 12, 19],
					   [3,   6,  9, 16, 22],
					   [10, 13, 14, 17, 24],
					   [18, 21, 23, 26, 30] ]

			 ���� target = 5 , ��� 5
			 ���� target = 20, ��� 20
			
 @ limited : 0 <= n <= 1000
			 0 <= m <= 1000
======================================================================================*/

class Solution {
public:
    int findNumberIn2DArray(vector<vector<int> >& matrix, int target) {
        int i = matrix.size() - 1, j = 0; // �����½ǿ�ʼ����
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