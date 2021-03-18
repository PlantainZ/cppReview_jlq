#include<stdio.h>
#include<string>
#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

/*====================================================================================
 @ title   : 写一个函数，输入 n ，求斐波那契（Fibonacci）数列的第 n 项（即 F(N)）。
			 斐波那契数列由 0 和 1 开始，之后的斐波那契数就是由之前的两数相加而得出。


 @ example : 输入：n = 2
			 输出：1

			 输入：n = 5
			 输出：5


 @ limited : 答案需要取模 1e9+7（1000000007），如计算初始结果为：1000000008，请返回 1。
			 0 <= n <= 100
======================================================================================*/

class Solution {
public:
	// 【法1】：递归 =================================================
	unordered_map<int, int> mp;
	int dfs(int n) {
		// 终止条件
		if (n == 0) return 0;
		else if (n == 1) return 1;
		else if (mp.count(n)) return mp[n];

		// 双支递归操作（有重叠）：把计算过的fib(n)的值存在HASH表中，可以大量减少运算
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


	// 【法2】：循环 =================================================
	int fib(int n) {
		vector<int> dp;
		for (int i = 0; i <= n; i++) {
			if (i == 0) dp.push_back(0);
			else if (i == 1) dp.push_back(1);
			//动态规划方程
			else dp.push_back((dp[i - 1] + dp[i - 2]) % 1000000007);
		}
		return dp[n];
	}

};