#include<stdio.h>
#include<iostream>
#include<unordered_map>
#include<string>
#include<stack>
using namespace std;

// ��������λ�á�
/*
����һ�����������һ��Ŀ��ֵ�����������ҵ�Ŀ��ֵ�������������������Ŀ��ֵ�������������У����������ᱻ��˳������λ�á�

�����ʹ��ʱ�临�Ӷ�Ϊ O(log n) ���㷨��
*/
// ���� �����ַ�

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int n = nums.size();
        int left = 0, right = n - 1, ans = n;

        while (left <= right) {
            int mid = ((right - left) >> 1) + left; // ע�⣬Ҫ+left
            if (target <= nums[mid]) {
                ans = mid; // ����Զȡ�м�.����ָ����ʽ�ǣ�(right) (ans = mid,left)��Ҳ���ǣ�ans��ָ��Ƚϴ��һ������Cache��!
                right = mid - 1;
            }
            else {
                left = mid + 1;
            }
        }
        return ans;
    }


};

