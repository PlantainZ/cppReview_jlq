#include<stdio.h>
#include<iostream>
#include<unordered_map>
#include<string>
#include<stack>
#include<minmax.h>
using namespace std;

/* 
����һ���� ���� ��ɵ� �ǿ� ��������ʾ�ķǸ��������ڸ����Ļ����ϼ�һ��
���λ���ִ�����������λ�� ������ÿ��Ԫ��ֻ�洢�������֡�
����Լ���������� 0 ֮�⣬��������������㿪ͷ��
*/

/* ������
���룺digits = [1,2,3]
�����[1,2,4]
����123 + 1 = 124

���룺digits = [4,3,2,1]
�����[4,3,2,2]
���ͣ����������ʾ���� 4321��

���룺digits = [0]
�����[1]
*/


class Solution {
public: // �ܼ򵥣���Ҫ���Ǻü�������Ĵ�����
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();

        for (int i = n - 1; i >= 0; --i) { // �����һ�����ֿ�ʼ����
            if (digits[i] != 9) { // ��ǰ���ֲ�����9
                ++digits[i];
                for (int j = i + 1; j < n; ++j) {
                    digits[j] = 0; // ���е�ǰλ�ú�ߵ�9ȫ����Ϊ0��
                }
                return digits;
            } // �����ǰ������9��ֱ��ʲô��������Ȼ��--i������һ�֡�
        }

        // digits �����е�Ԫ�ؾ�Ϊ 9
        vector<int> ans(n + 1); // ����һ������Ϊn+1��ans���飬����Ĭ�ϸ�Ԫ�س�ʼ��Ϊ0
        ans[0] = 1;
        return ans;
    }
};




