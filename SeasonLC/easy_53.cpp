#include<stdio.h>
#include<iostream>
#include<unordered_map>
#include<string>
#include<stack>
#include<minmax.h>
using namespace std;

// ����������
/*
	����һ���������� nums �������ҳ�һ���������͵����������飨���������ٰ���һ��Ԫ�أ������������͡�
	������ �������е�һ���������֡�
*/


// 1. ������==================================================
class Solution1
{
public:
    int maxSubArray(vector<int>& nums)
    {
        //����Ѱ�������Сֵ����Ŀ����ʼֵһ��Ҫ����������ϵ���С���ֵ
        int max = INT_MIN;
        int numsSize = int(nums.size());

        for (int i = 0; i < numsSize; i++)
        {
            int sum = 0;
            for (int j = i; j < numsSize; j++)
            {
                sum += nums[j];
                if (sum > max)
                {
                    max = sum;
                }
            }
        }

        return max;
    }
};



// 2. ��̬�滮�� =============================================
class Solution
{
public:
    int maxSubArray(vector<int>& nums)
    {
        //����Ѱ�������Сֵ����Ŀ����ʼֵһ��Ҫ����������ϵ���С���ֵ
        int result = INT_MIN;
        int numsSize = int(nums.size());

        //dp[i]��ʾnums����nums[i]��β����������
        vector<int> dp(numsSize);
        dp[0] = nums[0];
        result = dp[0];
        for (int i = 1; i < numsSize; i++)
        {
            dp[i] = max(dp[i - 1] + nums[i], nums[i]);
            result = max(result, dp[i]);
        }

        return result;
    }
};