#include<stdio.h>
#include<iostream>
#include<unordered_map>
#include<string>
#include<stack>
using namespace std;

/*将两个升序链表合并为一个新的 升序 链表并返回。新链表是通过拼接给定的两个链表的所有节点组成的。*/

//类型定义。
struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
 }; // 注意这个ListNode的定义,val & next.


ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
    ListNode* dummy = new ListNode(0);
    ListNode* cur = dummy; // dummy只是一个辅助表头。等会最后会删掉。

    while (l1 != nullptr && l2 != nullptr) {
        ListNode** pp = (l1->val < l2->val) ? &l1 : &l2; // pp指值比较小的那个结点。为了获得L1/L2的地址！
                                                         //**pp，二级指针。获得p指针的地址！p指的是l1或者l2的地址。
        cur->next = *pp; // pp存的是p指针的内存地址。*pp就是p指针所指的地址！注意这个用法。
        cur = cur->next;
        *pp = (*pp)->next; // p指针所指地址的next。相当于让(l1或者l2)这个ListNode*指针直接移动！
    }

    cur->next = (l1 == nullptr) ? l2 : l1; // 只剩下一条链表了，直接连上。

    ListNode* ans = dummy->next; 
    delete dummy;
    return ans;
}