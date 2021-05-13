#include<stdio.h>
#include<vector>
using namespace std;

class BubbleSort
{
public:
	BubbleSort() {};
	~BubbleSort() {};

	void swap(int& a, int& b) {
		int tmp = a;
		a = b;
		b = tmp;
	}

private:
	int n;
	vector<int> array;

	void bubbleSort(vector<int>& array, int n) {
		for (int i = 0; i < n; ++i) {
			bool flag = false;
			for (int j = n - 1; j > i; --j) {
				if (array[j] > array[j - 1]) swap(array[j], array[j - 1]);
				flag = true;
			}
			if (flag == false) return;
		}
	}
};