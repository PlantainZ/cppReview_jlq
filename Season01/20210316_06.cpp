#include<stdio.h>
#include<string>
#include<vector>
#include<iostream>
#include<stack>
using namespace std;


/*====================================================================================
 @ title   : ����һ�������ͷ�ڵ㣬��β��ͷ����������ÿ���ڵ��ֵ�������鷵�أ���

 @ example : ���룺s = head = [1,3,2]
			 �����[2,3,1]

 @ limited : 0 <= ������ <= 10000
======================================================================================*/

struct ListNode
{
	int val;
	ListNode* next;
	ListNode(int x) : val(x),next(NULL) {}
};

// ��4�ֽⷨ��
class Solution {
public:
	vector<int> res;
	vector<int> reversePrint(ListNode* head) {
		//����1��reverse��ת�� ========================
		while (head) {
			res.push_back(head->val);
			head = head->next;
		} // ��ʹ��algorithm�㷨�е�reverse��תres
		reverse(res.begin(), res.end());
		return res;


		//����2����ջ�� ================================
		stack<int> s;
		
		while (head) { //��ջ
			s.push(head->val);
			head = head->next;
		}
		while (!s.empty()) {// ��ջ
			res.push_back(s.top());
			s.pop();
		}
		return res;


		//����3���ݹ� =================================
		if (head == nullptr) return res; // �Դ�Ϊ�źŴ������ͷ���������²�����㷵��
		reversePrint(head->next);
		res.push_back(head->val); // push_back֮�󷵻�һ�����ʵ�res,�ϲ��ڴ˻����ϼ���push_back
		return res;


		if (head == nullptr) return res;



		//����4���ı�����ṹ ==========================
		ListNode* pre = nullptr;
		ListNode* next = head;
		ListNode* cur = head;
		while (cur) { // ��ת��һ������
			next = cur->next; // �����next��λ��
			cur->next = pre; // 
			pre = cur;
			cur = next;
		} // ��һ��pre������ָ��ָ��
		while (pre) { // ��ת�úõ������ٱ������߱�����������������
			res.push_back(pre->val);
			pre = pre->next;
		}
		return res;

	}
};



