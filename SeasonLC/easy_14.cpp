#include<stdio.h>
#include<string>
#include<unordered_map>
#include<iostream>
#include<minmax.h>
using namespace std;

class Solution { // round1 �����ⷨ
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (!strs.size()) { // string�ͼ�ֵ��unordered_map�̶���size()����
            return "";
        }
        string prefix = strs[0]; // ȡ��һ���ַ���
        int count = strs.size(); // �ж��ٸ��ַ���

        for (int i = 1; i < count; ++i) { // ����ÿ���ַ���
            prefix = longestCommonPrefix(prefix, strs[i]); // ��ÿ���ַ������б�����˫�����������·��� �� ��
            if (!prefix.size()) { // ��ͬǰ׺�����ڡ�
                break;
            }
        }

        return prefix;

    }

    string longestCommonPrefix(const string& str1, const string& str2) {
        int length = min(str1.size(), str2.size()); // ȡ������̵�ǰ׺
        int index = 0;
        while (index < length && str1[index] == str2[index]) {
            ++index; // ����ַ���ͬ��index+1
        }
        return str1.substr(0, index); // ����ǰ׺����substr��ȡ���ء�
    }
};


// round2 ����ɨ�跨 =======================================================================
class Solution2 {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (!strs.size()) { // Ԥ������
            return "";
        }


        int length = strs[0].size(); // ��һ���ַ����ж೤
        int count = strs.size();

        for (int i = 0; i < length; ++i) {
            char c = strs[0][i]; // �Ե�һ���ַ������ַ�Ϊ��׼
            for (int j = 1; j < count; ++j) {
                if (i == strs[j].size() || strs[j][i] != c) { // ǰ���ǣ�i�Ѿ�������j���±귶Χ 
                                                              // ����ǣ�iλ���±겻ƥ�䡣
                    return strs[0].substr(0, i); // ��0��ʼ��0��һ������i������[0:i-1]��
                }
            }
        }
        return strs[0];
    }
};