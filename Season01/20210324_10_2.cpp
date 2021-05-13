#include<stdio.h>
#include<string>
#include<vector>
#include<iostream>
#include<stack>
#include<unordered_map>
using namespace std;


/*====================================================================================
 @ title   : 一只青蛙一次可以跳上1级台阶，也可以跳上2级台阶。
			 求该青蛙跳上一个 n 级的台阶总共有多少种跳法。

 @ example : 输入：n = 2 , 输出：2
			 输入：n = 7 , 输出：21
			 输入：n = 0 , 输出：1

 @ limited : 答案需要取模 1e9+7（1000000007），如计算初始结果为：1000000008，请返回 1。
			 0 <= n <= 100
======================================================================================*/

// 0. 被钉在耻辱柱上的错误写法

class Solution {
public:
	int numWays(int n) {
		if (n == 0) return 1;
		else if (n == 1) return 1;
		return (numWays(n - 1) + numWays(n - 2)) % 1000000007;
	} // 要进行很多多余的计算！
		//	比如计算fib(3)，需要fib(2) & fib(1)
		// 当计算fib(4) 时，需要fib(3) & fib(2)
		// 每一次fib(3) & fib(2)都会执行一次递归。浪费大量时间！！
		// 所以应当将计算结果存储在一个哈希表上，计算过的就不用再重复计算，直接提取使用。
};
}


// 1. 递归写法========================================================
class Solution2 {
public:
	unordered_map<int, int> mp;
	int dfs(int n) {
		// 边界条件
		if (n == 0) return 1;
		else if (n == 1) return 1;

		// 先检查下，这个n是否之前计算过，如果算过直接返回
		else if (mp.count(n)) return mp[n];

		// 哈希表中没有，先算出来再存入哈希表
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


// 2. 迭代写法========================================================
class Solution3 {
public:
	int numWays(int n) {
		vector<int> dp;
		for (int i = 0; i <= n; i++) {
			//确定初始条件
			if (i == 0) dp.push_back(1);
			else if (i == 1) dp.push_back(1);

			// 动态规划方程
			else
				dp.push_back((dp[i - 1] + dp[i - 2]) % 10000000007);
		}
		return dp[n];
	}
};