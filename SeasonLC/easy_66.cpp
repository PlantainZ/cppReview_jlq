#include<stdio.h>
#include<iostream>
#include<unordered_map>
#include<string>
#include<stack>
#include<minmax.h>
using namespace std;

/* 
给定一个由 整数 组成的 非空 数组所表示的非负整数，在该数的基础上加一。
最高位数字存放在数组的首位， 数组中每个元素只存储单个数字。
你可以假设除了整数 0 之外，这个整数不会以零开头。
*/

/* 举例：
输入：digits = [1,2,3]
输出：[1,2,4]
即，123 + 1 = 124

输入：digits = [4,3,2,1]
输出：[4,3,2,2]
解释：输入数组表示数字 4321。

输入：digits = [0]
输出：[1]
*/


class Solution {
public: // 很简单，但要考虑好极限情况的处理！！
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();

        for (int i = n - 1; i >= 0; --i) { // 从最后一个数字开始着手
            if (digits[i] != 9) { // 当前数字不等于9
                ++digits[i];
                for (int j = i + 1; j < n; ++j) {
                    digits[j] = 0; // 所有当前位置后边的9全部变为0！
                }
                return digits;
            } // 如果当前数字是9，直接什么都不动，然后--i进入下一轮。
        }

        // digits 中所有的元素均为 9
        vector<int> ans(n + 1); // 创建一个长度为n+1的ans数组，数组默认各元素初始化为0
        ans[0] = 1;
        return ans;
    }
};




