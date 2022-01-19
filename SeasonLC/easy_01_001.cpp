#include<stdio.h>
#include<string>
#include<vector>
#include<iostream>
#include<unordered_map>
using namespace std;

class Solution { // 哈希表。 时间复杂度为O(n)
public: // map底层：红黑树，unordered_map底层：哈希表
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> hashtable; // 哈希表first:数值，second:数组索引 （倒过来放！）
        for (int i = 0; i < nums.size(); ++i) {
            auto it = hashtable.find(target - nums[i]); // find 值为target-nums[i]的键值对
            if (it != hashtable.end()) {
                return { it->second,i };  //返回数组下标
            }
            hashtable[nums[i]] = i; // 如果没有找到，那就新建一对hash键值对，first是数值，second是数组索引。
        }
    }
}；