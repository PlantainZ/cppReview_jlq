#include<stdio.h>
#include<string>
#include<vector>
#include<iostream>
#include<stack>
#include<unordered_map>
using namespace std;


/*====================================================================================
 @ title   : һֻ����һ�ο�������1��̨�ף�Ҳ��������2��̨�ס�
			 �����������һ�� n ����̨���ܹ��ж�����������

 @ example : ���룺n = 2 , �����2
			 ���룺n = 7 , �����21
			 ���룺n = 0 , �����1

 @ limited : ����Ҫȡģ 1e9+7��1000000007����������ʼ���Ϊ��1000000008���뷵�� 1��
			 0 <= n <= 100
======================================================================================*/

// 0. �����ڳ������ϵĴ���д��

class Solution {
public:
	int numWays(int n) {
		if (n == 0) return 1;
		else if (n == 1) return 1;
		return (numWays(n - 1) + numWays(n - 2)) % 1000000007;
	} // Ҫ���кܶ����ļ��㣡
		//	�������fib(3)����Ҫfib(2) & fib(1)
		// ������fib(4) ʱ����Ҫfib(3) & fib(2)
		// ÿһ��fib(3) & fib(2)����ִ��һ�εݹ顣�˷Ѵ���ʱ�䣡��
		// ����Ӧ�����������洢��һ����ϣ���ϣ�������ľͲ������ظ����㣬ֱ����ȡʹ�á�
};
}


// 1. �ݹ�д��========================================================
class Solution2 {
public:
	unordered_map<int, int> mp;
	int dfs(int n) {
		// �߽�����
		if (n == 0) return 1;
		else if (n == 1) return 1;

		// �ȼ���£����n�Ƿ�֮ǰ�������������ֱ�ӷ���
		else if (mp.count(n)) return mp[n];

		// ��ϣ����û�У���������ٴ����ϣ��
		int a = dfs(n - 1) % 1000000007;
		mp[n - 1] = a;
		int b = dfs(n - 2) % 1000000007;
		mp[n - 2] = b;
		mp[n] = (a + b) % 1000000007;
		return mp[n];
	}

	int numWays(int n) {
		return dfs(n);
	}
};


// 2. ����д��========================================================
class Solution3 {
public:
	int numWays(int n) {
		vector<int> dp;
		for (int i = 0; i <= n; i++) {
			//ȷ����ʼ����
			if (i == 0) dp.push_back(1);
			else if (i == 1) dp.push_back(1);

			// ��̬�滮����
			else
				dp.push_back((dp[i - 1] + dp[i - 2]) % 10000000007);
		}
		return dp[n];
	}
};