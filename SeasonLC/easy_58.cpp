#include<stdio.h>
#include<iostream>
#include<unordered_map>
#include<string>
#include<stack>
#include<minmax.h>
using namespace std;

/*
给你一个字符串 s，由若干单词组成，单词前后用一些空格字符隔开。返回字符串中最后一个单词的长度。

单词 是指仅由字母组成、不包含任何空格字符的最大子字符串。
*/

class Solution {
public: // 从后方遍历。主要观察如何处理空格！！！
    int lengthOfLastWord(string s) {
        int index = s.size() - 1;

        while (s[index] == ' ') {
            index--;  // 消除了最后方的空格
        }
        int wordLength = 0;
        while (index >= 0 && s[index] != ' ') {
            wordLength++;
            index--;
        }

        return wordLength;
    }
};