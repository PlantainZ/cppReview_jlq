#include<vector>
#include<stdio.h>
#include<iostream>
using namespace std;

/*====================================================================================
 @ title   : ��ʵ��һ�����������ַ��� s �е�ÿ���ո��滻��"%20"��

 @ example : ���룺s = "We are happy."
			 �����"We%20are%20happy."

 @ limited : 0 <= s �ĳ��� <= 10000
======================================================================================*/

class Solution {
public:
    string replaceSpace(string s) {
        int count = 0, len = s.size();
        // ͳ�ƿո�����
        for (char c : s) {
            if (c == ' ') count++;
        }
        // �޸� s ����
        s.resize(len + 2 * count);
        // ��������޸�
        for (int i = len - 1, j = s.size() - 1; i < j; i--, j--) {
            if (s[i] != ' ')
                s[j] = s[i];
            else {
                s[j - 2] = '%';
                s[j - 1] = '2';
                s[j] = '0';
                j -= 2;
            }
        }
        return s;
    }
};












