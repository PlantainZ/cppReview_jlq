#include<stdio.h>
#include<vector>
#include<string>
#include<iostream>
using namespace std;

class KMP
{
public:
	vector<int> arr,next;
	string x;

private:

	void preKmp(string x, int m, vector<int>& next) { // ����nextģʽ���ع�λ��ָʾ����
		int i, j;
		// ���Ի���iΪ��̽λ
		i = 0;
		j = next[0] = -1;

		while (i < m) { // �ص��ע���ǣ�jָʾλ�õ�ǰ׺��ע��ʧ��ָ��������ʧ�䣬�������ģʽ��ʧ�䡣
			// ���jλ�� һֱ��= iλ�õ�char���ǾͲ�ͣ����ȥ��һ��ָʾλ�ã���Щָʾλ�ö�����Ϊǰ׺��ͬ��
			// ֱ��x[i]=x[j] ���� j<1 �Ǿͳ�while�ˡ�
			// ʹ����Ŀǰλ�ã�i��j�߹���char������ȫ��ͬ��
			while (j >= 1 && x[i] != x[j]) j = next[j];

			i++; // Ȼ�������һ��charƥ��
			j++;

			if (x[i] == x[j]) next[i] = next[j]; // �������������char��ͬ����ô������iλ��ʧ�䣬��ô��jλ��Ҳ��ʧ���
			else next[i] = j; // ��һ�еķ�������ǰx[j]��һ����x[i]���䣬�������ߵ�ǰ׺һ����
			// ˭֪��������ʲô��ĸ�أ����Բ��������ǰ�ꡣ
		}
	}


	void kmp(string p, string t) {
		int m = p.length();
		int n = t.length();

		const char* x = p.c_str(); // ������Ҳ���ԣ�x��ģʽ��
		const char* y = t.c_str(); // y������
		/*--------------------------------------------------------------------------
		string-->char*
		char* x = p.c_str();
		c_str()������һ����ʱ��const char*ָ�룬һ��ָ������C�ַ�����ָ�룬���ܶ�����в���
				 ����Ϊ����c���Լ��ݣ���c������û��string���ͣ�
				 �ʱ���ͨ��string�����ĳ�Ա����c_str()��string ����ת����c�е��ַ�����ʽ��
 
		string���ʲô�����ָ��ͻ���ʲô�����string����������ô���ָ��ͻ��±ơ�
		----------------------------------------------------------------------------*/
		int i = 0, j = 0;
		vector<int> next;
		preKmp(x, m, next); // ����next���飬��ģʽ�������á�

		while (j < n) { // ��ʱjָ��������������Ҫ������������
			while (i > -1 && x[i] != y[i]) i = next[i]; // ������ģʽ��ʧ�䣬����ģʽ��������ȷ����ģʽ����char��ͬ��
			i++;
			j++;

			if (i >= m) { // ��ʱ�Ѿ�������һ��ģʽ��
				cout << "Matching index found at:" << j - i << endl; // j-i ���������У��ҵ�ģʽ����һ��char��ʼ��λ��
				i = next[i]; // ��ƥ����ɣ����ؿ�ƥ����ϸ�ǰ׺��
						     //��������û���ƥ���꣡ģʽ�������������п��ܻᷢ���ص�����
			}
		}
	}

};