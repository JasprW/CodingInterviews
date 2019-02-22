struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(nullptr) {
	}
};

class Solution {
public:
    ListNode* ReverseList(ListNode* pHead) {
        if(!pHead || !(pHead -> next)) {
            return pHead;
        }
        ListNode* nHead = pHead;
        ListNode* cur = pHead;
        while(cur -> next) {
            ListNode* tmp = cur -> next;
            cur -> next = tmp -> next;
            tmp -> next = nHead;
            nHead = tmp;
        }
        return nHead;
    }
};