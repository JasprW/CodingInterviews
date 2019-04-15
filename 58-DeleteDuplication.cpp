#include <iostream>
#include <vector>
using namespace std;

struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) :
        val(x), next(NULL) {
    }
};


ListNode* deleteDuplication(ListNode* pHead)
    {
        if(pHead == nullptr || pHead -> next == nullptr) {
            return pHead;
        }
        ListNode* cur = pHead, * nex = cur -> next;
        if(cur -> val == nex -> val) {
            nex = nex -> next;
            while(nex != nullptr && nex -> val == cur -> val) {
                nex = nex -> next;
            }
            return deleteDuplication(nex);
        }
        else {
            pHead -> next = deleteDuplication(pHead -> next);
            return pHead;
        }
    }

ListNode* list(vector<int> arr) {
    if(arr.size() == 0) {
        return nullptr;
    }
    ListNode* head = new ListNode(arr[0]);
    ListNode* cur = head;
    for(int i=1; i < arr.size(); i++) {
        cur -> next = new ListNode(arr[i]);
        cur = cur -> next;
    }
    return head;
}

int main() {
    vector<int> arr = {1,2,3,3,4,4,5};
    ListNode* l = list(arr);
    ListNode* res = deleteDuplication(l);
    while(res != nullptr) {
        cout << res -> val << ' ';
        res = res -> next;
    }
}