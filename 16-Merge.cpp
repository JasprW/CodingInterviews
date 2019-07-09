struct ListNode {
    int val;
    struct ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
   public:
    ListNode* Merge(ListNode* pHead1, ListNode* pHead2) {
        ListNode* nHead = new ListNode(1);
        ListNode* cur = nHead;
        ListNode *t1 = pHead1, *t2 = pHead2;
        while (t1 && t2) {
            if (t1->val <= t2->val) {
                cur->next = t1;
                cur = cur->next;
                t1 = t1->next;
            } else {
                cur->next = t2;
                cur = cur->next;
                t2 = t2->next;
            }
        }
        if (t1) {
            cur->next = t1;
        } else if (t2) {
            cur->next = t2;
        }
        return nHead->next;
    }
};