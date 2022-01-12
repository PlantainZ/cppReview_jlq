#include<stdio.h>
#include<iostream>
#include<unordered_map>
#include<string>
#include<stack>
using namespace std;

/*考点：KMP算法。
给你两个字符串 haystack 和 needle ，
请你在 haystack 字符串中找出 needle 字符串出现的第一个位置（下标从 0 开始）。如果不存在，则返回  -1 。
*/


class Solution {
public: // 在haystack（长）中找needle字符串！
public:
    int strStr(string haystack, string needle) {
        int n = haystack.size(), m = needle.size();
        if (m == 0) {
            return 0;
        }

        vector<int> pi(m);

        for (int i = 1, j = 0; i < m; i++) { // j是慢指针
            while (j > 0 && needle[i] != needle[j]) {
                j = pi[j - 1]; // 如果i≠j，
            }
            if (needle[i] == needle[j]) {
                j++;
            }
            pi[i] = j;
        }
        for (int i = 0, j = 0; i < n; i++) {
            while (j > 0 && haystack[i] != needle[j]) {
                j = pi[j - 1];
            }
            if (haystack[i] == needle[j]) {
                j++;
            }
            if (j == m) {
                return i - m + 1;
            }
        }
        return -1;
    }
};
