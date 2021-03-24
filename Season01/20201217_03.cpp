#include<vector>
#include<stdio.h>
#include<iostream>
using namespace std;

/*====================================================================================
 @ title   : �ҳ��������ظ������֡�
			 ��һ������Ϊ n ������ nums ����������ֶ��� 0��n-1 �ķ�Χ�ڡ�
			 ������ĳЩ�������ظ��ģ�����֪���м��������ظ��ˣ�Ҳ��֪��ÿ�������ظ��˼��Ρ�
			 ���ҳ�����������һ���ظ������֡�
 @ example : ���� // [2, 3, 1, 0, 2, 5, 3]
			 ��� // 2 �� 3 
======================================================================================*/

class Solution {
public:
    int findRepeatNumber(vector<int>& nums) {
        int i = 0;
        while (i < nums.size()) {
            if (nums[i] == i) { // ���Ԫ�� = ����������һ����ע��i�п��ܻ��ü�������++����
                i++;
                continue;
            }
            if (nums[nums[i]] == nums[i]) // �����Ԫ��ֵ�����������ҵ����� = ���Ԫ��ֵ(���������iǰ������ȫ���Ѿ�������������������ֵ = Ԫ��ֵ)���ͷ��أ�
                return nums[i];
            sswap(nums[i], nums[nums[i]]);  // ����������ͽ���λ�ã�����������ֵ��Ԫ��ֵ��ȡ���nums[nums[i]]Ҫ�������
        }
        return -1;
    }

    void sswap(int a, int b);
};

void Solution::sswap(int a, int b) {
    int tmp = a;
    a = b;
    b = tmp;
}


// *** main *** //
//int main() {
//    Solution test;
//    int a[7] = { 2, 3, 1, 0, 2, 5, 3 };
//    vector<int> b(a, a + 7);
//    int result = test.findRepeatNumber(b);
//    printf("������printf\n");
//    cout << "result:" << result<<endl;
//}