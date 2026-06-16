#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(!list1 && !list2) return nullptr;

        ListNode* node1 = list1;
        ListNode* node2 = list2;

        // ListNode* newHead = new ListNode(-1); //this node is created on top a heap and hence never destroyed
        // ListNode* temp = newHead;

        ListNode newHead(-1); //this is a dummy node created on top of a stcak which is destroyed when the fxn returns
        ListNode* temp = &newHead;

        while (node1 && node2) {
            if (node1->val <= node2->val){ 
                temp->next = node1;
                node1 = node1->next;
            }
            else {
                temp->next = node2;
                node2 = node2->next;
            }
            temp = temp->next;
        }

        temp->next = node1 ? node1 : node2;

        return newHead.next;
    }
};