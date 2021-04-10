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
 @ title   : ����һ������Ϊ n �����ӣ�������Ӽ����������ȵ� m �Σ�m��n����������n>1����m>1����
             ÿ�����ӵĳ��ȼ�Ϊ k[0],k[1]...k[m-1] ��
             
             ���� k[0]*k[1]*...*k[m-1] ���ܵ����˻��Ƕ��٣�
             ���磬�����ӵĳ�����8ʱ�����ǰ������ɳ��ȷֱ�Ϊ2��3��3�����Σ���ʱ�õ������˻���18��

 @ example : ����: 2      ���: 1
             ����: 2 = 1 + 1, 1 �� 1 = 1

			 ����: 10     ���: 36
             ����: 10 = 3 + 3 + 4, 3 �� 3 �� 4 = 36

 @ limited : 1 <= n,m <= 100
			 0 <= k <= 20
======================================================================================*/

class Solution {
public:
    int cuttingRope(int n) {
        //���Ǳ�Ե���
        if (n == 2) return 1;
        else if (n == 3) return 2;
        else if (n == 4) return 4;

        int* d = new int[n + 1];
        memset(d, 0, sizeof(int) * (n + 1));

        // ��ʼ��
        d[2] = 1;
        d[3] = 2;
        d[4] = 4;

        // ��ѭ��
        for (int i = 5; i <= n; ++i) {
            // ��ѭ�� ���2�Σ����Ǹ��ֲ�ֳ���
            // ���Ǳ�Ե������Ҫ�����һ��
            int maxJ = (i >> 1) + (i % 2);
            // ��Ϊ���1���˷ѵģ��������ӣ����������2
            for (int j = 2; j <= maxJ; ++j) {
                d[i] = max(max(d[i], j * (i - j)), (j > 3 ? d[j] : j) * d[i - j]);
            }
        }
        return d[n];
    }
};