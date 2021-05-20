#include<stdio.h>
#include<vector>
#include<string>
using namespace std;

class KMP
{
public:
	vector<int> arr,next;
	string x;

private:
	void preKmp(string x, int m, vector<int> next) { // 生成next模式串回滚位置指示数组
		int i, j;
		// 初试化。i为试探位
		i = 0;
		j = next[0] = -1;

		while (i < m) {
			while (j >= 1 && x[i] != x[j]) j = next[j];
			i++;
			j++;

			if (x[i] == x[j]) next[i] = next[j];
			else next[i] = j;
		}
	}

	void kmp()



};