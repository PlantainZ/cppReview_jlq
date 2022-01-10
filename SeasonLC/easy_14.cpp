#include<stdio.h>
#include<string>
#include<unordered_map>
#include<iostream>
#include<minmax.h>
using namespace std;

class Solution { // round1 暴力解法
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (!strs.size()) { // string和键值对unordered_map固定有size()属性
            return "";
        }
        string prefix = strs[0]; // 取第一个字符串
        int count = strs.size(); // 有多少个字符串

        for (int i = 1; i < count; ++i) { // 遍历每个字符串
            prefix = longestCommonPrefix(prefix, strs[i]); // 对每个字符串进行遍历，双参数喊数在下方↓ ↓ ↓
            if (!prefix.size()) { // 共同前缀不存在。
                break;
            }
        }

        return prefix;

    }

    string longestCommonPrefix(const string& str1, const string& str2) {
        int length = min(str1.size(), str2.size()); // 取它们最短的前缀
        int index = 0;
        while (index < length && str1[index] == str2[index]) {
            ++index; // 如果字符相同，index+1
        }
        return str1.substr(0, index); // 返回前缀，用substr截取返回。
    }
};


// round2 纵向扫描法 =======================================================================
class Solution2 {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (!strs.size()) { // 预防条件
            return "";
        }


        int length = strs[0].size(); // 第一个字符串有多长
        int count = strs.size();

        for (int i = 0; i < length; ++i) {
            char c = strs[0][i]; // 以第一个字符串的字符为标准
            for (int j = 1; j < count; ++j) {
                if (i == strs[j].size() || strs[j][i] != c) { // 前边是，i已经超过了j的下标范围 
                                                              // 后边是，i位置下标不匹配。
                    return strs[0].substr(0, i); // 从0开始，0算一个，截i个，即[0:i-1]；
                }
            }
        }
        return strs[0];
    }
};