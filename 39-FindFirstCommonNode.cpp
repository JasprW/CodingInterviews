struct ListNode
{
    int val;
    struct ListNode *next;
    ListNode(int x) : val(x), next(nullptr)
    {
    }
};
class Solution
{
  public:
    ListNode *FindFirstCommonNode(ListNode *pHead1, ListNode *pHead2)
    {
        int len1 = length(pHead1), len2 = length(pHead2);
        ListNode *t1 = pHead1, *t2 = pHead2;
        if (len1 > len2)
        {
            for (int i = 0; i < (len1 - len2); i++)
            {
                t1 = t1->next;
            }
        }
        else if (len2 > len1)
        {
            for (int i = 0; i < (len2 - len1); i++)
            {
                t2 = t2->next;
            }
        }
        while (t1 != t2)
        {
            t1 = t1->next;
            t2 = t2->next;
        }
        return t1;
    }

    int length(ListNode *head)
    {
        int len = 0;
        ListNode *t = head;
        while (t)
        {
            len++;
            t = t->next;
        }
        return len;
    }
};