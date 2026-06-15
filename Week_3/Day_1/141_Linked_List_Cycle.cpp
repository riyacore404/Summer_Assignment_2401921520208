#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    bool hasCycle(ListNode *head) {
        if (head || head->next) return false;

        ListNode* temp = head;
        ListNode* temp2 = head;
        while (temp2 && temp2->next) {
            temp = temp->next;
            temp2 = temp2->next->next;
            if (temp == temp2) return true;
        }

        return false;
    }
};