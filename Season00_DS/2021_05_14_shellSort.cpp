#include<stdio.h>
#include<vector>
using namespace std;

class ShellSort
{
public:
	vector<int> arr;

private:
	void shellSort(vector<int>& arr, int n) {
		int i, j,dk;
		for (dk = n / 2; dk >= 1; dk /= 2) {
			for (i = dk + 1; i <= n; i++) {
				if (arr[i] < arr[i - dk]) arr[0] = arr[i]; // ÉÚÎ»¼ÇÂ¼
				for (j = i - dk; j > 0 && arr[j] > arr[0]; j -= dk) {
					arr[j + dk] = arr[j];
				}
				arr[j + dk] = arr[0];
			}
		}
	}

};