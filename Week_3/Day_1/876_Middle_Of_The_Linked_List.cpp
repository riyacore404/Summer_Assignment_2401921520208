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
    ListNode* middleNode(ListNode* head) {
        if (head || head->next) return head;
    
        ListNode* temp = head;
        ListNode* temp2 = head;
        while (temp2 && temp2->next) {
            temp = temp->next;
            temp2 = temp2->next->next;
        }

        return temp;
    }
};