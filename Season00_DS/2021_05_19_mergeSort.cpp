#include<stdio.h>
#include<vector>
using namespace std;

class MergeSort {
public:
	vector<int> arr,tmp;
	int i,j,k;

private:
	void mergeSort(vector<int> arr, int low, int high) {
		int mid = (low + high) / 2;
		mergeSort(arr, low, mid);
		mergeSort(arr, mid + 1, high);
		merge(arr,low,mid,high) // 最开始Merge时，是两个一组，也就是，low = mid , high = mid+1 的时候
	}

	void merge(vector<int> arr, int low, int mid, int high) {
		for (k = low; k <= high; k++) tmp[k] = arr[k]; // 所有元素复制到tmp暂存
		for (i = low, j = mid + 1, k = low; i <= mid && j <= high; k++) {
			if (tmp[i] <= tmp[j]) arr[k] = tmp[i++];
			else arr[k] = tmp[j++];
		}
		while (i <= mid) arr[k++] = tmp[i++];
		while (j <= high) arr[k++] = tmp[j++];
	}
};