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
        } // 如果是奇数个数的，永远不匹配。返回就是啦！

        unordered_map<char, char> pairs = {
            {')', '('},
            {']', '['},
            {'}', '{'}
        }; // 键为右括号，值为左括号

        stack<char> stk; // 用栈来存储左括号

        for (char ch : s) { // ch每读取一个s字符，遍历一次
            if (pairs.count(ch)) { // 如果在键值对里找到了键为ch的字符，即，是个右括号。
                if (stk.empty() || stk.top() != pairs[ch]) {
                    return false;
                }
                stk.pop();
            }
            else { // 如果不是右括号，就入栈
                stk.push(ch); 
            }
        }
        return stk.empty();
    }
};