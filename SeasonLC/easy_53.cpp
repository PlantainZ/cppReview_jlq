#include<stdio.h>
#include<iostream>
#include<unordered_map>
#include<string>
#include<stack>
#include<minmax.h>
using namespace std;

// 最大子数组和
/*
	给你一个整数数组 nums ，请你找出一个具有最大和的连续子数组（子数组最少包含一个元素），返回其最大和。
	子数组 是数组中的一个连续部分。
*/

// 分治法 ============================================================
class Solution
{
public:
    int maxSubArray(vector<int>& nums)
    {
        //类似寻找最大最小值的题目，初始值一定要定义成理论上的最小最大值
        int result = INT_MIN;
        int numsSize = int(nums.size());
        result = maxSubArrayHelper(nums, 0, numsSize - 1);
        return result;
    }

    int maxSubArrayHelper(vector<int>& nums, int left, int right)
    { // 找出中点两边的最大子串
        if (left == right) return nums[left]; // 最终切割成了单个数字，返回
        int mid = (left + right) / 2; // 取到中点
        int leftSum = maxSubArrayHelper(nums, left, mid);

        //注意这里应是mid + 1，否则left + 1 = right时，(nums,mid = left,right)会无线循环,算出来的mid还是left。
        int rightSum = maxSubArrayHelper(nums, mid + 1, right);
        int midSum = findMaxCrossingSubarray(nums, left, mid, right);

        int result = max(leftSum, rightSum); // 取最大值去
        result = max(result, midSum);
        return result;
    }

    int findMaxCrossingSubarray(vector<int>& nums, int left, int mid, int right)
    {
        int leftSum = INT_MIN;
        int sum = 0;
        for (int i = mid; i >= left; i--) //从中间到左边，最大的子串
        {
            sum += nums[i];
            leftSum = max(leftSum, sum);
        }

        int rightSum = INT_MIN;
        sum = 0;
        //注意这里i = mid + 1，避免重复用到nums[i]
        for (int i = mid + 1; i <= right; i++) // 从中间到右边，最大的子串
        {
            sum += nums[i];
            rightSum = max(rightSum, sum);
        }
        return (leftSum + rightSum); // 两个max子串相加。
    }

};


// 2. 动态规划法，其一 ，On,On=============================================
class Solution2
{
public:
    int maxSubArray(vector<int>& nums)
    {
        //类似寻找最大最小值的题目，初始值一定要定义成理论上的最小最大值
        int result = INT_MIN;
        int numsSize = int(nums.size());

        //dp[i]表示nums中以nums[i]结尾的最大子序和
        vector<int> dp(numsSize);
        dp[0] = nums[0];
        result = dp[0];
        for (int i = 1; i < numsSize; i++)
        {
            dp[i] = max(dp[i - 1] + nums[i], nums[i]); // 如果dp[2]是5，nums[3]是-1，那dp[i]就会是max(5-1=4 , -1)=4
            result = max(result, dp[i]);
        }

        return result;
    }
};


// 动态规划法，其二,On,O1=====================================================================
class Solution3
{
public:
    int maxSubArray(vector<int>& nums)
    {
        //类似寻找最大最小值的题目，初始值一定要定义成理论上的最小最大值
        int result = INT_MIN;
        int numsSize = int(nums.size());
        //因为只需要知道dp的前一项，我们用int代替一维数组
        int dp(nums[0]);
        result = dp;
        for (int i = 1; i < numsSize; i++)
        {
            dp = max(dp + nums[i], nums[i]);
            result = max(result, dp);
        }

        return result;
    }
};


// 贪心算法 ===================================================================
class Solution
{
public:
    int maxSubArray(vector<int>& nums)
    {
        // 类似寻找最大最小值的题目，初始值一定要定义成理论上的最小最大值
        int result = INT_MIN;
        int numsSize = int(nums.size());
        int sum = 0;
        for (int i = 0; i < numsSize; i++)
        {
            sum += nums[i];
            result = max(result, sum); // 比result小的不会刷新result！

            // 如果sum < 0，重新开始找子序串。因为证明 [0]+1+2+3 > [-1]+1+2+3
            if (sum < 0)
            {
                sum = 0; // 第二个子序串开始。
            }
        }

        return result;
    }
};
























