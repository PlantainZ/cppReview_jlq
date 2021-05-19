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
		merge(arr,low,mid,high) // �ʼMergeʱ��������һ�飬Ҳ���ǣ�low = mid , high = mid+1 ��ʱ��
	}

	void merge(vector<int> arr, int low, int mid, int high) {
		for (k = low; k <= high; k++) tmp[k] = arr[k]; // ����Ԫ�ظ��Ƶ�tmp�ݴ�
		for (i = low, j = mid + 1, k = low; i <= mid && j <= high; k++) {
			if (tmp[i] <= tmp[j]) arr[k] = tmp[i++];
			else arr[k] = tmp[j++];
		}
		while (i <= mid) arr[k++] = tmp[i++];
		while (j <= high) arr[k++] = tmp[j++];
	}
};