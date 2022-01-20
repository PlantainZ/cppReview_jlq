#include<stdio.h>
#include<iostream>
#include<unordered_map>
#include<string>
#include<stack>
#include<minmax.h>
using namespace std;

// 给定一个字符串 s ，请你找出其中不含有重复字符的 最长子串 的长度。

/* 举例：
输入: s = "abcabcbb"
输出: 3
解释: 因为无重复字符的最长子串是 "abc"，所以其长度为 3。

输入: s = "bbbbb"
输出: 1
解释: 因为无重复字符的最长子串是 "b"，所以其长度为 1。

输入: s = "pwwkew"
输出: 3
解释: 因为无重复字符的最长子串是 "wke"，所以其长度为 3。
     请注意，你的答案必须是 子串 的长度，"pwke" 是一个子序列，不是子串。
*/


// 1. 滑动窗口 =====================================================
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        //定义两个游标,还有长度,与结果,均初始化为0
        int start(0), end(0), length(0), result(0);

        //只要end<字符串大小
        while (end < s.size())
        {
            //该注释错误		//暂存首个字符char,
            //其实应该是暂存end所指向的那个值,到时候会跟index所指向的值比较
            char tempChar = s[end];

            //定义index,它只用于改变start的指向一般为index+1
            //因为index所处的与end的值相等,则没有统计的必要了
            //for循环只用来判断是否相等
            //
            for (int index = start; index < end; index++) // 当index == end = 0时，不进行此循环。
            {
                //判断是否出现重复字符串
                if (tempChar == s[index])
                {
                    // 如果出现,则将start跳过重复字符index指向的下一字符
                    start = index + 1;
                    // 保存长度
                    length = end - start;

                    // 如果相等,判断结束
                    break;
                }
            }
            //此时,end向后移动,每一一次,长度+1
            end++;
            length++;
            //返回更新后的length,如果更大,则为它
            result = max(result, length);
        }
        return result;
    }
};


// 2.利用hashmap优化 =============================================================
class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        //s[start,end) 前面包含 后面不包含
        int start(0), end(0), length(0), result(0);
        int sSize = int(s.size());
        unordered_map<char, int> hash;

        while (end < sSize)
        {
            char tmpChar = s[end];
            //仅当s[start,end) 中存在s[end]时更新start
            if (hash.find(tmpChar) != hash.end() && hash[tmpChar] >= start)
            {
                start = hash[tmpChar] + 1;
                length = end - start;
            }
            hash[tmpChar] = end;

            end++;
            length++;
            result = max(result, length);
        }
        return result;
    }
};
