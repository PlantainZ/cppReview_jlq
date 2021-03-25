#include<stdio.h>
#include<string>
#include<vector>
#include<iostream>
#include<stack>
#include<unordered_map>
using namespace std;


/*====================================================================================
 @ title   : 把一个数组最开始的若干个元素搬到数组的末尾，我们称之为数组的旋转。
			 输入一个递增排序的数组的一个旋转，输出旋转数组的最小元素。
			 例如，数组 [3,4,5,1,2] 为 [1,2,3,4,5] 的一个旋转，该数组的最小值为1。  


 @ example : 输入：[3,4,5,1,2]	输出：1
			 输入：[2,2,2,0,1]	输出：0

 @ limited : None
======================================================================================*/


// 使用二分查找
class Solution {
public:
	int minArray(vector<int>& numbers) {
		int low = 0;
		int high = numbers.size() - 1;

		while (low < high) {
			int pivot = low + (high - low) / 2; // 据说，这是防止溢出.本来该是 (low + height) // 2
			
			//如果中位数小于后方的数，那就取左边的部分
			if (numbers[pivot] < numbers[high]) high = pivot;

			// 如果中位数大于后方的数，就取右边的部分
			else if (numbers[pivot] > numbers[high]) low = pivot + 1;

			// 如果中位数和后方的数相等。
			else high -= 1;
		}// 跳出循环的时候，low = high

		return numbers[low];
	}
};

