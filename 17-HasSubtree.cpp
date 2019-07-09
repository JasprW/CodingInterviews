/**
 * 题目描述
 * 输入两棵二叉树A，B，判断B是不是A的子结构。（ps：我们约定空树不是任意一个树的子结构）
 */

struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
   public:
    bool HasSubtree(TreeNode* pRoot1, TreeNode* pRoot2) {
        if (!pRoot2 || !pRoot1) {
            return false;
        } else {
            bool result = false;
            // 数值相等时进一步判断
            if (pRoot1->val == pRoot2->val) {
                result = aux_hasSubtree(pRoot1, pRoot2);
            }
            // 根节点数值不一致时递归向左子树寻找节点数值相同的节点
            if (!result) {
                result = HasSubtree(pRoot1->left, pRoot2);
            }
            // 左子树也未寻找到时递归向右子树寻找
            if (!result) {
                result = HasSubtree(pRoot1->right, pRoot2);
            }
            return result;
        }
    }

    bool aux_hasSubtree(TreeNode* pRoot1, TreeNode* pRoot2) {
        // pRoot1到达叶节点但pRoot2未到达叶节点，为false
        if (!pRoot1 && pRoot2) {
            return false;
        }
        // pRoot2到达叶节点，无论pRoot1是否到达，均为true
        else if (!pRoot2) {
            return true;
        }
        // 都存在但数值不同，为false
        else if (pRoot1 && pRoot2 && pRoot1->val != pRoot2->val) {
            return false;
        }
        // 均存在且数值相同时，递归分别向各自左右子树判断
        else {
            return aux_hasSubtree(pRoot1->left, pRoot2->left) &&
                   aux_hasSubtree(pRoot1->right, pRoot2->right);
        }
    }
};