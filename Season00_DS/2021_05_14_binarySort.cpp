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
			// �ڱ���low & high�������
			matrix[0] = matrix[i];
			low = 1;
			high = i-1;

			while (low <= high) {
				mid = (low + high) / 2;
				if (matrix[0] < matrix[mid]) high = mid - 1; // ����������high��lowС�����ʱ��mid��low�غ�
															// pivot��lowҪС������low�����Ժ�ģ������Ų��һλ
				if (matrix[0] > matrix[mid]) low = mid + 1;
			} // high / low / ������ 

			for (j = i -1; j > high; j--) {
				matrix[j + 1] = matrix[j];
			}
			matrix[j + 1] = matrix[0];
		}
	}
};
