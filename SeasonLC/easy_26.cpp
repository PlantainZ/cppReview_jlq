#include<stdio.h>
#include<iostream>
#include<unordered_map>
#include<string>
#include<stack>
using namespace std;

/* ɾ�����������е��ظ��� */
/*
����һ���������� nums ������ ԭ��ɾ�� �ظ����ֵ�Ԫ�أ�
ʹÿ��Ԫ�� ֻ����һ�� ��
����ɾ����������³��ȡ�

��Ҫʹ�ö��������ռ䣬������� ԭ�� �޸��������� ����ʹ�� O(1) ����ռ����������ɡ�
*/

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size(); // ��ȡ���鳤��
        if (n == 0) {
            return 0;
        }

        int fast = 1, slow = 1; // �±�
        while (fast < n) {
            if (nums[fast] != nums[fast - 1]) {
                nums[slow] = nums[fast]; // ֱ�Ӹ�д����
                ++slow;
            }
            ++fast;
        }
        return slow;
    } // ���Ǳ��Ȱ�������


};