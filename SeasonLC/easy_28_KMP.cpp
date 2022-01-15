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
public:
    int strStr(string haystack, string needle) {
        // return haystack.find(needle);
        // KMP算法
        int len = needle.size();
        if (!len) {
            return 0;
        }
        int size = haystack.size();
        if (!size) {
            return -1;
        }


        vector<int> next(len, -1); // next[]元素全都初始化为-1
        // 真正的 next 数组会在此基础上每个元素 +1，并且 next 和字符串都是从脚标 1 开始存储
        // 但这里都是按照从脚标 0 开始
        if (len > 1) {
            next[1] = 0; // next[0]=-1 ,next[1]=0
        }
        int t = 0; // t 是模式串截至前一个字符的部分的最长公共前后缀长度（如果从 1 开始就是截至当前字符）


        // 生成next数组的核心代码 ==========================================================================
        for (int k = 2; k < len; ++k) { // k为活动指针
            if (needle[k - 1] == needle[t]) {
                next[k] = ++t;
            }
            else {
                while (needle[k - 1] != needle[t]) { // needle[k-1]的前几位，和needle[ next[t] ]的前几位相同。见Cache
                    t = next[t]; // 找上一个needle[k]前缀一样的地方。
                    if (t == -1) { // 已经回溯到模串的第一个字符了！！
                        break;
                    }
                }
                next[k] = ++t;
            }
        } // ↑ ↑ ↑ =======================================================================================

        int mPtr = 0, patPtr = 0;
        while (true) {
            if (haystack[mPtr] == needle[patPtr]) {
                if (patPtr == len - 1) { // 如果完全匹配了。
                    return mPtr - len + 1;
                }
                ++patPtr;
                ++mPtr;
            }
            else {
                if (next[patPtr] != -1) { // 在中途失配
                    patPtr = next[patPtr];
                }
                else { // 如果已经回溯到next[0]，就两个指针都前进一步
                    patPtr = 0;
                    ++mPtr;
                }
            }
            if (mPtr >= size || size - mPtr < len - patPtr) { // 主串指针溢出，或者主串剩下将要匹配的个数不够长。
                return -1;
            }
        }
        return 0;
    }
};