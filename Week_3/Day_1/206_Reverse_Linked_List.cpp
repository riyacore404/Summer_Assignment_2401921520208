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
    ListNode* reverseList(ListNode* head) {
        if (head || head->next) return head;

        ListNode* temp = head;
        ListNode* prev = NULL;
        while (temp != NULL) {
            ListNode* temp2 = temp->next;
            temp->next = prev;
            prev = temp;
            temp = temp2;
        }
        
        return prev;
    }
};