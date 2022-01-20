#include<stdio.h>
#include<iostream>
#include<unordered_map>
#include<string>
#include<stack>
#include<minmax.h>
using namespace std;

/* 02.两数之和。见LC_Cache
给你两个 非空 的链表，表示两个非负的整数。它们每位数字都是按照 逆序 的方式存储的，并且每个节点只能存储 一位 数字。
请你将两个数相加，并以相同形式返回一个表示和的链表。
你可以假设除了数字 0 之外，这两个数都不会以 0 开头。
*/

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

ListNode* addTwoNums(ListNode* l1, ListNode* l2) {
    ListNode* head = new ListNode(-1); // 表头为空
    ListNode* h = head; // 指引存数的地址

    int sum = 0;
    bool carry = false;

    while (l1 != NULL || l2 != NULL) {
        sum = 0;
        if (l1 != NULL) {
            sum += l1->val;
            l1 = l1->next;
        }
        if (l2 != NULL) {
            sum += l2->val;
            l2 = l2->next;
        }
        if (carry) sum++;
        h->next = new ListNode(sum % 10);
        h = h->next;
        carry = sum >= 10 ? true : false;
    }
    if (carry) {
        h->next = new ListNode(1);
        h = h->next;
    }
    return head->next;
}