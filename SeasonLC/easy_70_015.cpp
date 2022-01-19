#include<stdio.h>
#include<iostream>
#include<unordered_map>
#include<string>
#include<stack>
#include<minmax.h>
using namespace std;

/*
假设你正在爬楼梯。需要 n 阶你才能到达楼顶。
每次你可以爬 1 或 2 个台阶。你有多少种不同的方法可以爬到楼顶呢？
注意：给定 n 是一个正整数。
*/



// 1. 动态规划。时间O(n)空间O(1)，新手解法，内存溢出禁止使用太糟糕了。 =============================================
class Solution {
public:
    int climbStairs(int n) {
        int p = 0, q = 0, r = 1;
        for (int i = 1; i <= n; ++i) {
            p = q;
            q = r;
            r = p + q;
        }
        return r;
    }
};



// 2. 矩阵快速幂。时间O(log n) 空间O(1)=====================================================================

class Solution {
public: // 这里传进了2个二维数组。
    vector<vector<long long>> multiply(vector<vector<long long>>& a, vector<vector<long long>>& b) {
        // 建立了一个两行两列的数组！注意这个书写方式。
        // 最前头的只代表声明了行的类型，后边规定的时候还需要写列的类型！！
        vector<vector<long long>> c(2, vector<long long>(2)); 

        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 2; j++) {
                c[i][j] = a[i][0] * b[0][j] + a[i][1] * b[1][j]; // 比如c[1][1]是a第一行 * b第一列！
            }
        }
        return c;
    }

    vector<vector<long long>> matrixPow(vector<vector<long long>> a, int n) {
        vector<vector<long long>> ret = { {1, 0}, {0, 1} };
        while (n > 0) {
            if ((n & 1) == 1) { // n如果
                ret = multiply(ret, a);
            }
            n >>= 1; // 即，n除以2
            a = multiply(a, a);
        }
        return ret;
    }

    int climbStairs(int n) {
        vector<vector<long long>> ret = { {1, 1}, {1, 0} };
        vector<vector<long long>> res = matrixPow(ret, n);
        return res[0][0];
    }
};
