#include<stdio.h>
#include<iostream>
#include<unordered_map>
#include<string>
#include<stack>
#include<minmax.h>
using namespace std;

/*
给你一个非负整数 x ，计算并返回 x 的 算术平方根 。
由于返回类型是整数，结果只保留 整数部分 ，小数部分将被 舍去 。
注意：不允许使用任何内置指数函数和算符，例如 pow(x, 0.5) 或者 x ** 0.5 。
*/


// 1. 二分法 ===================================================
class Solution {
public:
    int mySqrt(int x) {
        int l = 0, r = x, ans = -1;

        while (l <= r) {
            int mid = l + (r - l) / 2;
            if ((long long)mid * mid <= x) {
                ans = mid;
                l = mid + 1;
            }
            else {
                r = mid - 1;
            }
        }
        return ans;
    }
};


// 2. 牛顿迭代：泰勒级数,偏数学的原理，见LC_Cache===============================================
class Solution {
public:
    int mySqrt(int x) {
        if (x == 0) return 0;

        double C = x, x0 = x;
        while (true) {
            double xi = 0.5 * (x0 + C / x0);
            if (fabs(x0 - xi) < 1e-7) { // 相差很小
                break;
            }
            x0 = xi;
        }
        return int(x0);
    }
};
