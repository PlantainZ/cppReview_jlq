#include<vector>
#include<stdio.h>
#include<iostream>
using namespace std;

/*====================================================================================
 @ title   : 找出数组中重复的数字。
			 在一个长度为 n 的数组 nums 里的所有数字都在 0～n-1 的范围内。
			 数组中某些数字是重复的，但不知道有几个数字重复了，也不知道每个数字重复了几次。
			 请找出数组中任意一个重复的数字。
 @ example : 输入 // [2, 3, 1, 0, 2, 5, 3]
			 输出 // 2 或 3 
======================================================================================*/

class Solution {
public:
    int findRepeatNumber(vector<int>& nums) {
        int i = 0;
        while (i < nums.size()) {
            if (nums[i] == i) { // 如果元素 = 索引，就下一个。注意i有可能换好几个数才++！！
                i++;
                continue;
            }
            if (nums[nums[i]] == nums[i]) // 如果将元素值当作索引，找到的数 = 这个元素值(在现在这个i前方的数全都已经纠正过索引，即索引值 = 元素值)，就返回！
                return nums[i];
            sswap(nums[i], nums[nums[i]]);  // 其它情况，就交换位置，尽量让索引值和元素值相等。即nums[nums[i]]要上下相等
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
//    printf("测试下printf\n");
//    cout << "result:" << result<<endl;
//}