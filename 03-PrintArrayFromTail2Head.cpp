class Solution {
   public:
    vector<int> printListFromTailToHead(ListNode *head) {
        std::stack<int> s;
        ListNode *cur = head;
        while (cur != NULL) {
            s.push(cur->val);
            cur = cur->next;
        }

        vector<int> v;
        while (!s.empty()) {
            v.push_back(s.top());
            s.pop();
        }
        return v;
    }
};

// 递归
class Solution {
   public:
    vector<int> printListFromTailToHead(struct ListNode *head) {
        vector<int> value;
        if (head != NULL) {
            value.insert(value.begin(), head->val);
            if (head->next != NULL) {
                vector<int> tempVec = printListFromTailToHead(head->next);
                if (tempVec.size() > 0)
                    value.insert(value.begin(), tempVec.begin(), tempVec.end());
            }
        }
        return value;
    }
};