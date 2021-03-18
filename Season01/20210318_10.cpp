#include<stdio.h>
#include<string>
#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

/*====================================================================================
 @ title   : дһ������������ n ����쳲�������Fibonacci�����еĵ� n ��� F(N)����
			 쳲����������� 0 �� 1 ��ʼ��֮���쳲�������������֮ǰ��������Ӷ��ó���


 @ example : ���룺n = 2
			 �����1

			 ���룺n = 5
			 �����5


 @ limited : ����Ҫȡģ 1e9+7��1000000007����������ʼ���Ϊ��1000000008���뷵�� 1��
			 0 <= n <= 100
======================================================================================*/

class Solution {
public:
	// ����1�����ݹ� =================================================
	unordered_map<int, int> mp;
	int dfs(int n) {
		// ��ֹ����
		if (n == 0) return 0;
		else if (n == 1) return 1;
		else if (mp.count(n)) return mp[n];

		// ˫֧�ݹ���������ص������Ѽ������fib(n)��ֵ����HASH���У����Դ�����������
		int a = dfs(n - 1) % 1000000007;
		mp[n - 1] = a;
		int b = dfs(n - 2) % 1000000007;
		mp[n - 2] = b;
		mp[n] = (a + b) % 1000000007;
		return mp[n];
	}

	int fib(int n) {
		return dfs(n);
	}


	// ����2����ѭ�� =================================================
	int fib(int n) {
		vector<int> dp;
		for (int i = 0; i <= n; i++) {
			if (i == 0) dp.push_back(0);
			else if (i == 1) dp.push_back(1);
			//��̬�滮����
			else dp.push_back((dp[i - 1] + dp[i - 2]) % 1000000007);
		}
		return dp[n];
	}

};