#include<stdio.h>
#include<iostream>
#include<unordered_map>
#include<string>
#include<stack>
#include<minmax.h>
using namespace std;

/*
������������¥�ݡ���Ҫ n ������ܵ���¥����
ÿ��������� 1 �� 2 ��̨�ס����ж����ֲ�ͬ�ķ�����������¥���أ�
ע�⣺���� n ��һ����������
*/



// 1. ��̬�滮��ʱ��O(n)�ռ�O(1)�����ֽⷨ���ڴ������ֹʹ��̫����ˡ� =============================================
class Solution {
public:
    int climbStairs(int n) {
        int p = 0, q = 0, r = 1;
        for (int i = 1; i <= n; ++i) {
            p = q;
            q = r;
            r = p + q;
        }
        return r;
    }
};



// 2. ��������ݡ�ʱ��O(log n) �ռ�O(1)=====================================================================

class Solution {
public: // ���ﴫ����2����ά���顣
    vector<vector<long long>> multiply(vector<vector<long long>>& a, vector<vector<long long>>& b) {
        // ������һ���������е����飡ע�������д��ʽ��
        // ��ǰͷ��ֻ�����������е����ͣ���߹涨��ʱ����Ҫд�е����ͣ���
        vector<vector<long long>> c(2, vector<long long>(2)); 

        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 2; j++) {
                c[i][j] = a[i][0] * b[0][j] + a[i][1] * b[1][j]; // ����c[1][1]��a��һ�� * b��һ�У�
            }
        }
        return c;
    }

    vector<vector<long long>> matrixPow(vector<vector<long long>> a, int n) {
        vector<vector<long long>> ret = { {1, 0}, {0, 1} };
        while (n > 0) {
            if ((n & 1) == 1) { // n���
                ret = multiply(ret, a);
            }
            n >>= 1; // ����n����2
            a = multiply(a, a);
        }
        return ret;
    }

    int climbStairs(int n) {
        vector<vector<long long>> ret = { {1, 1}, {1, 0} };
        vector<vector<long long>> res = matrixPow(ret, n);
        return res[0][0];
    }
};
