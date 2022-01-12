#include<stdio.h>
#include<iostream>
#include<unordered_map>
#include<string>
#include<stack>
using namespace std;

/* 删除有序数组中的重复项 */
/*
给你一个有序数组 nums ，请你 原地删除 重复出现的元素，
使每个元素 只出现一次 ，
返回删除后数组的新长度。

不要使用额外的数组空间，你必须在 原地 修改输入数组 并在使用 O(1) 额外空间的条件下完成。
*/

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size(); // 获取数组长度
        if (n == 0) {
            return 0;
        }

        int fast = 1, slow = 1; // 下标
        while (fast < n) {
            if (nums[fast] != nums[fast - 1]) {
                nums[slow] = nums[fast]; // 直接覆写！！
                ++slow;
            }
            ++fast;
        }
        return slow;
    } // 我是笨比吧呜呜呜


};