struct RandomListNode {
    int label;
    struct RandomListNode *next, *random;
    RandomListNode(int x) : label(x), next(nullptr), random(nullptr) {}
};

class Solution {
   public:
    RandomListNode* Clone(RandomListNode* pHead) {
        if (!pHead)
            return nullptr;
        else {
            RandomListNode* cur = pHead;
            while (cur) {
                RandomListNode* tmp = new RandomListNode(cur->label);
                tmp->next = cur->next;
                cur->next = tmp;
                cur = tmp->next;
            }

            cur = pHead;
            while (cur) {
                cur->next->random = cur->random->next;
                cur = cur->next->next;
            }

            cur = pHead;
            RandomListNode* result = pHead->next;
            while (cur->next) {
                RandomListNode* tmp = cur->next;
                cur->next = tmp->next;
                cur = tmp;
            }
            return result;
        }
    }
};