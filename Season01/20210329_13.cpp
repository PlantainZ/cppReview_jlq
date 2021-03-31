#include<stdio.h>
#include<string>
#include<vector>
#include<iostream>
#include<stack>
#include<unordered_map>
#include<queue>
#include<array>
using namespace std;


/*====================================================================================
 @ title   : 地上有一个m行n列的方格，从坐标 [0,0] 到坐标 [m-1,n-1] 。
			 一个机器人从坐标 [0, 0] 的格子开始移动，它每次可以向左、右、上、下移动一格（不能移动到方格外），
			 也不能进入行坐标和列坐标的数位之和大于k的格子。
			 
			 例如，当k为18时，机器人能够进入方格 [35, 37] ，因为3+5+3+7=18。
			 但它不能进入方格 [35, 38]，因为3+5+3+8=19。
			 
			 请问该机器人能够到达多少个格子？

 @ example : 输入：m = 2, n = 3, k = 1		输出：3
			 输入：m = 3, n = 1, k = 0		输出：1

 @ limited : 1 <= n,m <= 100
			 0 <= k <= 20
======================================================================================*/

class Solution {
	// 计算x的数位之和
	int get(int x) {
		int res = 0;
		for (; x; x /= 10) {
			res += x % 10;
		}
		return res;
	}


public:
	int movingCount(int m, int n, int k) {
		if (!k) return 1;
		queue<pair<int, int> > Q;
	}
public:
	int movingCount(int m, int n, int k) {
		if (!k) return 1;
		// pair的作用主要是将两个数据合成一个数据，两个数据可以是任意类型（不同也可以！）
		queue<pair<int, int> > Q; 

		// 向右 & 向下 的方向数组
		int dx[2] = { 0,1 };
		int dy[2] = { 1,0 };

		// 数组名为vis,包含m个vector<int>对象，每个对象都被初始化为n个0
		vector<vector<int> > vis(m, vector<int>(n, 0)); 
		Q.push(make_pair(0, 0)); // make_pair直接生成pair对象
		vis[0][0] = 1;
		int ans = 1;

		while (!Q.empty()){
			auto [x, y] = Q.front(); // 每次都取的是一个方向
			Q.pop(); // 然后削掉这个方向
			for (int i = 0; i < 2; ++i) {
				int tx = dx[i] + x; 
				int ty = dy[i] + y; // [0,0]下/右再往下/右迈步
				if (tx < 0 || tx >= m || ty<0 || ty >= n || 
					vis[tx][ty] || get(tx) + get(ty)> k)		continue;
				Q.push(make_pair(tx, ty)); // 先放的是0,1，后放的是1,0，即先往右，再往下
				vis[tx][ty] = 1; // 把这个走过的格子设为1.因为从斜2到斜3的地方，会重复计算一个格子。以此类推
				ans++;
			}
		}
		return ans;
	}
};












