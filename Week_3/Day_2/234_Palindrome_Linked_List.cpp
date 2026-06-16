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
    ListNode* rev(ListNode* head2) {
        if (head2 == nullptr || head2->next == nullptr) return head2;
            
        ListNode* temp2 = rev(head2->next);
        head2->next->next = head2;
        head2->next = nullptr;
        return temp2;
    }
public:
    bool isPalindrome(ListNode* head) {
        if (head == nullptr || head->next == nullptr) return true;

        ListNode* temp = head;
        ListNode* temp2 = head;
        while (temp2->next != nullptr && temp2->next->next != nullptr) {
            temp = temp->next;
            temp2 = temp2->next->next;
        }

        ListNode* newHead = rev(temp->next);

        temp = head;
        temp2 = newHead;
        while (temp2 != nullptr) {
            if (temp2->val != temp->val) return false;
            temp2 = temp2->next;
            temp = temp->next;
        }

        return true;
    }
};