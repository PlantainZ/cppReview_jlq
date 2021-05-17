#include<stdio.h>
#include<vector>
using namespace std;

class SelectSort
{
public:
	vector<int> arr;
	int n;

private:
	void selectSort(vector<int>& arr, int n) {
		for (int i = 0; i < n - 1; i++) {
			int min = i;
			for (int j = i + 1; j < n ; j++) {
				if (arr[j] < arr[min]) min = j;
			}
			if (min != i) Swap(arr[min], arr[i]);
		}
	}

	void Swap(int& a, int& b) {
		int tmp = a;
		a = b;
		b = tmp;
	}
};