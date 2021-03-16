#include<stdio.h>
#include<string>
#include<vector>
#include<iostream>
#include<stack>
using namespace std;


/*====================================================================================
 @ title   : 输入一个链表的头节点，从尾到头反过来返回每个节点的值（用数组返回）。

 @ example : 输入：s = head = [1,3,2]
			 输出：[2,3,1]

 @ limited : 0 <= 链表长度 <= 10000
======================================================================================*/

struct ListNode
{
	int val;
	ListNode* next;
	ListNode(int x) : val(x),next(NULL) {}
};

// 有4种解法。
class Solution {
public:
	vector<int> res;
	vector<int> reversePrint(ListNode* head) {
		//【法1】reverse反转法 ========================
		while (head) {
			res.push_back(head->val);
			head = head->next;
		} // ↓使用algorithm算法中的reverse反转res
		reverse(res.begin(), res.end());
		return res;


		//【法2】入栈法 ================================
		stack<int> s;
		
		while (head) { //入栈
			s.push(head->val);
			head = head->next;
		}
		while (!s.empty()) {// 出栈
			res.push_back(s.top());
			s.pop();
		}
		return res;


		//【法3】递归 =================================
		if (head == nullptr) return res; // 以此为信号代表迭到头，进行以下操作层层返回
		reversePrint(head->next);
		res.push_back(head->val); // push_back之后返回一个新鲜的res,上层在此基础上继续push_back
		return res;


		if (head == nullptr) return res;



		//【法4】改变链表结构 ==========================
		ListNode* pre = nullptr;
		ListNode* next = head;
		ListNode* cur = head;
		while (cur) { // 反转整一条链表
			next = cur->next; // 保存好next的位置
			cur->next = pre; // 
			pre = cur;
			cur = next;
		} // 留一个pre作启动指向指针
		while (pre) { // 把转置好的链表再遍历，边遍历边塞进新链表中
			res.push_back(pre->val);
			pre = pre->next;
		}
		return res;

	}
};



