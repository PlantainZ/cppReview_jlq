#include<stdio.h>
#include<vector>
using namespace std;

class HeapSort {
public:
	vector<int> arr;
	int len;

	void Swap(int& a, int& b) {
		int tmp = a;
		a = b;
		b = tmp;
	}

private:

	void heapSort(vector<int> arr, int len) {
		BuildMaxHeap(arr, len);
		for (int i = len; i > 1; i--) {
			Swap(arr[i], arr[1]);
			AdjustDown(arr, 1, i - 1);
		}
	}//============================================

	void BuildMaxHeap(vector<int> arr, int len) {
		for (int i = len / 2; i > 0; i--) { // 每个非叶结点都进行枝排序
			AdjustDown(arr, i, len);
		}

	}//============================================

	void AdjustDown(vector<int> arr, int k, int len){// 父节点和子结点之间，简单选择排序的变种。
		arr[0] = arr[k]; // k指示父结点，i游走指示两个子结点
		for (int i = 2 * k; i <= len; i *= 2) {
			if (i < len && arr[i] < arr[i + 1]) i++;
			if (arr[0] >= arr[i]) break;
			else {
				arr[k] = arr[i];
				k = i;
			}
		}
		arr[k] = arr[0]; // 注意循环结束条件 i<=len

	}//=================================================

	void AdjustUp(vector<int> arr, int k) {
		arr[0] = arr[k];
		int i = k / 2;
		while (i > 0 && arr[0] > arr[i]) {
			arr[k] = arr[i];
			k = i;
			i /= 2;
		}
		arr[k] = arr[0];
	}
};
