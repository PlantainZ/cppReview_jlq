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

// ���η� ============================================================
class Solution
{
public:
    int maxSubArray(vector<int>& nums)
    {
        //����Ѱ�������Сֵ����Ŀ����ʼֵһ��Ҫ����������ϵ���С���ֵ
        int result = INT_MIN;
        int numsSize = int(nums.size());
        result = maxSubArrayHelper(nums, 0, numsSize - 1);
        return result;
    }

    int maxSubArrayHelper(vector<int>& nums, int left, int right)
    { // �ҳ��е����ߵ�����Ӵ�
        if (left == right) return nums[left]; // �����и���˵������֣�����
        int mid = (left + right) / 2; // ȡ���е�
        int leftSum = maxSubArrayHelper(nums, left, mid);

        //ע������Ӧ��mid + 1������left + 1 = rightʱ��(nums,mid = left,right)������ѭ��,�������mid����left��
        int rightSum = maxSubArrayHelper(nums, mid + 1, right);
        int midSum = findMaxCrossingSubarray(nums, left, mid, right);

        int result = max(leftSum, rightSum); // ȡ���ֵȥ
        result = max(result, midSum);
        return result;
    }

    int findMaxCrossingSubarray(vector<int>& nums, int left, int mid, int right)
    {
        int leftSum = INT_MIN;
        int sum = 0;
        for (int i = mid; i >= left; i--) //���м䵽��ߣ������Ӵ�
        {
            sum += nums[i];
            leftSum = max(leftSum, sum);
        }

        int rightSum = INT_MIN;
        sum = 0;
        //ע������i = mid + 1�������ظ��õ�nums[i]
        for (int i = mid + 1; i <= right; i++) // ���м䵽�ұߣ������Ӵ�
        {
            sum += nums[i];
            rightSum = max(rightSum, sum);
        }
        return (leftSum + rightSum); // ����max�Ӵ���ӡ�
    }

};


// 2. ��̬�滮������һ ��On,On=============================================
class Solution2
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
            dp[i] = max(dp[i - 1] + nums[i], nums[i]); // ���dp[2]��5��nums[3]��-1����dp[i]�ͻ���max(5-1=4 , -1)=4
            result = max(result, dp[i]);
        }

        return result;
    }
};


// ��̬�滮�������,On,O1=====================================================================
class Solution3
{
public:
    int maxSubArray(vector<int>& nums)
    {
        //����Ѱ�������Сֵ����Ŀ����ʼֵһ��Ҫ����������ϵ���С���ֵ
        int result = INT_MIN;
        int numsSize = int(nums.size());
        //��Ϊֻ��Ҫ֪��dp��ǰһ�������int����һά����
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


// ̰���㷨 ===================================================================
class Solution
{
public:
    int maxSubArray(vector<int>& nums)
    {
        // ����Ѱ�������Сֵ����Ŀ����ʼֵһ��Ҫ����������ϵ���С���ֵ
        int result = INT_MIN;
        int numsSize = int(nums.size());
        int sum = 0;
        for (int i = 0; i < numsSize; i++)
        {
            sum += nums[i];
            result = max(result, sum); // ��resultС�Ĳ���ˢ��result��

            // ���sum < 0�����¿�ʼ�����򴮡���Ϊ֤�� [0]+1+2+3 > [-1]+1+2+3
            if (sum < 0)
            {
                sum = 0; // �ڶ������򴮿�ʼ��
            }
        }

        return result;
    }
};
























