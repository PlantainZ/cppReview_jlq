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
		for (i = 2; i <= n; i++) { // ע�������и���������ڱ�λ�����������n=���٣�matrix�о��ж��ٸ�����
			if (matrix[i - 1] > matrix[i]) matrix[0] = matrix[i];
			for (j = i-1; matrix[j]>matrix[0]; --j) { // j=i-1 ��˼�ǣ�ע��������i��ǰ��һ�����Ƿ��ƶ��ϡ����Ƕ��ƶ��ˡ�
				matrix[j + 1] = matrix[j];
			}
			matrix[j] = matrix[0];
		}
	}
};