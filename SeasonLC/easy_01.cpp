#include<stdio.h>
#include<string>
#include<vector>
#include<iostream>
#include<unordered_map>
using namespace std;

class Solution { // ��ϣ�� ʱ�临�Ӷ�ΪO(n)
public: // map�ײ㣺�������unordered_map�ײ㣺��ϣ��
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> hashtable; // ��ϣ��first:��ֵ��second:�������� ���������ţ���
        for (int i = 0; i < nums.size(); ++i) {
            auto it = hashtable.find(target - nums[i]); // find ֵΪtarget-nums[i]�ļ�ֵ��
            if (it != hashtable.end()) {
                return { it->second,i };  //���������±�
            }
            hashtable[nums[i]] = i; // ���û���ҵ����Ǿ��½�һ��hash��ֵ�ԣ�first����ֵ��second������������
        }
    }
}��