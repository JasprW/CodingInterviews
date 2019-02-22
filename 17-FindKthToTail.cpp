struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(nullptr) {
	}
};

class Solution {
public:
    ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) {
        if(!pListHead || k==0)
            return nullptr;
        ListNode* cur = pListHead;
        ListNode* rear = cur;
        for (int i=1; i<k; i++) {
            if(rear -> next) {
                rear = rear -> next;
            } else {
                return nullptr;
            }
        }
        while(rear -> next) {
            rear = rear -> next;
            cur = cur -> next;
        }
        return cur;
    }
};