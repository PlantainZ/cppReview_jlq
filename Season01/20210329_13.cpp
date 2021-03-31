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
 @ title   : ������һ��m��n�еķ��񣬴����� [0,0] ������ [m-1,n-1] ��
			 һ�������˴����� [0, 0] �ĸ��ӿ�ʼ�ƶ�����ÿ�ο��������ҡ��ϡ����ƶ�һ�񣨲����ƶ��������⣩��
			 Ҳ���ܽ�������������������λ֮�ʹ���k�ĸ��ӡ�
			 
			 ���磬��kΪ18ʱ���������ܹ����뷽�� [35, 37] ����Ϊ3+5+3+7=18��
			 �������ܽ��뷽�� [35, 38]����Ϊ3+5+3+8=19��
			 
			 ���ʸû������ܹ�������ٸ����ӣ�

 @ example : ���룺m = 2, n = 3, k = 1		�����3
			 ���룺m = 3, n = 1, k = 0		�����1

 @ limited : 1 <= n,m <= 100
			 0 <= k <= 20
======================================================================================*/

class Solution {
	// ����x����λ֮��
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
		// pair��������Ҫ�ǽ��������ݺϳ�һ�����ݣ��������ݿ������������ͣ���ͬҲ���ԣ���
		queue<pair<int, int> > Q; 

		// ���� & ���� �ķ�������
		int dx[2] = { 0,1 };
		int dy[2] = { 1,0 };

		// ������Ϊvis,����m��vector<int>����ÿ�����󶼱���ʼ��Ϊn��0
		vector<vector<int> > vis(m, vector<int>(n, 0)); 
		Q.push(make_pair(0, 0)); // make_pairֱ������pair����
		vis[0][0] = 1;
		int ans = 1;

		while (!Q.empty()){
			auto [x, y] = Q.front(); // ÿ�ζ�ȡ����һ������
			Q.pop(); // Ȼ�������������
			for (int i = 0; i < 2; ++i) {
				int tx = dx[i] + x; 
				int ty = dy[i] + y; // [0,0]��/��������/������
				if (tx < 0 || tx >= m || ty<0 || ty >= n || 
					vis[tx][ty] || get(tx) + get(ty)> k)		continue;
				Q.push(make_pair(tx, ty)); // �ȷŵ���0,1����ŵ���1,0���������ң�������
				vis[tx][ty] = 1; // ������߹��ĸ�����Ϊ1.��Ϊ��б2��б3�ĵط������ظ�����һ�����ӡ��Դ�����
				ans++;
			}
		}
		return ans;
	}
};












