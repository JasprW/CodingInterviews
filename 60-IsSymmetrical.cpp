struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};

class Solution {
public:
    bool isSymmetrical(TreeNode* pRoot)
    {
        if(pRoot == nullptr || (pRoot -> left == nullptr && pRoot -> right == nullptr)) {
            return true;
        } else {
            return TreeCmp(pRoot -> left, pRoot -> right);
        }
    }

    bool TreeCmp(TreeNode* t1, TreeNode* t2) {
        if(t1 == nullptr && t2 == nullptr) {
            return true;
        } else if(t1 == nullptr || t2 == nullptr) {
            return false;
        } else {
            if(t1 -> val == t2 -> val) {
                return TreeCmp(t1 -> left, t2 -> right) && TreeCmp(t1->right, t2->left);
            } else {
                return false;
            }
        }
    }
};