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
	void preKmp(string x, int m, vector<int> next) { // ����nextģʽ���ع�λ��ָʾ����
		int i, j;
		// ���Ի���iΪ��̽λ
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