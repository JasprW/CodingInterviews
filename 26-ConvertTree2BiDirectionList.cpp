struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
   public:
    TreeNode* Convert(TreeNode* root) {
        if (!root) return nullptr;
        if (!root->left && !root->right) {
            return root;
        }
        TreeNode* left = Convert(root->left);
        TreeNode* p = left;
        while (p && p->right) {
            p = p->right;
        }
        if (p) {
            p->right = root;
            root->left = p;
        }
        TreeNode* right = Convert(root->right);
        if (right) {
            right->left = root;
            root->right = right;
        }
        return left ? left : root;
    }
};

// 非递归方法
class Solution {
   public:
    TreeNode* Convert(TreeNode* pRootOfTree) {
        if (pRootOfTree == nullptr) return nullptr;
        TreeNode* pre = nullptr;

        convertHelper(pRootOfTree, pre);

        TreeNode* res = pRootOfTree;
        while (res->left) res = res->left;
        return res;
    }

    void convertHelper(TreeNode* cur, TreeNode*& pre) {
        if (cur == nullptr) return;
        convertHelper(cur->left, pre);
        cur->left = pre;
        if (pre) pre->right = cur;
        pre = cur;
        convertHelper(cur->right, pre);
    }
};