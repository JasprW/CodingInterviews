struct TreeLinkNode {
    int val;
    struct TreeLinkNode *left;
    struct TreeLinkNode *right;
    struct TreeLinkNode *next;
    TreeLinkNode(int x) :val(x), left(NULL), right(NULL), next(NULL) {
        
    }
};

class Solution {
public:
    TreeLinkNode* GetNext(TreeLinkNode* pNode)
    {
        if(pNode -> right != nullptr) {
            return LeftMost(pNode);
        }
        else {
            if(pNode -> next != nullptr) {
                TreeLinkNode* par = pNode -> next;
                if(par -> left == pNode) {
                    return par;
                } else {
                    TreeLinkNode* gp = par -> next;
                    if(gp == nullptr) {
                        return nullptr;
                    } else {
                        if(gp -> left == par) {
                            return gp;
                        } else {
                            return nullptr;
                        }
                    }
                }
            }
        }
        return nullptr;
    }

    TreeLinkNode* LeftMost(TreeLinkNode* pNode) {
        if(pNode -> right == nullptr) {
            return nullptr;
        } else {
            TreeLinkNode* rs = pNode -> right;
            while(rs -> left) {
                rs = rs -> left;
            }
            return rs;
        }
    }
};