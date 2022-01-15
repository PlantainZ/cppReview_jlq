#include<stdio.h>
#include<iostream>
#include<unordered_map>
#include<string>
#include<stack>
using namespace std;

// 搜索插入位置。
/*
给定一个排序数组和一个目标值，在数组中找到目标值，并返回其索引。如果目标值不存在于数组中，返回它将会被按顺序插入的位置。

请必须使用时间复杂度为 O(log n) 的算法。
*/
// 考点 ：二分法

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int n = nums.size();
        int left = 0, right = n - 1, ans = n;

        while (left <= right) {
            int mid = ((right - left) >> 1) + left; // 注意，要+left
            if (target <= nums[mid]) {
                ans = mid; // 答案永远取中间.最后的指针形式是：(right) (ans = mid,left)，也就是，ans会指向比较大的一方。见CacheⅡ!
                right = mid - 1;
            }
            else {
                left = mid + 1;
            }
        }
        return ans;
    }


};

