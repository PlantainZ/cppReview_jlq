#include<stdio.h>
#include<string>
#include<vector>
#include<iostream>
#include<stack>
#include<unordered_map>
#include<queue>
#include<array>
using namespace std;


/*====================================================================================
 @ title   : 给你一根长度为 n 的绳子，请把绳子剪成整数长度的 m 段（m、n都是整数，n>1并且m>1），
             每段绳子的长度记为 k[0],k[1]...k[m-1] 。
             
             请问 k[0]*k[1]*...*k[m-1] 可能的最大乘积是多少？
             例如，当绳子的长度是8时，我们把它剪成长度分别为2、3、3的三段，此时得到的最大乘积是18。

 @ example : 输入: 2      输出: 1
             解释: 2 = 1 + 1, 1 × 1 = 1

			 输入: 10     输出: 36
             解释: 10 = 3 + 3 + 4, 3 × 3 × 4 = 36

 @ limited : 1 <= n,m <= 100
			 0 <= k <= 20
======================================================================================*/

class Solution {
public:
    int cuttingRope(int n) {
        //考虑边缘情况
        if (n == 2) return 1;
        else if (n == 3) return 2;
        else if (n == 4) return 4;

        int* d = new int[n + 1];
        memset(d, 0, sizeof(int) * (n + 1));

        // 初始化
        d[2] = 1;
        d[3] = 2;
        d[4] = 4;

        // 外循环
        for (int i = 5; i <= n; ++i) {
            // 内循环 拆分2段，考虑各种拆分长度
            // 考虑边缘奇数需要额外多一个
            int maxJ = (i >> 1) + (i % 2);
            // 因为拆成1是浪费的，不会增加，所以起点是2
            for (int j = 2; j <= maxJ; ++j) {
                d[i] = max(max(d[i], j * (i - j)), (j > 3 ? d[j] : j) * d[i - j]);
            }
        }
        return d[n];
    }
};