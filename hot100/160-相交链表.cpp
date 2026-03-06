#include <iostream>
using namespace std;


// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int numA = 0, numB = 0;
        ListNode *itA = headA, *itB = headB;
        while (itA) {
            numA++;
            itA = itA->next;
        }
        while (itB) {
            numB++;
            itB = itB->next;
        }
        itA = headA, itB = headB;
        if (numA > numB) {
            for (int i = 0; i < numA - numB; i++)
                itA = itA->next;
        } else {
            for (int i = 0; i < numB - numA; i++)
                itB = itB->next;
        }
        while (itA != itB) {
            itA = itA->next;
            itB = itB->next;
        }
        return itA;
    }
};