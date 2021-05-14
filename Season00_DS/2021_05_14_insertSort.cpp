#include<stdio.h>
#include<vector>
using namespace std;

class InsertSort
{
public:
	int pivot;
	vector<int> matrix;

private:
	void insertSort(vector<int>& matrix, int n) {
		int i, j;
		for (i = 2; i <= n; i++) { // 注意这里有个多出来的哨兵位，所以输入的n=多少，matrix中就有多少个变量
			if (matrix[i - 1] > matrix[i]) matrix[0] = matrix[i];
			for (j = i-1; matrix[j]>matrix[0]; --j) { // j=i-1 意思是，注意力放在i的前面一个数是否移动上。它们都移动了。
				matrix[j + 1] = matrix[j];
			}
			matrix[j] = matrix[0];
		}
	}
};