#include <iostream>
using namespace std;
struct ListNode {
    int val;
    struct ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
   public:
    ListNode* EntryNodeOfLoop(ListNode* pHead) {
        ListNode *slow = pHead, *fast = pHead;
        if (pHead == nullptr || pHead->next == nullptr) {
            return nullptr;
        }
        do {
            fast = fast->next->next;
            slow = slow->next;
        } while (slow != fast);

        fast = pHead;
        while (slow != fast) {
            fast = fast->next;
            slow = slow->next;
        }
        return fast;
    }
};

int main() {
    ListNode* head = new ListNode(1);
    ListNode* cur = head;
    cur->next = new ListNode(2);
    cur = cur->next;
    ListNode* tmp = new ListNode(3);
    cur->next = tmp;
    cur = cur->next;
    cur->next = new ListNode(4);
    cur = cur->next;
    cur->next = new ListNode(5);
    cur = cur->next;
    cur->next = tmp;
    cout << EntryNodeOfLoop(head)->val;
}