#include<stdio.h>
#include<string>
#include<vector>
using namespace std;

class QucikSort
{
public:
	void quickSort(vector<int>& matrix, int low, int high) {
		if (low < high) {
			int pivotpos = Partition(matrix, low, high);
			quickSort(matrix, low, pivotpos - 1);
			quickSort(matrix, pivotpos, high);
		}
	}

private:
	int low, high;
	vector<int> matrix[];

	int Partition(vector<int> matrix, int low, int high) {
		int pivot = matrix[low];
		while(low<high){
			while (low < high && matrix[high] >= pivot) high--;
			matrix[low] = matrix[high];
			while (low < high && matrix[low] <= pivot) low++;
			matrix[high] = matrix[low];
		}
		matrix[low] = pivot;
		return low;
	}
};