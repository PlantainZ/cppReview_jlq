#include<stdio.h>
#include<iostream>
#include<unordered_map>
#include<string>
#include<stack>

using namespace std;

class Solution {
public:
    bool isValid(string s) {
        int n = s.size();
        if (n % 2 == 1) {
            return false;
        } // ��������������ģ���Զ��ƥ�䡣���ؾ�������

        unordered_map<char, char> pairs = {
            {')', '('},
            {']', '['},
            {'}', '{'}
        }; // ��Ϊ�����ţ�ֵΪ������

        stack<char> stk; // ��ջ���洢������

        for (char ch : s) { // chÿ��ȡһ��s�ַ�������һ��
            if (pairs.count(ch)) { // ����ڼ�ֵ�����ҵ��˼�Ϊch���ַ��������Ǹ������š�
                if (stk.empty() || stk.top() != pairs[ch]) {
                    return false;
                }
                stk.pop();
            }
            else { // ������������ţ�����ջ
                stk.push(ch); 
            }
        }
        return stk.empty();
    }
};