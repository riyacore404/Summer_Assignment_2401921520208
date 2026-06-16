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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (head == nullptr || head->next == nullptr) return nullptr;

        ListNode* temp = head;
        int c = 0;
        while (temp != nullptr) {
            temp = temp->next;
            c++;
        }
        temp = head;
        c -= n;
        if (c == 0) {
            ListNode* newHead = head->next;
            delete head;
            return newHead;
        }

        while (c > 1) {
            temp = temp->next;
            c--;
        }
        ListNode* delNode = temp->next;
        temp->next = delNode->next;
        delete delNode;
        
        return head;
    }
};