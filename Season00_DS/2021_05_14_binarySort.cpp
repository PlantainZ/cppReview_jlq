#include<stdio.h>
#include<vector>
using namespace std;

class BinarySort
{
public:
	int i, j;
	vector<int> matrix;
private:
	void binaryInsertSort(vector<int> matrix, int n) {
		int low, high, mid;
		for (i = 2; i <= n; i++) {
			// 哨兵、low & high设置完毕
			matrix[0] = matrix[i];
			low = 1;
			high = i-1;

			while (low <= high) {
				mid = (low + high) / 2;
				if (matrix[0] < matrix[mid]) high = mid - 1; // 最后，这里会让high比low小。这个时候mid和low重合
															// pivot比low要小，所以low及其以后的，都向后挪动一位
				if (matrix[0] > matrix[mid]) low = mid + 1;
			} // high / low / 出来。 

			for (j = i -1; j > high; j--) {
				matrix[j + 1] = matrix[j];
			}
			matrix[j + 1] = matrix[0];
		}
	}
};
