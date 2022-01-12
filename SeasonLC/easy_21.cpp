#include<stdio.h>
#include<iostream>
#include<unordered_map>
#include<string>
#include<stack>
using namespace std;

/*��������������ϲ�Ϊһ���µ� ���� �������ء���������ͨ��ƴ�Ӹ�����������������нڵ���ɵġ�*/

//���Ͷ��塣
struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
 }; // ע�����ListNode�Ķ���,val & next.


ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
    ListNode* dummy = new ListNode(0);
    ListNode* cur = dummy; // dummyֻ��һ��������ͷ���Ȼ�����ɾ����

    while (l1 != nullptr && l2 != nullptr) {
        ListNode** pp = (l1->val < l2->val) ? &l1 : &l2; // ppֵָ�Ƚ�С���Ǹ���㡣Ϊ�˻��L1/L2�ĵ�ַ��
                                                         //**pp������ָ�롣���pָ��ĵ�ַ��pָ����l1����l2�ĵ�ַ��
        cur->next = *pp; // pp�����pָ����ڴ��ַ��*pp����pָ����ָ�ĵ�ַ��ע������÷���
        cur = cur->next;
        *pp = (*pp)->next; // pָ����ָ��ַ��next���൱����(l1����l2)���ListNode*ָ��ֱ���ƶ���
    }

    cur->next = (l1 == nullptr) ? l2 : l1; // ֻʣ��һ�������ˣ�ֱ�����ϡ�

    ListNode* ans = dummy->next; 
    delete dummy;
    return ans;
}